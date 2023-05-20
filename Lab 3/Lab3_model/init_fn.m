function init_fn()
clear all

assignin ('base', 'm', 1600) %kg
assignin ('base', 'r', 0.30) %m
assignin ('base', 'v0', 0) %km/h

assignin ('base', 'MAX_SPEED_FORWARD', 240) %km/h
assignin ('base', 'MAX_SPEED_BACKWARD', 60) %km/h

assignin ('base', 'MAX_TORQUE_REVERSE', 40) %Nm
assignin ('base', 'MAX_TORQUE', 80) %Nm
assignin ('base', 'TRANSMISSION_RATIO', 12)
assignin ('base','MAX_RDB_ENGAGE_SPEED', 0.5) %km/h

assignin ('base', 'S', 3.5) %m^2
assignin ('base', 'rho', 1.25) %kg/m^3
assignin ('base', 'c_x', 0.3)
S = evalin('base', 'S');
rho = evalin ('base', 'rho');
c_x = evalin ('base', 'c_x');
assignin ('base','X_air', S*rho*c_x/2) % Ns/m 
X_air = evalin('base', 'X_air'); 
assignin ('base', 'X_tyres', X_air*50/3.6) %Ns^2/m^2

% Ogni virgola e return nei commenti è presente nei vettori come punto di riferimento
% ======================= TEST LOGICA ===============================================
% parto fermo freno ingrano retro, accelero indietro mi fermo inizio ad ingranare D, 
% con D accelero ed ingrano B, freno rigenerativo fino a fermo e riaccelero,
% freno rigenerativo e riaccelero, provo retro aggiungo freno e ingrano R,
% freno e ingrano B freno rigenerativo fino a fermo e ingrano D,
% accelero ingranando B e freno rigenerativo ripassando a D,
% ======================= TEST ERRORI ===============================================
gas=[0 0 0, linspace(0,1,5) linspace(1,0,4) 0, ...
    linspace(0,1,7), linspace(1,0,5) .5 .7, ...
    .5 .2 .5 .7, linspace(.4,0,3) zeros(1,4), ...
    linspace(0,1,3) linspace(1,0,3) 0, ...
    linspace(0,1,3) linspace(1,.1,3) .1];
brake=[0 1 1, zeros(1,5) ones(1,5), ...
    zeros(1,7), zeros(1,7), ... 
    zeros(1,4), zeros(1,6) 1, ...
    1 zeros(1,5) 0, ...
    zeros(1,7)];
vel=[0 0 0, linspace(0,-50,5) linspace(-50,0,5), ...
    linspace(0,90,7), linspace(90,0,5) 5 30, ...
    40 20 30 50, 55 40 20 10 zeros(1,3), ...
    linspace(0,40,3) linspace(40,0,3) 0, ...
    linspace(0,40,3) linspace(40,10,3) 10];
selector=[0 0 1, ones(1,8) 3*ones(1,2), ...
    3*ones(1,5) 4*ones(1,2), 4*ones(1,7), ...
    4*ones(1,4), ones(1,7), ... 
    4*ones(1,6) 3, ...
    4*ones(1,6) 3];
%
tFin=length(gas);

assignin('base','tFin',tFin);
assignin('base','gas',gas);
assignin('base','brake',brake);
assignin('base','vel',vel);
assignin('base',"selector",selector);

end

