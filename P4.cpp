#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
#include <cstdio>
#include <sys/stat.h>

#define fifo14 "fifo14"

int main(void){
  int pId14;
  char buff[100];

  pId14 = open(fifo14, O_RDONLY);
  read(pId14, buff, 99);

  strcat(buff, "+P4");

  //pId5 = open(fifo12, O_WRONLY);
  //write(pId5, buff, 99);

  printf("P4=%d, ppid=%d, in pipe str=%s\n", getpid(), getppid(), buff);

  close(pId14);
  exit(0);
}


