X = data(:,1:5);
w = X\SYSLoad;
SYSLoad2 = X*w;
SYSLoad3 = sim(net,X')';
plot([SYSLoad,SYSLoad3])