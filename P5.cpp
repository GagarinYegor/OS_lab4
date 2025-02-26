#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
#include <cstdio>
#include <sys/stat.h>

#define fifo25 "fifo25"
#define fifo58 "fifo58"

int main(void){
  int pId25, pId58;
  char buff[100];

  pId25 = open(fifo25, O_RDONLY);
  read(pId25, buff, 99);

  strcat(buff, "+P5");

  pId58 = open(fifo58, O_WRONLY);
  write(pId58, buff, 99);

  printf("P5=%d, ppid=%d, in pipe str=%s\n", getpid(), getppid(), buff);

  close(pId25);
  close(pId58);
  exit(0);
}

