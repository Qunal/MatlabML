%% Electricity Load Forecasting
% This example demonstrates building and validating a short term
% electricity load forecasting model with MATLAB. The models take into
% account multiple sources of information including temperatures and
% holidays in constructing a day-ahead load forecaster. The models compared
% include Neural Networks and Regression Trees.

%% Import Weather & Load Data
% The data set used is a table of historical hourly loads and temperature
% observations from the New England ISO for the years 2004 to 2008. The
% weather information includes the dry bulb temperature and the dew point.
% This data set is imported from an Access database using the
% auto-generated function _fetchDBLoadData_.

data = fetchDBLoadData('2004-01-01', '2008-12-31');

%% Import list of holidays
% A list of New England holidays that span the historical date range is
% imported from an Excel spreadsheet

[num, text] = xlsread('..\Data\Holidays.xls');
holidays = text(2:end,1);


%% Generate Predictor Matrix
% The function *genPredictors* generates the predictor variables used as
% inputs for the model. For short-term forecasting these include
% 
% * Dry bulb temperature
% * Dew point
% * Hour of day
% * Day of the week
% * A flag indicating if it is a holiday/weekend
% * Previous day's average load
% * Load from the same hour the previous day
% * Load from the same hour and same day from the previous week
%
% If the goal is medium-term or long-term load forecasting, only the inputs
% hour of day, day of week, time of year and holidays can be used
% deterministically. The weather/load information would need to be
% specified as an average or a distribution

% Select forecast horizon
term = 'short';

[X, dates, labels] = genPredictors(data, term, holidays);

%% Split the dataset to create a Training and Test set
% The dataset is divided into two sets, a _training_ set which includes 
% data from 2004 to 2007 and a _test_ set with data from 2008. The training
% set is used for building the model (estimating its parameters). The test
% set is used only for forecasting to test the performance of the model on 
% out-of-sample data. 

% Create training set
trainInd = data.NumDate < datenum('2008-01-01');
trainX = X(trainInd,:);
trainY = data.SYSLoad(trainInd);

% Create test set and save for later
testInd = data.NumDate >= datenum('2008-01-01');
testX = X(testInd,:);
testY = data.SYSLoad(testInd);
testDates = dates(testInd);

save Data\testSet testDates testX testY
clear X data trainInd testInd term holidays dates ans num text

%% Build the Load Forecasting Model
% Each of the following scripts trains and evaluates a different load
% forecasting model on the training data defined above. Trained models are
% saved to the Models directory

NNScript
    
% TBScript


%% Save Trained Model
% We can compact the model (to remove any stored training data) and save
% for later reuse

model = compact(model);
save Models\TreeModel model


%% Test Results
% Load in the model and test data and run the treeBagger forecaster and
% compare to actual load.

clear
load Models\TreeModel
load Data\testSet

%% Compute Prediction
% Predict the load for 2008 using the model trained on load data from 2007
% and before.
forecastLoad = predict(model, testX);

%% Compare Forecasted Load and Actual Load
% Create a plot to compare the actual load and the predicted load as well
% as the forecast error.

ax1 = subplot(2,1,1);
plot(testDates, [testY forecastLoad]);
ylabel('Load'); legend({'Actual', 'Forecast'}); legend('boxoff')
ax2 = subplot(2,1,2);
plot(testDates, testY-forecastLoad);
xlabel('Date'); ylabel('Error (MWh)');
linkaxes([ax1 ax2], 'x');
dynamicDateTicks([ax1 ax2], 'linked')

%% Compute Model Forecast Metrics
% In addition to the visualization we can quantify the performance of the
% forecaster using metrics such as mean average error (MAE), mean average
% percent error (MAPE) and daily peak forecast error.

err = testY-forecastLoad;
errpct = abs(err)./testY*100;

fL = reshape(forecastLoad, 24, length(forecastLoad)/24)';
tY = reshape(testY, 24, length(testY)/24)';
peakerrpct = abs(max(tY,[],2) - max(fL,[],2))./max(tY,[],2) * 100;

fprintf('Mean Average Percent Error (MAPE): %0.2f%% \nMean Average Error (MAE): %0.2f MWh\nDaily Peak MAPE: %0.2f%%\n',...
    mean(errpct(~isinf(errpct))), mean(abs(err)), mean(peakerrpct))