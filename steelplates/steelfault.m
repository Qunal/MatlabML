function out = steelfault(in)

Xtest = in;
load model_TB2
Ypredict = str2double(predict(model_TB2,Xtest(:,fs)));

Faults = {'Pastry','Z_Scratch','K_Scatch','Stains',...
    'Dirtiness','Bumps','Other_Faults'}';

out = Faults(Ypredict);

%#function TreeBagger
