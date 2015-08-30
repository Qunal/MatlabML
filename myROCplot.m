
function myROCplot(Xtrain,Ytrain,Xtest,Ytest,posClass,nFeatures,varimp)
%myROCplot produces ROC curves with different number of predictors
%   |nFeatures| is a vector that specifies the number of predictors to use
%   for each ROC curve. Predictors are selected based on the order of
%   variable importance measure |varimp|, from the highest to lowest.
%   |posClass| specifies which label to use as the positive label for ROC
%   curves. |Xtrain| is training set of predictors, |Ytrain| is their
%   matching labels. |Xtest| is test set of predictors, |Ytest| is their
%   matching labels.

% sort variable importance scores in a descending order
[~,idxvarimp]= sort(varimp,'descend');

% get the index of the positive class
posIdx = find(strcmp(posClass,categories(Ytrain)));

% initialize some accumulators
colors = lines(length(nFeatures)+1);
curves = zeros(1,length(nFeatures)+1);
labels = cell(length(nFeatures)+1,1);

% enable parallel option
opts = statset('UseParallel',true);

% use 50 trees and fewer options to make it go faster
model = TreeBagger(50,table2array(Xtrain(:,sort(idxvarimp(1:nFeatures(1))))),...
        Ytrain,'Method','classification','options',opts);
% non parallel version
% model = TreeBagger(50,table2array(Xtrain(:,sort(idxvarimp(1:featSize(1))))),...
%     Ytrain,'Method','classification');

% get the classification scores
[~,Yscore] = predict(model,table2array(Xtest(:,sort(idxvarimp(1:nFeatures(1))))));
% compute and plot the ROC curve and AUC score
[rocX,rocY,~,auc] = perfcurve(Ytest,Yscore(:,posIdx),posClass);

% plot the ROC curves
figure
curves(1) = plot(rocX,rocY,'Color',colors(1,:));
% get the labels for legend
labels{1} = sprintf('Features:%02d, AUC: %.4f',nFeatures(1),auc); 
hold on

for i = 2:length(nFeatures)
    model = TreeBagger(50,table2array(Xtrain(:,sort(idxvarimp(1:nFeatures(i))))),...
        Ytrain,'Method','classification','options',opts);
    % non parallel version
%     model = TreeBagger(50,table2array(Xtrain(:,sort(idxvarimp(1:featSize(i))))),...
%         Ytrain,'Method','classification');
    [~,Yscore] = predict(model,table2array(Xtest(:,sort(idxvarimp(1:nFeatures(i))))));
    [rocX,rocY,~,auc] = perfcurve(Ytest,Yscore(:,posIdx),posClass);
    curves(i) = plot(rocX,rocY,'Color',colors(i,:));
    labels{i} = sprintf('Features:%02d, AUC: %.4f',nFeatures(i),auc); 
end
curves(end) = refline(1,0); set(curves(end),'LineStyle',':');
labels{end} = 'Line for random predictions';

hold off
xlabel('False posiitve rate');
ylabel('True positive rate')
title(sprintf('ROC curve for Class ''%s'', predicted vs. actual',posClass))
legend(curves,labels,'Location','SouthEast');

end





