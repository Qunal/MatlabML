function  plotFitErrors(y,varargin)

% Copyright 2011 The MathWorks, Inc.

figure;

legendName = cell(length(varargin),1);

hold all
for ii = 1:length(varargin)
    yfit = varargin{ii};
    scatter(yfit, (y- yfit)./yfit,'o','filled')
    rs = Rsquared(y,yfit);
    legendName{ii,1} = sprintf('%s (R^2=%0.3f)', inputname(ii+1), rs);
end
hold off


legend(legendName)

refline(0,0)
xlabel('Estimated Value')
ylabel('Error/Estimated Value')