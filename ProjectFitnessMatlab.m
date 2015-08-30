%%

T = readtable('pml-training.csv','TreatAsEmpty','NA'); 
% separate the classification label from the predictor variables
class = categorical(T.classe); 
%T.classe = [];
id = {'NA' NaN ''};
missingVals = sum(ismissing(T,id));
% dropping vars with missing values 
FixT = T(:,missingVals == 0); 
% remove user name, time stamps, etc.
FixT(:,1:7)=[];
% Set the random number seed to make the results repeatable
rng('default');

% Partition the dataset to a 80:20 split
cv = cvpartition(height(FixT),'holdout',0.20);
% Training set
Xtrain = FixT(training(cv),:);
% Get the names of variables 
vars = Xtrain.Properties.VariableNames;
Xtrain(:,53)=[]; % Drop catagory variable
Ytrain = FixT(training(cv),53);
%%
%MATLAB needs matric or array can not use table in stats
Xtrain=table2array(Xtrain);
Ytrain=table2array(Ytrain);

% fprintf('\nTraining Set\n')
% tabulate(Ytrain)

% Test set
Xtest = FixT(test(cv),:);
Xtest(:,53)=[]; % Drop catagory variable
Ytest = FixT(test(cv),53);
% fprintf('\nTest Set\n')
% tabulate(Ytest)
%MATLAB needs matric or array can not use table in stats
Xtest=table2array(Xtest);
Ytest=table2array(Ytest);

%% EDA
% Scatter plot some variables

Importvar= {'roll_belt' 'pitch_forearm' 'yaw_belt' 'magnet_dumbbell_z'}
colr=['c' 'b' 'm' 'g' 'r']
symp={'o','x','+','-','*'}
PlotX=FixT(:,Importvar);
summary(PlotX);% dobles 
PlotX_Stru=table2struct(PlotX);
PlotX_Stru
PlotX_Stru.roll_belt
PlotX_Cell=table2cell(PlotX);
PlotX_Arr=table2array(PlotX);
figure;
% cross plot 4 variables colour by classe 
% gplotmatrix(PlotX_Cell,PlotX_Cell,FixT.classe,[],[],[],[],'variable',Importvar,Importvar);
% gplotmatrix(PlotX_Cell,PlotX_Cell,FixT.classe,[],[],[],[],'variable',Importvar,Importvar);
% gplotmatrix(PlotX_Stru,PlotX_Stru,FixT.classe,[],[],[],[],'variable');

gplotmatrix(PlotX_Arr,PlotX_Arr,FixT.classe,colr,[],[],[],[],Importvar,Importvar);
%gscatter(PlotX_Arr,PlotX_Arr,FixT.classe,colr,[],[],[],Importvar,Importvar);

%% Stats
% Create a Random Forest model with 100 trees, check parallel enabled...
tic;
rfmodel = TreeBagger(100,Xtrain,Ytrain,...
    'Method','classification','oobvarimp','on');
toc %83.6sec
rfmodel
rfmodel.ClassNames

%% Plot misclassification errors by number of trees
% I happened to pick 100 trees in the model, but you can check the
% misclassification errors relative to the number of trees used in the
% prediction. The plot shows that 100 is an overkill - we could use fewer 
% trees and that will make it go faster. 

figure
plot(oobError(rfmodel));% oobError for Treebagger and oobLoss for Fitensemble
xlabel('Number of Grown Trees');
ylabel('Out-of-Bag Classification Error');

%% Variable Importance
% One major criticism of Random Forest is that it is a black box algorithm
% and it not easy to understand what it is doing. However, Random Forest
% can provide the variable importance measure, which corresponds to the
% change in prediction error with and without the presence of a given
% variable in the model.
%
% For our hypothetical weight lifting trainer mobile app, Random Forest
% would be too cumbersome and slow to implement, so you want to use a
% simpler prediction model with fewer predictor variables. Random Forest
% can help you with selecting which predictors you can drop without
% sacrificing the prediction accuracy too much. 
%
% Let's see how you can do this with |TreeBagger|. 

%%

%%
% Get and sort the variable importance scores.
% Because we turned |'oobvarimp'| to |'on'|, the model contains 
% |OOBPermutedVarDeltaError| which acts as the variable importance measure.
varimp = rfmodel.OOBPermutedVarDeltaError';
[~,idxvarimp]= sort(varimp);
labels = vars(idxvarimp);
%%
% Plot the sorted scores.
figure
barh(varimp(idxvarimp),1); ylim([40 52]);% Top 12 variables
set(gca, 'YTickLabel',labels, 'YTick',1:numel(labels))
title('Variable Importance'); xlabel('score')

%% Evaluate trade-off with ROC plot
% Now let's do the trade-off between the number of predictor variables and
% prediction accuracy. The
% <http://en.wikipedia.org/wiki/Receiver_operating_characteristic Receiver
% operating characteristic (ROC)> plot provides a convenient way to
% visualize and compare performance of binary classifiers. You plot the
% false positive rate against the true positive rate at various prediction
% thresholds to produce the curves. If you get a completely random result,
% the curve should follow a diagonal line. If you get a 100% accuracy, then
% the curve should hug the upper left corner. This means you can use the
% area under the curve (AUC) to evaluate how well each model performs.
%
% Let's plot ROC curves with different sets of predictor variables, using
% the "C" class as the positive class, since we can only do this one class
% at a time, and the previous confusion matrix shows more misclassification
% errors for this class than others. You can use
% <http://www.mathworks.com/help/stats/perfcurve.html |perfcurve|> to
% compute ROC curves.
%
% Check out <http://blogs.mathworks.com/images/loren/2014/myROCplot.m
% |myROCplot.m|> to see the details.

nFeatures = [3,5,10,15,20,25,52];
myROCplot(Xtrain,Ytrain,Xtest,Ytest,'C',nFeatures,varimp)

%%
% Predict the class labels for the test set.
tic;
[Ypred,Yscore]= predict(rfmodel,Xtest);
toc % 0.94 sec
%%
% Compute the confusion matrix and prediction accuracy.
C = confusionmat(Ytest,categorical(Ypred));% Wors if Ytest is atble not cell
disp(array2table(C,'VariableNames',rfmodel.ClassNames,'RowNames',rfmodel.ClassNames))
fprintf('Prediction accuracy on test set: %f\n\n', sum(C(logical(eye(5))))/sum(sum(C)))%%99.28%


%% The reduced model with 12 features
% Based on the previous analysis, it looks like you can achieve a high
% accuracy rate even if you use as few as 10 features. Let's say we settled
% for 12 features. We now know you don't have to use the data from the
% glove for prediction, so that's one less sensor our hypothetical end
% users would have to buy. Given this result, I may even consider dropping
% the arm band, and just stick with the belt and dumbbell sensors.
%%
% Show which features were included.
disp(table(varimp(idxvarimp(1:12)),'RowNames',vars(idxvarimp(1:12)),...
    'VariableNames',{'Importance'}));
%%
