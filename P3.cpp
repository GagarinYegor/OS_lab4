#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
#include <cstdio>
#include <sys/stat.h>

#define fifo13 "fifo13"
#define fifo36 "fifo36"

int main(void){
  int pId13, pId36;
  char buff[100];

  pId13 = open(fifo13, O_RDONLY);
  read(pId13, buff, 99);

  strcat(buff, "+P3");

  pId36 = open(fifo36, O_WRONLY);
  write(pId36, buff, 99);

  printf("P3=%d, ppid=%d, in pipe str=%s\n", getpid(), getppid(), buff);

  close(pId13);
  close(pId36);
  exit(0);
}


