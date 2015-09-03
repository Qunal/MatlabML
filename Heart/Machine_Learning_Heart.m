%% Machine Learning
% Predicting the presence of Heart Disease base on input data:
%
%       -- 1. age       
%       -- 2. sex       
%       -- 3. chest pain type  (4 values)       
%       -- 4. resting blood pressure  
%       -- 5. serum cholestoral in mg/dl      
%       -- 6. fasting blood sugar > 120 mg/dl       
%       -- 7. resting electrocardiographic results  (values 0,1,2) 
%       -- 8. maximum heart rate achieved  
%       -- 9. exercise induced angina    
%       -- 10. oldpeak = ST depression induced by exercise relative to rest   
%       -- 11. the slope of the peak exercise ST segment     
%       -- 12. number of major vessels (0-3) colored by flourosopy        
%       -- 13.  thal: 3 = normal; 6 = fixed defect; 7 = reversable defect     
%
% http://archive.ics.uci.edu/ml/datasets/Statlog+%28Heart%29

%% Import our data
importheart %import data
X = heart(:,1:13); 
Y = heart(:,14);
VarNames = {'age','sex','chest','bp','chol','bldsug','resting','hr','exc','old','slope','vess','thal'};
%% Covariance Matrix
% How correlated are each of the data columns?

covmat = corrcoef(double(heart));

figure
x = size(heart, 2);
imagesc(covmat);
set(gca,'clim',[-1,1])
set(gca,'XTick',1:x);
set(gca,'YTick',1:x);
set(gca,'XTickLabel',shortlabels(VarNames));
set(gca,'YTickLabel',VarNames);
axis([0 x+1 0 x+1]);
grid;
colorbar;

%%  Use sequential feature selection to identify significant variables
% Create a cvpartition object (kfold or holdout)

% rand('seed',6)

c2 = cvpartition(Y, 'holdout');
Xtrain = X(training(c2, 1),:);
Xtest = X(test(c2, 1),:);
Ytrain = Y(training(c2,1));
Ytest = Y(test(c2,1));


%% NaiveBayes

baymodel = NaiveBayes.fit(Xtrain,Ytrain,'Distribution','kernel');

% Predict using Naive Bayes classifier
Ypredict = predict(baymodel,Xtest);
percb = 100*(1-(sum(Ytest~=Ypredict)/length(Ytest)));
disp(percb);

figure
pie([percb,100-percb],{['Correct - ',num2str(percb),'%'],['Incorrect - ',num2str(100-percb),'%']})
title('Heart Disease Model Accuracy - NaiveBayes')

%% Opening up a MATLAB pool to run feature selection in parallel
% matlabpool open 2
opts = statset('display','iter', 'useparallel', 'always');
% opts = statset('display','iter');
tic

fun = @(Xtrain,Ytrain,Xtest,Ytest)...
      sum(Ytest~=predict(NaiveBayes.fit(Xtrain,Ytrain,'Distribution','kernel'),Xtest));
  
[fs,history] = sequentialfs(fun,X,Y,'cv',c2,'options',opts);

toc;


%% Re-do the prediction using only significant variables
% Predict using Naive Bayes classifier
Ypredict = predict(NaiveBayes.fit(Xtrain(:,fs),Ytrain,'Distribution','kernel'),Xtest(:,fs));

percb2 = 100*(1-(sum(Ytest~=Ypredict)/length(Ytest)));
disp(percb2);

pie([percb2,100-percb2],{['Correct - ',num2str(percb2),'%'],['Incorrect - ',num2str(100-percb2),'%']})
title('Heart Disease Model Accuracy - NaiveBayes Segmented')


%% Treebagger - Regression Tree

model = TreeBagger(20,Xtrain,Ytrain,'Method','Classification');
view(model.Trees{1},'mode','graph')
Ypredict2 = str2double((predict(model,Xtest)));

perct = 100*(1-(sum(Ytest~=Ypredict2)/length(Ytest)));
disp(perct);
figure
pie([perct,100-perct],{['Correct - ',num2str(perct),'%'],['Incorrect - ',num2str(100-perct),'%']})
title('Heart Disease Model Accuracy - TreeBagger')
 
%% Neural Networks

u = unique(Y);
Ytrain2 = zeros(length(Ytrain),length(u));
for i = 1:length(u)
    a = Ytrain == u(i);
    Ytrain2(:,i) = double(a);
end

% nprtool %show interactive tool for neural networks
net = patternnet(10);
net = train(net,Xtrain',Ytrain2');


Y3 = net(Xtest')';
for i = 1:length(Y3)
    [~,m] = max(Y3(i,:));
    Ypredict3(i,:) = u(m);
end

percnn = 100*(1-(sum(Ytest~=Ypredict3)/length(Ytest)));
disp(percnn);
figure
pie([percnn,100-percnn],{['Correct - ',num2str(percnn),'%'],['Incorrect - ',num2str(100-percnn),'%']})
title('Heart Disease Model Accuracy - TreeBagger')

%% Comparison
figure
bar([percb,percb2,perct,perct])
ylim([50,100])

