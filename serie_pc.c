#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "termset.h"
#include <string.h>

int main(void){

int fd;
char a;
struct termios oldtty, newtty;
const char *str1 = "1";
const char *str2 = "2";
fd = open("/dev/ttyUSB2", O_RDWR | O_NOCTTY | O_NDELAY);
if(fd == -1){
printf("ERROR:  no se pudo abrir el dispositivo\n");
return -1;
}
if(termset(fd, 9600, &oldtty, &newtty) == -1){
printf("ERROR: no se pudo configurar el tty\n");
return -1;
}

tcflush(fd, TCIOFLUSH);

do{ //desde acá hace un while infinito hasta que reciba una "s", sino con la "p" prende el led de la placa de arduino y con la "a" lo apaga
scanf("%c", &a);
if(a=='p'){
write(fd, str1, strlen(str1));
tcdrain(fd);
sleep(1);
}
if(a=='a'){
write(fd, str2, strlen(str2));
tcdrain(fd);
sleep(1);
}


}while(a!='s');


close(fd);
return 0;
}


