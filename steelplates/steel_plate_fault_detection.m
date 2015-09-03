%% Steel Plate Fault Detection
% Machine Learning Classification Example for mining / processing industry
% Goal is to build a model that can detect defects in steel plate
% manufacturing.
% 
% Concepts covered: Machine Learning techniques (Neural Networks, Naive
% Bayesian, Tree Bagger), Feature Selection, Parallel Computing.
%
% The output is also compiled as an Excel Addin to:
% "fault_detection.xlsm"
%
% Inputs:
%
% X_Minimum,% X_Maximum,% Y_Minimum,
% Y_Maximum
% Pixels_Areas
% X_Perimeter
% Y_Perimeter
% Sum_of_Luminosity
% Minimum_of_Luminosity
% Maximum_of_Luminosity
% Length_of_Conveyer
% TypeOfSteel_A300
% TypeOfSteel_A400
% Steel_Plate_Thickness
% Edges_Index
% Empty_Index
% Square_Index
% Outside_X_Index
% Edges_X_Index
% Edges_Y_Index
% Outside_Global_Index
% LogOfAreas
% Log_X_Index
% Log_Y_Index
% Orientation_Index
% Luminosity_Index
% SigmoidOfAreas
%
% Outputs: 7 Types of faults:
% Pastry
% Z_Scratch
% K_Scatch
% Stains
% Dirtiness
% Bumps
% Other_Faults
%
% David Willingham, MathWorks
% May 2014
% Dataset from https://archive.ics.uci.edu/ml/datasets/Steel+Plates+Faults

%% Import Data
importheaders
importdata

%% Pre process data into training and test sets
Faults = cell2mat(Faults);
datain = Faults(:,1:27);
dataout = Faults(:,28:end);
dataout2 = dataout.*repmat([1,2,3,4,5,6,7],length(Faults),1);
dataout2 = sum(dataout2,2);
rand('seed',6)
c = cvpartition(length(Faults),'holdout',0.15);
idxTrain = training(c);
idxTest = test(c);
Xtrain = datain(idxTrain,:);
Xtest = datain(idxTest,:);
Ytrain = dataout2(idxTrain,:);
Ytest = dataout2(idxTest,:);
Ytrain2 = dataout(idxTrain,:);
Ytest2 = dataout(idxTest,:);

%% Treebagger Classifier
model_TB = TreeBagger(100,Xtrain,Ytrain,'method','classification','oobvarimp','on');

Ypredict = str2double(predict(model_TB,Xtest));

perc_steel = sum(Ytest == Ypredict)/length(Ytest);
disp(['Correct Steel Fault Treebagger = ',num2str(100*perc_steel),'%']);

% Determine where the mis classification is
% Could be used for fine tuning the model later
C = confusionmat(Ytest,Ypredict,'order',[1:7]); 
C_perc = diag(sum(C,2))\C;
%% Neural Networks Classifier

model_net = patternnet(10);
model_net = train(model_net,Xtrain',Ytrain2');

u = unique(Ytest);
Y3 = model_net(Xtest')';
for i = 1:length(Y3)
    [~,m] = max(Y3(i,:));
    Ypredict2(i,:) = u(m);
end

perc_steel2 = sum(Ytest == Ypredict2)/length(Ytest);
disp(['Correct Steel Fault Neural Networks = ',num2str(100*perc_steel2),'%']);

%% NaiveBayes Classifier
model_bay = NaiveBayes.fit(Xtrain,Ytrain,'Distribution','kernel');

Ypredict3 = predict(model_bay,Xtest);

perc_steel3 = sum(Ytest == Ypredict3)/length(Ytest);
disp(['Correct Steel Fault Naive Bayesian = ',num2str(100*perc_steel3),'%']);

%% What var's are important? Feature Selection
opts = statset('display','iter', 'useparallel', 'always');
tic
fun = @(Xtrain,Ytrain,Xtest,Ytest)...
      sum(Ytest~=predict(NaiveBayes.fit(Xtrain,Ytrain,'Distribution','kernel'),Xtest));
[fs,history] = sequentialfs(fun,datain,dataout2,'cv',c,'options',opts);
toc;
%% Re-do the prediction using only significant variables
% Predict using Naive Bayes classifier
Ypredict4 = predict(NaiveBayes.fit(Xtrain(:,fs),Ytrain,'Distribution','kernel'),Xtest(:,fs));

perc_steel4 = sum(Ytest == Ypredict4)/length(Ytest);
disp(['Correct Steel Fault Naive Bayesian Reduced = ',num2str(100*perc_steel4),'%']);

%% Try again with Treebagger with feature selection
% Commented out as this takes time, even with parallel computing

% parpool %open parallel computing
% opts = statset('display','iter', 'useparallel', 'always');
% tic
% 
% [fs,history] = sequentialfs(@funtree,datain,dataout2,'cv',c,'options',opts);
% 
% toc;
% save fs fs
load fs

%% Re-do the prediction using only significant variables
% Predict using TreeBagger classifier
model_TB2 = TreeBagger(100,Xtrain(:,fs),Ytrain,'method','classification','oobvarimp','on');

Ypredict5 = str2double(predict(model_TB2,Xtest(:,fs)));

perc_steel = sum(Ytest == Ypredict5)/length(Ytest);
disp(['Correct Steel Fault Treebagger Reduced = ',num2str(100*perc_steel),'%']);

% display results as a confusion matrix to determine accuracy and where the
% miss classification is
C = confusionmat(Ytest,Ypredict5,'order',[1:7]); 
C_perc = diag(sum(C,2))\C;
