function y = loadForecast(date, hour, temperature, isWorkingDay, histDate, histHour, histLoad)
% LOADFORECAST performs a day-ahead load forecast using a pre-trained
% Neural-Network or Bagged Regression Tree model
%
% USAGE:
% y = loadForecast(model, date, hour, temperature, isWorkingDay, ...
%                  histDate, histHour, histLoad)

% Process Historical loads
date = datenum(date);
histDate = datenum(histDate);%+(histHour-1)/24;
prevWeek = histLoad(histDate == date(1) - 7);
prevDay  = histLoad(histDate == date(1) - 1);
ave24 = filter(ones(24,1)/24, 1, histLoad);
prev24 = ave24(histDate == date(1) - 1);

% Create predictor matrix
% Drybulb, Dewpnt, Hour, Day, isWkDay, PrevWeek, PrevDay, Prev24
X = [temperature hour weekday(date) isWorkingDay*ones(size(date)) prevWeek prevDay prev24];

% Load model and perform prediction
s = load('Models\NNModel_aus.mat');
y1 = sim(s.net, X')';

s = load('Models\TreeModel_aus.mat');
y2 = predict(s.model, X);

plot(hour, [y1 y2]/1e3); 
xlabel('Hour');
ylabel('Load (x1000 MW)');
title(sprintf('Load Forecast Profile for %s', datestr(date(1))))
grid on;
legend('NeuralNet','BaggedTree','Location','best');
print -dmeta

y = [y1 y2];

%#function TreeBagger
%#function CompactTreeBagger
%#function network
%#function network\sim