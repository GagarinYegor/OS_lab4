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
  int status;
  if(mkfifo(fifo12, 0606) < 0){
    printf("don't create fifo\n");
    exit(-1);
  }
  if(fork() == 0)
    execl("./P1", "P1", NULL);
  if(fork() == 0)
    execl("./P2", "P2", NULL);
  while(wait(&status)>0);
  unlink(fifo12);
  printf("\n creatorPid= %d\n", getpid());
  exit(0);
}
