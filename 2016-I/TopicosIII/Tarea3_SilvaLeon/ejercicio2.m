% Cargamos los datos
data = load('ex1data2.txt');

%% x las dos primeras columnas
x = data(:, 1:2);

%% y la tercera columna
y = data(:, 3);
m = length(y);

%% Se normalizan los valores[
[x mu sigma] = featureNormalize(x);
%%Se agregan 1's a x para theta0
x = [ones(m, 1) x];

alpha = 0.01; %% learning rate
num_iters = 400;


theta = zeros(3, 1);
[theta, J4] = gradientDescentMulti(x, y, theta, alpha, num_iters);

%% PRobar con Varios alpha
alpha = 0.3
theta = zeros(3, 1);%% inicializamos a 0 para calcular denuevo
[theta, J1] = gradientDescentMulti(x, y, theta, alpha, num_iters);

alpha = 0.1
theta = zeros(3, 1);
[theta, J2] = gradientDescentMulti(x, y, theta, alpha, num_iters);

alpha = 0.03
theta = zeros(3, 1);
[theta, J3] = gradientDescentMulti(x, y, theta, alpha, num_iters);

alpha = 0.003
theta = zeros(3, 1);
[theta, J5] = gradientDescentMulti(x, y, theta, alpha, num_iters);

alpha = 0.001
theta = zeros(3, 1);
[theta, J6] = gradientDescentMulti(x, y, theta, alpha, num_iters);

%% Graficamos todos los J con distintos alpha
figure;
plot(1:50,J1(1:50),'-')
hold on;
plot(1:50,J2(1:50))
plot(1:50,J3(1:50))
plot(1:50,J4(1:50))
plot(1:50,J5(1:50))
plot(1:50,J6(1:50))
hold off;
fprintf('Mientras el valor de alpha es mas pequeño se tarda mas en encontrar el minimo\n')

%%Modificar Numero de iteraciones

alpha = 0.01
num_iters = [5,50,500]
theta = zeros(3, 1);
[theta, Ja] = gradientDescentMulti(x, y, theta, alpha, num_iters(1));
theta = zeros(3, 1);
[theta, Jb] = gradientDescentMulti(x, y, theta, alpha, num_iters(2));
theta = zeros(3, 1);
[theta, Jc] = gradientDescentMulti(x, y, theta, alpha, num_iters(3));

fprintf("Comparando los J con diferentes iteraciones con alpha constante mientras mas iteraciones la convergencia es mejor\n")

%% Predecir Valores finales

prediction = [1,3,1650]*theta
fprintf("Costo para area de 1650 pies y 3 cuartos %f\n",prediction);

fprintf("Con minimos cuadrados: %f\n",theta);

theta = normalEqn(x,y);

fprintf("Con ecuacion normal: %f\n",theta);

fprintf("Predicion con ecuacion normal %f \n",[1,3,1650]*theta);

fprintf("Se observa que la prediccion no es buena con la ecuacion normal\n")
fprintf("\nEnter para salir")
pause;

