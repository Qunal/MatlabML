%%  Dat Mining App
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
summary(FixT);
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
% Needs one Table of X and Y but no cells
% Ifwe drop Classe variable and do table2array it converts all to double.
% ELse messes up with many cells
%Then we add Claase back
M.X=array2table(Xtrain,'VariableNames',{vars{1:52}});% Double braces to convert comma list to cell
M.Y=cell2table(Ytrain,'VariableNames',{'classe'});
N=height(M.X);
for i=1:N
    Rnames{i}=['r',num2str(i)];% Creat a cell array of strings
end
M.X.Properties.RowNames=Rnames;
M.Y.Properties.RowNames=Rnames;

MiningT=join(M.X,M.Y,'Keys','RowNames');% merge tables by row
summary(MiningT)

%%
% variables have been created in the base workspace.
% To use the exported classifier 'trainedClassifier' to make predictions on new data, T, use 
%   yfit = predict(trainedClassifier, T{:,trainedClassifier.PredictorNames})
% 
% If your new data contains any integer variables, then preprocess the data to doubles like this:
%   X = table2array(varfun(@double, T(:,trainedClassifier.PredictorNames)));
%   yfit = predict(trainedClassifier, X)
%load('Mining.mat') %Trained classifier
tic;
[ens, validationAccuracy]=trainClassifier(MiningT)
toc;
yfit = predict(ens, Xtest);% 397 seconds 10 fold, accuracy is 99.55%

%%
C = confusionmat(Ytest,yfit);% Wors if Ytest is atble not cell
%disp(array2table(C,'VariableNames',rfmodel.ClassNames,'RowNames',rfmodel.ClassNames))
fprintf('Prediction accuracy on test set: %f\n\n', sum(C(logical(eye(5))))/sum(sum(C)))%%99.28%

%% Kfoldloss
figure;
plot(kfoldLoss(ens,'mode','individual'));
xlabel('Number of folds');
ylabel('Test classification error');%Funny between 50-52 and stable aftern that
%%
figure
plot( oobLoss(ens,'mode','cumulative'));
xlabel('Number of Grown Trees');
ylabel('Out-of-Bag Classification Error'); % 50th treeis near optimum

%% Treeplot
tree=ens.Trained{45};
% Text explanation of tree
view(tree)%% VEry cool
%View  Not able to prune interactively as prunng sequence not filled in
view(tree,'Mode','graph')
% prune for viewing
%  pruneTree=prune(tree)% suppsed to fill pruving sequence 
% view(pruneTree,'Mode','graph','Level',4)% supposed to prune 



%% Graph by number of leaf nodes
% Generate minimum leaf occupancies for classification trees from 10 to 100, spaced exponentially apart:
% 
leafs = logspace(0,2,10);
% Create cross validated classification trees for the  data with minimum leaf occupancies from leafs:

rng('default')
N = numel(leafs);
err = zeros(N,1);
for n=1:N
    t = fitctree(Xtrain,Ytrain,'CrossVal','On',...
        'MinLeafSize',leafs(n));
    err(n) = kfoldLoss(t);
end
plot(leafs,err);
xlabel('Min Leaf Size');
ylabel('cross-validated error');


%% OOB loss etc per number of trees
 %Try to get  ensemble cv model
 tic;
cvens= crossval(ens, 'KFold', 10);% 349.66 seconds
toc
% plot loss by number of elearners 
tic;
figure;
plot(loss(ens,Xtest,Ytest,'mode','cumulative'));% on bag ensemble not on CV lossed
hold on;
plot(kfoldLoss(cvens,'mode','cumulative'),'r.') % on cvpartioned model
plot(oobLoss(ens,'mode','cumulative'),'k--');% Bag ensembles have OOB loss not cv partioned
hold off;
xlabel('Number of trees');
ylabel('Classification error');
legend('Test','Cross-validation','Out of bag','Location','NE');
toc % 19.15 sec

%% Prune
% Try to get  ensemble cv model
% partitionedModel = crossval(cvens, 'KFold', 10);
% % Find optimum level to prune
[~,~,~,bestlevel] = cvloss(cvens,...
    'SubTrees','All','TreeSize','min')

% 
% % prune
% Mdl7 = fitctree(X,Y,'MaxNumSplits',7,'CrossVal','on');
% view(Mdl7.Trained{1},'Mode','graph')
% 


