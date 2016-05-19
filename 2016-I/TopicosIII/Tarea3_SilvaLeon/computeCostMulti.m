function J = computeCostMulti(X, y, theta) 

m = length(y); 
J = 0;
J = (1/2*m) * (X*theta-y)' * (X*theta-y);
end
