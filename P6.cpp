#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
#include <cstdio>
#include <sys/stat.h>

#define fifo26 "fifo26"
#define fifo36 "fifo36"
#define fifo68 "fifo68"

int main(void){
  int pId26, pId36, pId68;
  char buff1[100], buff2[100], buff3[100] = "";

  pId26 = open(fifo26, O_RDONLY);
  read(pId26, buff1, 99);
  pId36 = open(fifo36, O_RDONLY);
  read(pId36, buff2, 99);

  strcat(buff3, "");
  strcat(buff3, "((");
  strcat(buff3, buff1);
  strcat(buff3, ")+(");
  strcat(buff3, buff2);
  strcat(buff3, "))");
  strcat(buff3, "+P6");

  pId68 = open(fifo68, O_WRONLY);
  write(pId68, buff3, 99);

  printf("P6=%d, ppid=%d, in pipe str=%s\n", getpid(), getppid(), buff3);

  close(pId26);
  close(pId36);
  close(pId68);
  exit(0);
}

