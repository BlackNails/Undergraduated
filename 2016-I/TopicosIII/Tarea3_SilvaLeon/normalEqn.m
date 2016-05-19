function [theta] = normalEqn(X, y)

theta = zeros(size(X, 2), 1);
theta = inverse(X' * X) * X' * y;

end
