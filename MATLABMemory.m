 userview=memory

userview = 

%     MaxPossibleArrayBytes: 3.4851e+09
%     MemAvailableAllArrays: 3.4851e+09
%             MemUsedMATLAB: 943951872
% 
% load('matlab.mat')
% clearvars pmltesting pmltraining;
% save matlab1.mat FixedTesting FixedTraining;


% whos
%   Name                   Size                 Bytes  Class     Attributes
% 
%   A                      1x1                  46284  struct              
%   FixedTesting          20x53                 76108  table               
%   FixedTraining      19622x53              60320254  table 60MB              
%   id                     1x3                    348  cell                
%   pmltesting            20x160               341322  table               
%   pmltraining        19622x160            291359841  table 291MB              
%   userview               1x1                    552  struct     
userview=memory

% userview = 
% 
%     MaxPossibleArrayBytes: 2.9586e+09
%     MemAvailableAllArrays: 2.9586e+09
%             MemUsedMATLAB: 1.4864e+09

UsedMem=1.4864e+09-943951872

% UsedMem =  542 MB
% 
%    542,448,128