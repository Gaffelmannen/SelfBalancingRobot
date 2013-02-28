%F?desplan f?r att l?sa v?ran data ifr?n serieporten

%run('clean');
clear all;
close all;

%Initirea comporten
%s = serial('/dev/tty.usbmodem641'); %Kalf comport
s = serial('/dev/tty.usbmodem621'); %Hans comport

set(s, 'InputBufferSize', 1024); %number of bytes in inout buffer
set(s, 'FlowControl', 'hardware');
set(s, 'BaudRate', 9600);
set(s, 'Parity', 'none');
set(s, 'DataBits', 8);
set(s, 'StopBit', 1);
set(s, 'Timeout',10);

%V?nta p? input fr?n anv?ndare
reply = 0;
while reply ~= 'G'
    reply = input('Send data? [G]: ', 's');
end
%N?r G kommer...

%...starta l?sning ifr?n comporten
fopen(s);   %Open stream

%skicka G
%fprintf(s,reply);   %Send character on stream

% ge t, X och A begynnelsev?rden
t=1;
X=0;
A = eye( 1, 200 );

disp('Executing thy bidding, master!');

fread(s);

%stoppa inl?sning utav data
fclose(s);

%st?ng comporten
%ber?kna storleken p? arrayen
%l?s sista v?rdet (tiden)
%dela tiden med antal sampels (l?sta rader - 1) l?g i deltaT
% plotta v?rden med deltaT som mellanrum