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

int main(void){
  int pId13;
  char buff[100];

  pId13 = open(fifo13, O_RDONLY);
  read(pId13, buff, 99);

  strcat(buff, "+P3");

  //pId5 = open(fifo12, O_WRONLY);
  //write(pId5, buff, 99);

  printf("P3=%d, ppid=%d, in pipe str=%s\n", getpid(), getppid(), buff);

  close(pId13);
  exit(0);
}


