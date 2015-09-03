%% Machine Learning for Mining - XLS version
% Machine Learning Regression Example for mining industry.
%
% This example use regression techniques for predicting the impurities  
% output of Silica (Si02) and Magnesia(MgO) levels from a iron ore 
% processing plant
%
% Concepts covered: Pre processing data, Machine Learning techniques 
% (Multiple Linear Regression, Tree Bagger, Neural Networks), Feature Selection, Parallel Computing.
%
% Original data & example in "concentrator_data.xls" & proc_conc.m
% but changed to txt file version for speed. 
%
% Output data is:
% conc_out = imp_conc_out('concentrator_data.xlsx','Chemistry Data May-02 to May-03',2,8400);
% Input data is:
% conc_chem = imp_chem_in('concentrator_data.xlsx','Chemistry Data May-02 to May-03',2,8400);
% conc_in = imp_conc_in('concentrator_data.xlsx','Process Data Values',8,9510);
%
% Abhaya Parthy & David Willingham
% MathWorks Australia, 2014
%% seed the random number generator
rng('default')

%% load target data
conc_out = imp_conc_out('concentrator_data.xlsx','Chemistry Data May-02 to May-03',2,8400);

%% set all samples to be hourly
% int32 function rounds before conversion
conc_out.Time = int32(conc_out.Time*24);

%% find unique time samples
[untime,idx] = unique(conc_out.Time);

%% take mean of unique time samples
siav = zeros(length(idx),1);
mgav = zeros(length(idx),1);
endidx = [idx(2:end)-1; length(conc_out.si)];
for ii = 1:length(idx);
    siav(ii) = nanmean(conc_out.si(idx(ii):endidx(ii)));
    mgav(ii) = nanmean(conc_out.mg(idx(ii):endidx(ii)));
end

%% create target dataset
conc_tar = table(untime,siav,mgav,'VariableNames',{'Time','si','mg'});

%% create chemistry input data set
conc_chem = imp_chem_in('concentrator_data.xlsx','Chemistry Data May-02 to May-03',2,8400);

%% set all samples to be hourly
% int32 function rounds before conversion
conc_chem.Time = int32(conc_chem.Time*24);

%% find unique time samples
[untime,idx] = unique(conc_chem.Time);

%% take mean of unique time samples
siav = zeros(length(idx),1);
mgav = zeros(length(idx),1);
endidx = [idx(2:end)-1; length(conc_chem.si_in)];
for ii = 1:length(idx)
    siav(ii) = nanmean(conc_chem.si_in(idx(ii):endidx(ii)));
    mgav(ii) = nanmean(conc_chem.mg_in(idx(ii):endidx(ii)));
end

%% create chemistry input dataset
conc_chem = table(untime,siav,mgav,'VariableNames',{'Time','si_in','mg_in'});

%% process input data
% removed two rows from original dataset due to bad data
conc_in = imp_conc_in('concentrator_data.xlsx','Process Data Values',8,9510);
conc_in.Time = int32(conc_in.Time * 24);

%% join input and chem data using time key
condata_chem = outerjoin(conc_in,conc_chem,'MergeKeys',true);

%% join input and target data using time key
condata = outerjoin(condata_chem,conc_tar,'MergeKeys',true);

%% convert joined dataset back to matrix
conmat = table2array(condata(:,2:end));
samples = table2array(condata(:,1));
samples = double(samples);

%% interpolate each column to fill in missing values

% interpolated
conmatint = zeros(size(conmat));

for ii = 1:size(conmat,2)
    % find valid values
    idx = ~isnan(conmat(:,ii));
    v = conmat(idx,ii); % values
    x = samples(idx); % samples
    
    conmatint(:,ii) = interp1(x,v,samples,'spline');
    
%     figure;
%     plot([conmat(:,ii),conmatint(:,ii)]);
end

%% create input and output data matrices
X = conmatint(:,1:end-2);
Y = conmatint(:,end-1:end);

%% create training set and test set
% Test with 15% of the Data
% cvpartition helps us create a cross-validation partition for data. We
% create a test set (15% of data) and training set (85% of data).

c = cvpartition(length(samples),'holdout',0.15);

idxTrain = training(c);
idxTest = test(c);

Xtrain = X(idxTrain,:);
Xtest = X(idxTest,:);
Ytrain = Y(idxTrain,:);
Ytest = Y(idxTest,:);

%% Multiple Linear Regression
modelLR_si = LinearModel.fit(Xtrain,Ytrain(:,1));
modelLR_mg = LinearModel.fit(Xtrain,Ytrain(:,2));
%disp(modelLR_si)
yfitLR_si = predict(modelLR_si,Xtest);
yfitLR_mg = predict(modelLR_mg,Xtest);

plotFitErrors(Ytest(:,1),yfitLR_si)
plotFitErrors(Ytest(:,2),yfitLR_mg)

R2_si = Rsquared(Ytest(:,1),yfitLR_si);
disp(['R-sq LinReg (SiO2) = ',num2str(R2_si)])

R2_mg = Rsquared(Ytest(:,2),yfitLR_mg);
disp(['R-sq LinReg (MgO) = ',num2str(R2_mg)])

%% Bagged Regression Tree Model
modelTB_si = TreeBagger(100,Xtrain,Ytrain(:,1),'method','regression','oobvarimp','on');
modelTB_mg = TreeBagger(100,Xtrain,Ytrain(:,2),'method','regression','oobvarimp','on');
%disp(modelLR_si)
[yfitTB_si,~] = predict(modelTB_si,Xtest);
[yfitTB_mg,~] = predict(modelTB_mg,Xtest);

plotFitErrors(Ytest(:,1),yfitTB_si)
plotFitErrors(Ytest(:,2),yfitTB_mg)

R2_si = Rsquared(Ytest(:,1),yfitTB_si);
disp(['R-sq DTree (SiO2) = ',num2str(R2_si)])

R2_mg = Rsquared(Ytest(:,2),yfitTB_mg);
disp(['R-sq DTree (MgO) = ',num2str(R2_mg)])

%% plot parameter importance
figure;
barh(modelTB_si.OOBPermutedVarDeltaError);
title('SI');

figure;
barh(modelTB_mg.OOBPermutedVarDeltaError);
title('MG')

%% Neural Network

% Create a Fitting Network
hiddenLayerSize = 20;
net_si = fitnet(hiddenLayerSize);
net_mg = fitnet(hiddenLayerSize);

% Set up Division of Data for Training, Validation, Testing
% net.divideParam.trainRatio = 70/100;
% net.divideParam.valRatio = 15/100;
% net.divideParam.testRatio = 15/100;
 
% Train the Network
[net_si,~] = train(net_si,Xtrain.',Ytrain(:,1).');
[net_mg,~] = train(net_mg,Xtrain.',Ytrain(:,2).');
 
% Test the Network
yfitNN_si = net_si(Xtest.').';
yfitNN_mg = net_mg(Xtest.').';
 
%% R_2

plotFitErrors(Ytest(:,1),yfitNN_si)
plotFitErrors(Ytest(:,2),yfitNN_mg)

R2_si = Rsquared(Ytest(:,1),yfitNN_si);
disp(['R-sq NNet (SiO2) = ', num2str(R2_si)])

R2_mg = Rsquared(Ytest(:,2),yfitNN_mg);
disp(['R-sq NNet (MgO) = ', num2str(R2_mg)])
 
