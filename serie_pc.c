#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "termset.h"
#include <string.h>

int main(int argc, char *argv[]){

int fd;
char a;
int n;
struct termios oldtty, newtty;
//chars para escritura
const char *str1 = "1";
const char *str2 = "2";
const char *str3 = "3";
//chars para lectura 
 char str4[10] = {0};
 
 if(argc != 2) {
    printf("No introdujo el nombre del puerto\n");
    exit(0);
  }
fd = open(argv[1], O_RDWR | O_NOCTTY | O_NDELAY);
if(fd == -1){
printf("ERROR:  no se pudo abrir el dispositivo\n");
return -1;
}
if(termset(fd, 9600, &oldtty, &newtty) == -1){
printf("ERROR: no se pudo configurar el tty\n");
return -1;
}

tcflush(fd, TCIOFLUSH);

do{
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

if(a=='l'){ //condicion para recibir una lectura del puerto 
write(fd, str3, strlen(str3));
tcdrain(fd);
sleep(1);
sleep(1);
sleep(1);
n = read(fd, str4, strlen(str4));
printf("%d %d", n, str4[0]);
printf("\n");

}


}while(a!='s');


close(fd);
return 0;
}


