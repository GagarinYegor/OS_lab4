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
#define fifo13 "fifo13"
#define fifo14 "fifo14"

int main(void){
  int pId12, pId13, pId14;
  char buff[100] = "";

  FILE *fIn;
  fIn = fopen("input.txt", "r");
  if(fIn){
    fgets(buff, 4, fIn);
  }
  else{
    printf("input.txt was'nt opened\n");
  }

  strcat(buff, "+P1");

  pId12 = open(fifo12, O_WRONLY);
  write(pId12, buff, 99);
  pId13 = open(fifo13, O_WRONLY);
  write(pId13, buff, 99);
  pId14 = open(fifo14, O_WRONLY);
  write(pId14, buff, 99);

  printf("P1=%d, pPid=%d, in file str=%s\n", getpid(), getppid(), buff);

  close(pId12);
  close(pId13);
  close(pId14);
  fclose(fIn);
  exit(0);
}
