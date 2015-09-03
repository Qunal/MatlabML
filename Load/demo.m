x = [0:0.1:2*pi]';
y = sin(x)+4*sin(x*10);
plot(x,y)


beta = nlinfit(x,y,@myfunc,[4,10,0,1,1,0]);
y2 = myfunc(beta,x);

hold on
plot(x,y2,'ro')