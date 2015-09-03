%% Load Duration
% David Willingham
%% Importing Data
myimport %import data
%% Analytics
ldc = sort(SYSLoad,'descend');
x = linspace(0,100,length(ldc))';
%% Plotting
createfigure2(Date1,SYSLoad,x,ldc)