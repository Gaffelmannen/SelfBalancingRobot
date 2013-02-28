%F�desplan f�r att l�sa v�ran data ifr�n serieporten

%run('clean');
clear all;
close all;

%Initirea comporten
s = serial('/dev/tty.usbmodem641'); %our comport
 
set(s, 'InputBufferSize', 256); %number of bytes in inout buffer
set(s, 'FlowControl', 'hardware');
set(s, 'BaudRate', 9600);
set(s, 'Parity', 'none');
set(s, 'DataBits', 8);
set(s, 'StopBit', 1);
set(s, 'Timeout',10);

%V�nta p� input fr�n anv�ndare
reply = 0;
while reply ~= 'G'
    reply = input('Do you want more? Y/N [Y]: ', 's');
end
%N�r G kommer...
%...starta l�sning ifr�n comporten
fopen(s);   %Open stream
fprintf(s,reply);   %Send character on stream

%skicka G
%L�gg v�rden i en array
%stoppa inl�sning utav data
%st�ng comporten
%ber�kna storleken p� arrayen
%l�s sista v�rdet (tiden)
%dela tiden med antal sampels (l�sta rader - 1) l�g i deltaT
% plotta v�rden med deltaT som mellanrum