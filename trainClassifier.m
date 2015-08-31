function [trainedClassifier, validationAccuracy] = trainClassifier(datasetTable)
% Extract predictors and response
predictorNames = {'roll_belt', 'pitch_belt', 'yaw_belt', 'total_accel_belt', 'gyros_belt_x', 'gyros_belt_y', 'gyros_belt_z', 'accel_belt_x', 'accel_belt_y', 'accel_belt_z', 'magnet_belt_x', 'magnet_belt_y', 'magnet_belt_z', 'roll_arm', 'pitch_arm', 'yaw_arm', 'total_accel_arm', 'gyros_arm_x', 'gyros_arm_y', 'gyros_arm_z', 'accel_arm_x', 'accel_arm_y', 'accel_arm_z', 'magnet_arm_x', 'magnet_arm_y', 'magnet_arm_z', 'roll_dumbbell', 'pitch_dumbbell', 'yaw_dumbbell', 'total_accel_dumbbell', 'gyros_dumbbell_x', 'gyros_dumbbell_y', 'gyros_dumbbell_z', 'accel_dumbbell_x', 'accel_dumbbell_y', 'accel_dumbbell_z', 'magnet_dumbbell_x', 'magnet_dumbbell_y', 'magnet_dumbbell_z', 'roll_forearm', 'pitch_forearm', 'yaw_forearm', 'total_accel_forearm', 'gyros_forearm_x', 'gyros_forearm_y', 'gyros_forearm_z', 'accel_forearm_x', 'accel_forearm_y', 'accel_forearm_z', 'magnet_forearm_x', 'magnet_forearm_y', 'magnet_forearm_z'};
predictors = datasetTable(:,predictorNames);
predictors = table2array(varfun(@double, predictors));
response = datasetTable.classe;
% Train a classifier
trainedClassifier = fitensemble(predictors, response, 'Bag', 200, 'Tree', 'Type', 'Classification', 'PredictorNames', {'roll_belt' 'pitch_belt' 'yaw_belt' 'total_accel_belt' 'gyros_belt_x' 'gyros_belt_y' 'gyros_belt_z' 'accel_belt_x' 'accel_belt_y' 'accel_belt_z' 'magnet_belt_x' 'magnet_belt_y' 'magnet_belt_z' 'roll_arm' 'pitch_arm' 'yaw_arm' 'total_accel_arm' 'gyros_arm_x' 'gyros_arm_y' 'gyros_arm_z' 'accel_arm_x' 'accel_arm_y' 'accel_arm_z' 'magnet_arm_x' 'magnet_arm_y' 'magnet_arm_z' 'roll_dumbbell' 'pitch_dumbbell' 'yaw_dumbbell' 'total_accel_dumbbell' 'gyros_dumbbell_x' 'gyros_dumbbell_y' 'gyros_dumbbell_z' 'accel_dumbbell_x' 'accel_dumbbell_y' 'accel_dumbbell_z' 'magnet_dumbbell_x' 'magnet_dumbbell_y' 'magnet_dumbbell_z' 'roll_forearm' 'pitch_forearm' 'yaw_forearm' 'total_accel_forearm' 'gyros_forearm_x' 'gyros_forearm_y' 'gyros_forearm_z' 'accel_forearm_x' 'accel_forearm_y' 'accel_forearm_z' 'magnet_forearm_x' 'magnet_forearm_y' 'magnet_forearm_z'}, 'ResponseName', 'classe', 'ClassNames', {'A' 'B' 'C' 'D' 'E'});

% Perform cross-validation
partitionedModel = crossval(trainedClassifier, 'KFold', 10);

% Compute validation accuracy
validationAccuracy = 1 - kfoldLoss(partitionedModel, 'LossFun', 'ClassifError');

%% Uncomment this section to compute validation predictions and scores:
% % Compute validation predictions and scores
% [validationPredictions, validationScores] = kfoldPredict(partitionedModel);