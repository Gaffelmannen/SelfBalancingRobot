% Self Balancing Robot
% H. Sandstr?m
% K-F Johansson
% 2013-02-27

% Rensa
clear all;
close all;

% Read file
load crap.dat; % this is just fake data at  the moment

% Create a new variable to put it in, called acc
acc = crap( :,1 );

% Get the time value and set granularity
time = 4285;
samples = size(acc);
t = time./samples;
x=t:t:time;

% Calc mean value
%mean(acc,1);

% Apply low-pass filter
accfilt = filter(x, [1 x-1], acc);

% Plot it
%plot(x, acc, 'k');
%hold on;
plot(x, accfilt);

%plot(acc, '--rs','LineWidth',1,...
%'MarkerEdgeColor','r',...
%'MarkerFaceColor','b',...
%'MarkerSize',10)

% Vi ska sedan ta fram info f?r ?verf?ringsfkn, etc.
% - step