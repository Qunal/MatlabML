% initialize the environment
clearvars;close all; clc;

% load the dataset
% T = readtable('WearableComputing_weight_lifting_exercises_biceps_curl_variations.csv','TreatAsEmpty','NA');
T = readtable('pml-training.csv','TreatAsEmpty','NA'); % use a subset instead to speed things up

% separate the classification label from the predictor variables
class = categorical(T.classe); T.classe = [];
% fprintf('Num samples in data   : %d\n',height(T))
% fprintf('Num predictors in data: %d\n\n',width(T))
missingVals = sum(ismissing(T));
% dropping vars with missing values 
T = T(:,missingVals == 0); 

%% Partition the dataset for cross validation
% One of the key techniques you use in predictive modeling or machine
% learning is 
% <http://en.wikipedia.org/wiki/Cross-validation_%28statistics%29 cross 
% validation>. Roughly speaking, you hold out part of
% available data for testing later, and build models using the remaining 
% dataset. The held out set is called 'test set' and the set we will use
% for modeling is called 'training set'. This makes it more difficult to
% <http://en.wikipedia.org/wiki/Overfitting overfit> your model, because 
% you can test your model against the data you didn't use in the modeling 
% process. 

% Set the random number seed to make the results repeatable
rng('default');

% Partition the dataset to a 80:20 split
cv = cvpartition(height(T),'holdout',0.20);

% Training set
Xtrain = T(training(cv),:);
Ytrain = class(training(cv));
% fprintf('\nTraining Set\n')
% tabulate(Ytrain)

% Test set
Xtest = T(test(cv),:);
Ytest = class(test(cv));
% fprintf('\nTest Set\n')
% tabulate(Ytest)

%% Clean and normalize the dataset
% Raw data is never clean, so you need to check for missing values and
% transform data into usable form. If the range of values differ
% substantially from one variable to another, it can affect the machine
% learning algorithms. Therefore we normalize the data as well. 

%  check for missing values
% missingVals = sum(ismissing(Xtrain));
% fprintf('\nNum vars with missing vals: %d\n',sum(missingVals > 0))
% fprintf('Max num missing vals      : %d/%d\n',max(missingVals),height(Xtrain))
% fprintf('Avg num missing vals      : %d/%d\n\n',mean(missingVals(missingVals > 0)),height(Xtrain))

% too many values missing for those variables to be useful
% dropping vars with missing values 
Xtrain = Xtrain(:,missingVals == 0); Xtest = Xtest(:,missingVals == 0);

% separate users
users = double(categorical(Xtrain.user_name));

% remove user name, time stamps, etc.
Xtrain(:,1:6) =[]; Xtest(:,1:6) =[];

% apply normalization to each variable in training set
arr = table2array(Xtrain); mu = mean(arr); sigma = std(arr);
shiftMean2Zero = bsxfun(@minus,arr,mu); 
scaleBySigma = bsxfun(@rdivide,shiftMean2Zero,sigma);
Xtrain = array2table(scaleBySigma,'VariableNames',Xtrain.Properties.VariableNames);

% apply normalzation to each variable in test set 
% with mu and sigma from training set (because test set mu and sigma will
% not be available in actual predictive use of the model).
arr = table2array(Xtest);
shiftMean2Zero = bsxfun(@minus,arr,mu); 
scaleBySigma = bsxfun(@rdivide,shiftMean2Zero,sigma);
Xtest = array2table(scaleBySigma,'VariableNames',Xtest.Properties.VariableNames);
% disp('Vars with missing vals and others removed.')

%% Exploratory Data Analysis
% You begin exploratory data analysis by plotting the variables in order to
% get oriented with the dataset. Plots of the first four variables show
% that:
% 
% # data is sorted by class - requires random reshuffling. 
% # data points cluster around a few different mean values - 
% indicating that measurements were taken by devices calibrated in a few 
% different ways. The following plot shows the first variable by users, and
% it is clear that one group used one calibration and another group used a
% different one. 
% # those variables exhibit a distinct patterns for Class E (colored in 
% magenta)- those variables will be useful to isolate it.

figure
subplot(2,2,1)
gscatter(1:height(Xtrain),Xtrain.roll_belt,Ytrain,'bgrcm','o',5,'off')
xlim([1 height(Xtrain)]);title('Colored by 5 activity type');ylabel('roll belt');
subplot(2,2,2)
gscatter(1:height(Xtrain),Xtrain.pitch_belt,Ytrain,'bgrcm','o',5,'off')
xlim([1 height(Xtrain)]);title('Colored by 5 activity type');ylabel('pitch belt');
subplot(2,2,3)
gscatter(1:height(Xtrain),Xtrain.yaw_belt,Ytrain,'bgrcm','o',5,'off')
xlim([1 height(Xtrain)]);title('Colored by 5 activity type');ylabel('yaw belt');
subplot(2,2,4)
gscatter(1:height(Xtrain),Xtrain.total_accel_belt,Ytrain,'bgrcm','o',5,'off')
xlim([1 height(Xtrain)]);title('Colored by 5 activity types');ylabel('total accel belt');

% plot the first variable by user
% figure
% gscatter(1:height(Xtrain),Xtrain.roll_belt,users,'bgrcmy','o',5,'off')
% ylabel('roll belt'); xlabel('index'); title('Colored by 6 users')

%% Radomizing the dataset
% The exloratory analysis shows that the dataset is ordered by class. In
% reality, new unknown data could belong to any of the five classes, rather
% than in neatly ordered sequence. To make the prediction more realistic,
% we need to reshuffle the dataset. 
% 
% This step may not be very important in this case because the data will be
% randomized in Random Forest algorithm we will use later, but it is still
% a good general practice to keep in mind.

% reshuffle the training set
randidx = randperm(height(Xtrain));
Xtrain = Xtrain(randidx,:);
Ytrain = Ytrain(randidx);

% reshuffle the test set
randidx = randperm(height(Xtest));
Xtest = Xtest(randidx,:);
Ytest = Ytest(randidx);

% remove unnecessary variables
clearvars arr class cv missingVals mu scaleBySigma shiftMean2Zero...
    randidx sigma T users 
