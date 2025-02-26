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
using namespace std;
int main(void){
  int pId12;
  char buff[100];

  FILE *fIn;

  fIn = fopen("input.txt", "r");
  fgets(buff, 4, fIn);
  strcat(buff, "+P1");

  pId12 = open(fifo12, O_WRONLY);
  write(pId12, buff, 99);

  printf("P1=%d, pPid=%d, in file str=%s\n", getpid(), getppid(), buff);

  close(pId12);
  fclose(fIn);
  exit(0);
}
