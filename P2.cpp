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
#define fifo25 "fifo25"
#define fifo26 "fifo26"

int main(void){
  int pId12, pId25, pId26;
  char buff[100];

  pId12 = open(fifo12, O_RDONLY);
  read(pId12, buff, 99);

  strcat(buff, "+P2");

  pId25 = open(fifo25, O_WRONLY);
  write(pId25, buff, 99);
  pId26 = open(fifo26, O_WRONLY);
  write(pId26, buff, 99);

  printf("P2=%d, ppid=%d, in pipe str=%s\n", getpid(), getppid(), buff);

  close(pId12);
  close(pId25);
  close(pId26);
  exit(0);
}

