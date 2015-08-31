%% Import data from text file.
% X numeric matrix
% Y numeric vector
% save lasso.mat X Y% Command format
load lasso.mat
Xnames={'Cement','BlastFurnaceSlag','FlyAsh','Water','Superplasticizer','CoarseAggregate','FineAggregate','Age'};
Ynames={'CompressiveStrength'};
% Import X as numeric
%Import y as numeric, had a NAN row
%% Lasso
cv = cvpartition(Y,'HoldOut',0.3);
Xtrain=X(training(cv),:);
Ytrain=Y(training(cv),:);
Xtest=X(test(cv),:);
Ytest=X(test(cv),:);
%
tic
[b fitinfo]=lasso(X,Y);
toc
lassoPlot(b, fitinfo,'PlotType','Lambda','XScale','log','PredictorNames',{'Cement','BlastFurnaceSlag','FlyAsh','Water','Superplasticizer','CoarseAggregate','FineAggregate','Age'})