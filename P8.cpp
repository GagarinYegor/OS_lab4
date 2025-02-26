#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
#include <cstdio>
#include <sys/stat.h>

#define fifo58 "fifo58"
#define fifo68 "fifo68"
#define fifo48 "fifo48"

int main(void){
  int pId58, pId68, pId48;
  char buff1[100], buff2[100], buff3[100], buff4[100] = "";

  pId58 = open(fifo58, O_RDONLY);
  read(pId58, buff1, 99);
  pId68 = open(fifo68, O_RDONLY);
  read(pId68, buff2, 99);
  pId48 = open(fifo48, O_RDONLY);
  read(pId48, buff3, 99);

  strcat(buff4, "");
  strcat(buff4, "(");
  strcat(buff4, buff1);
  strcat(buff4, "+");
  strcat(buff4, buff2);
  strcat(buff4, "+");
  strcat(buff4, buff3);
  strcat(buff4, ")");
  strcat(buff4, "+P8");

  printf("P8=%d, ppid=%d, in pipe str=%s\n", getpid(), getppid(), buff4);

  close(pId58);
  close(pId68);
  close(pId48);
  exit(0);
}

