function perc_steel = funtree(Xtrain,Ytrain,Xtest,Ytest)

model_TB = TreeBagger(100,Xtrain,Ytrain,'method','classification','oobvarimp','on');

Ypredict = str2double(predict(model_TB,Xtest));

perc_steel = sum(Ytest ~= Ypredict)/length(Ytest);