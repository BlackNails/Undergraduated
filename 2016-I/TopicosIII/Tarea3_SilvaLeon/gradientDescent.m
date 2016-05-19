function [theta, J_history] = gradientDescent(X, y, theta, alpha, num_iters)

m = length(y); % number of training examples
J_history = zeros(num_iters, 1);

for iter = 1:num_iters
	h = ((X * theta) - y)';
	
	temp1 = theta(1) - alpha * (1/m) * h * X(:,1);
	temp2 = theta(2) - alpha * (1/m) * h * X(:,2);
	
	theta(1) = temp1;
	theta(2) = temp2;
	
	J_history(iter) = computeCost(X,y,theta);
    
    J_history(iter) = computeCost(X, y, theta);

end

end
