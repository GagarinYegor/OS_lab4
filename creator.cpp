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
#define fifo25 "fifo25"

int main(void){
  int status;
  if(mkfifo(fifo12, 0606) < 0){
    printf("don't create fifo\n");
    exit(-1);
  }
  if(mkfifo(fifo13, 0606) < 0){
    printf("don't create fifo\n");
    exit(-1);
  }
  if(mkfifo(fifo14, 0606) < 0){
    printf("don't create fifo\n");
    exit(-1);
  }
  if(mkfifo(fifo25, 0606) < 0){
    printf("don't create fifo\n");
    exit(-1);
  }
  if(fork() == 0)
    execl("./P1", "P1", NULL);
  if(fork() == 0)
    execl("./P2", "P2", NULL);
  if(fork() == 0)
    execl("./P3", "P3", NULL);
  if(fork() == 0)
    execl("./P4", "P4", NULL);
  if(fork() == 0)
    execl("./P5", "P5", NULL);
  while(wait(&status)>0);
  unlink(fifo12);
  unlink(fifo13);
  unlink(fifo14);
  unlink(fifo25);
  printf("\n creatorPid= %d\n", getpid());
  exit(0);
}
