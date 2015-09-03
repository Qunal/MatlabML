%% Decision Boundary
clear;
load fisheriris;
X = meas(:,1:2);
y = categorical(species);
labels = categories(y);

figure(1)
gscatter(X(:,1), X(:,2), species,'rgb','osd');
xlabel('Sepal length');
ylabel('Sepal width');
% $ classifiers
tic
classifier{1} = NaiveBayes.fit(X,y);
toc % 0.75
classifier{2} = ClassificationDiscriminant.fit(X,y);
toc % 1.39
classifier{3} = ClassificationTree.fit(X,y);
toc % 0.422
classifier{4} = ClassificationKNN.fit(X,y);
toc %0.17
classifier_name = {'Naive Bayes','Discriminant Analysis','Classification Tree','Nearest Neighbor'};
% plot
[xx1, xx2] = meshgrid(4:.01:8,2:.01:4.5);
tic
figure(2)
for ii = 1:numel(classifier)
   ypred = predict(classifier{ii},[xx1(:) xx2(:)]);

   h(ii) = subplot(2,2,ii);
   gscatter(xx1(:), xx2(:), ypred,'rgb');

   title(classifier_name{ii},'FontSize',15)
   legend off, axis tight
end

legend(h(1), labels,'Location',[0.35,0.01,0.35,0.05],'Orientation','Horizontal')
toc % 3.49 