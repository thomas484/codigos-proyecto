#include <stdio.h>
#include "termset.h"

int termset(int fd, int baudrate, struct termios *ttyold, struct termios *ttynew){
switch(baudrate){
case 115200: baudrate = B115200;
break;

case 57600: baudrate = B57600;
break;

case 38400: baudrate = B38400;
break;

case 19200: baudrate = B19200;
break;

case 9600: baudrate = B9600;
break;

default: baudrate = B115200;
break;
}

if (tcgetattr(fd, ttyold) != 0){
  printf(" ERROR : tcgetattr \n");
  return -1;
}
ttynew = ttyold;

cfsetospeed(ttynew, baudrate);
cfsetispeed(ttynew, baudrate);

ttynew->c_cflag = (ttynew->c_cflag & ~CSIZE) | CS8; //bits de datos
ttynew->c_cflag &= ~(PARENB | PARODD); //sin paridad
ttynew->c_cflag &= ~CSTOPB; //1 bit de parada

ttynew->c_cflag |= (CLOCAL | CREAD);
ttynew->c_cflag &= ~CRTSCTS;


ttynew->c_iflag &= ~IGNBRK;
ttynew->c_iflag &= ~(IXON | IXOFF | IXANY);


ttynew->c_lflag =0;
ttynew->c_oflag =0;
ttynew->c_cc[VMIN] =0;
ttynew->c_cc[VTIME] =100;


if(tcsetattr(fd, TCSAFLUSH, ttynew) != 0){
printf("ERROR : tcsetattr \n");
return -1;

}

return 0;
}
