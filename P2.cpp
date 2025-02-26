#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
#include <cstdio>
#include <sys/stat.h>


#define fifo12 "fifo12"

int main(void){
  int pId1;
  char buff[100];

  pId1 = open(fifo12, O_RDONLY);
  read(pId1, buff, 99);
  strcat(buff, "+P2");

  printf("P2=%d, ppid=%d, in pipe str=%s\n", getpid(), getppid(), buff);

  close(pId1);
  exit(0);
}

