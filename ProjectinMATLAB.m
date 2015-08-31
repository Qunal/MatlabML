%% Get Data
% Practical ML Project
load('matlab')
% Prune NA columns
%id = {'NA' '' -99 NaN Inf};
id = {'NA' NaN ''};
%FixedTesting=pmltesting(:, sum( ismissing( pmltesting,id ) )==0);
FixedTraining=pmltraining(:, sum( ismissing( pmltraining,id ) )==0);
%in R thre are 87 columns in MATLAB only 33???
A.Orignames=pmltraining.Properties.VariableNames % 160 columns
A.Fixednames=FixedTraining.Properties.VariableNames% only 60 columns
%Dropped Columnes
A.Diffnames=setdiff(A.Orignames, A.Fixednames)
%prune bookkeeping variable
FixedTesting(:,[1:7,13:20]) = [];
FixedTraining(:,[1:7,13:20])=[];
save matlab1.mat FixedTesting FixedTraining;

%%  Web Project
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
summary(FixT)
% Partition the dataset to a 80:20 split
cv = cvpartition(height(FixT),'holdout',0.20);
% Training set
Xtrain = FixT(training(cv),:);
% Get the names of variables 
vars = Xtrain.Properties.VariableNames;
Xtrain(:,53)=[]; % Drop catagory variable
Ytrain = FixT(training(cv),53);
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
%
tic;
B = TreeBagger(nTrees,Xtest,Ytest, 'Method', 'classification');
toc
tree1=B.Trees{27};
view(tree1,'Mode','graph')% Explore pruning
tree2=prune(tree1,'Level', 2)
view(tree1,'Mode','graph')


%%  Start
load('matlab1')
summary(FixedTraining)
FixC=table2cell(FixedTraining);
FixA=table2array(FixedTraining);
%clearvars pmltesting pmltraining;
nTrees=101;
Xnames=FixedTraining.Properties.VariableNames;
X=table2array(FixedTraining(:,(7:50)));
Y=table2array(FixedTraining(:,51));
clear
tic;
B = TreeBagger(nTrees,X,Y, 'Method', 'classification');
toc
% view(B.Trees{27},'Mode','graph')% Explore pruning
% tree1=prune(B.Trees(27),'Level', 2)
% view(tree1,'Mode','graph')

 %% ENsmeble
 
Pnames={Xnames{1:52}}
 tic;
 ens = fitensemble(Xtrain,Ytrain,'AdaBoostM2',101,'Tree','CrossVal','On','PredictorNames',Pnames);
 toc; % 98.05 seconds
figure;
plot(kfoldLoss(ens,'mode','individual'));
xlabel('Number of folds');
ylabel('Test classification error');%Funny between 50-52 and stable aftern that
%
kfoldLoss(ens,'mode','average')% 0.5734

%CHeck cvloss also

 

%% Independant
%Create a bagged classification ensemble of 200 trees from the training data:

cvpart = cvpartition(Y,'holdout',0.3);
Xtrain = X(training(cvpart),:);
Ytrain = Y(training(cvpart),:);
Xtest = X(test(cvpart),:);
Ytest = Y(test(cvpart),:);



tic;

bag = fitensemble(Xtrain,Ytrain,'Bag',200,'Tree',...
    'Type','Classification')
toc;



% Plot the loss (misclassification) of the test data as a function of the number of trained trees in the ensemble:

figure;
plot(loss(bag,Xtest,Ytest,'mode','cumulative'));
xlabel('Number of trees');
ylabel('Test classification error');

 
 
 %% CV
 tic;
 cv = fitensemble(X,Y,'Bag',200,'Tree',...
    'type','classification','kfold',3)
toc
% Examine the cross-validation loss as a function of the number of trees in the ensemble:
figure;
plot(loss(bag,Xtest,Ytest,'mode','cumulative'));
hold on;
plot(kfoldLoss(cv,'mode','cumulative'),'r.');
hold off;
xlabel('Number of trees');
ylabel('Classification error');
legend('Test','Cross-validation','Location','NE');

% predictor importance
[imp2,ma] = predictorImportance(bag)
% Sort imp2



%Generate the loss curve for out-of-bag estimates, and plot it along with the other curves:



figure;
plot(loss(bag,Xtest,Ytest,'mode','cumulative'));
hold on;
plot(kfoldLoss(cv,'mode','cumulative'),'r.');
plot(oobLoss(bag,'mode','cumulative'),'k--');
hold off;
xlabel('Number of trees');
ylabel('Classification error');
legend('Test','Cross-validation','Out of bag','Location','NE');





%% Deep Trees
% Use deep trees for higher ensemble accuracy. To do so, set the trees to have minimal leaf size of 5. Set LearnRate to 0.1 in order to achieve higher accuracy as well. The data is large, and, with deep trees, creating the ensemble is time consuming.



t = templateTree('MinLeafSize',5);
tic
rusTree = fitensemble(X,Y,'RUSBoost',1000,t,...
    'LearnRate',0.1,'nprint',100);
toc % 1115.36 Sec

% Plot the classification error against the number of members in the ensemble.



figure;
tic
plot(loss(rusTree,Xtest,Ytest,'mode','cumulative'));
toc
grid on;
xlabel('Number of trees');
ylabel('Test classification error');

%Examine the confusion matrix for each class as a percentage of the true class.



tic
Yfit = predict(rusTree,Xtest);
toc
tab = tabulate(Ytest);
bsxfun(@rdivide,confusionmat(Ytest,Yfit),tab(:,2))*100 %Y is a char class needs to be numeric



