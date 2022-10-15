#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "termset.h"

int main(void){

int fd;
struct termios oldtty, newtty;
fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY);
if(fd == -1){
printf("ERROR:  no se pudo abrir el dispositivo\n");
return -1;
}
if(termset(fd, 9600, &oldtty, &newtty) == -1){
printf("ERROR: no se pudo configurar el tty\n");
return -1;
}

tcflush(fd, TCIOFLUSH);
for(;;)
{
write(fd, "1", 1);
tcdrain(fd);
sleep(1);
}

for(int d=0; d<20000; d++);

for(;;)
{
write(fd, "2", 1);
tcdrain(fd);
sleep(1);
}

close(fd);
return 0;
}


