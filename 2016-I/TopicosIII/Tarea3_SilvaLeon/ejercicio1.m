%% Desarrollo

%% Parte 1Graficar los datos

data = load('ex1data1.txt'); % Se carga el archivo
x = data(:, 1); y = data(:, 2); % Se asigna la columna 1 y 2
								% a X y Y 
plotData(x,y);%se grafican los datos


%% Parte 2 Funcion de costo
theta = 0
computeCost(x,y,theta)

%% Parte 3 Gradiente descendente
num_iters = 1500;	%% Numero de iteraciones
alpha = 0.01; 		%% Learning rate suficientemente pequeño
theta = zeros(2, 1);%% son 2 parametros
m = length(y); %% Training examples
x = [ones(m, 1), data(:,1)];%% Para que se pueda multiplicar con theta

	%% Se calculan los parametros
theta = gradientDescent(x, y, theta, alpha, num_iters);

fprintf('Parametros : %f %f \n', theta(1), theta(2));

hold on; % para graficar la recta encima del grafico ploteado

%%Se grafica la recta con parametros theta 1 y theta 2
plot(x(:,2), x*theta, '-') 

hold off;%% para dejar de graficar encima

%%Luego graficar la funcion de costo

% Creamos el grid
theta0_vals = linspace(-10, 10, 100);
theta1_vals = linspace(-1, 4, 100);

%% Inicializa los valores de J en 0
J_vals = zeros(length(theta0_vals), length(theta1_vals));

% Calculamos los valores de J con la funcion de costo
for i = 1:length(theta0_vals)
    for j = 1:length(theta1_vals)
	  t = [theta0_vals(i); theta1_vals(j)];    
	  J_vals(i,j) = computeCost(x, y, t);
    end
end

J_vals = J_vals';
% Surface plot
figure; %% nueva figura
surf(theta0_vals, theta1_vals, J_vals) %% se grafica la superficie
xlabel('\theta_0'); ylabel('\theta_1');

%% Graficamos los contornos

figure;
contour(theta0_vals, theta1_vals, J_vals, logspace(-2, 3, 20));
xlabel('\theta_0'); ylabel('\theta_1');
hold on;
plot(theta(1), theta(2), 'rx', 'MarkerSize', 10, 'LineWidth', 2);


%% Predecir valores

predict1 = [1,3.5]*theta; %% Costo1
predict2 = [1,7]*theta;   %% Costo2
%%fprintf('Parameters : ',theta);
fprintf('Population: 35,000 Cost --> %f\n',predict1*10000);
fprintf('Population: 70,000 Cost --> %f\n',predict1*10000);
fprintf("\nPresionar enter para salir")
pause;

