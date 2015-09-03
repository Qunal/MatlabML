function R_Sqr1 = Rsquared(Y, YHat )
%RSQUARED

SStot = sum((Y - mean(Y)).*(Y - mean(Y)));

% Calculate residuals
resid1 = Y - YHat;

% Square residuals
resid1_sqrd = resid1.*resid1;

% Take the sum of the squared residuals
SSerr1 = sum(resid1_sqrd);

% Calculate R^2
R_Sqr1 = 1 - (SSerr1/SStot);

end

