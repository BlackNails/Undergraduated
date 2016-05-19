function [X_norm, mu, sigma] = featureNormalize(X)

X_norm = X;
mu = zeros(1, size(X, 2));
sigma = zeros(1, size(X, 2));
mu = mean(X);
sigma = std(X);
t = ones(length(X),1);
X_norm = (X.-(t*mu)) ./ (t*sigma);
end

