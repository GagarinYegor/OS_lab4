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
#define fifo26 "fifo26"
#define fifo36 "fifo36"
#define fifo58 "fifo58"
#define fifo68 "fifo68"
#define fifo48 "fifo48"

int main(void){
  int status;
  if(mkfifo(fifo12, 0606) < 0){
    printf("don't create fifo12\n");
    exit(-1);
  }
  if(mkfifo(fifo13, 0606) < 0){
    printf("don't create fifo13\n");
    exit(-1);
  }
  if(mkfifo(fifo14, 0606) < 0){
    printf("don't create fifo14\n");
    exit(-1);
  }
  if(mkfifo(fifo25, 0606) < 0){
    printf("don't create fifo25\n");
    exit(-1);
  }
  if(mkfifo(fifo26, 0606) < 0){
    printf("don't create fifo26\n");
    exit(-1);
  }
  if(mkfifo(fifo36, 0606) < 0){
    printf("don't create fifo36\n");
    exit(-1);
  }
  if(mkfifo(fifo58, 0606) < 0){
    printf("don't create fifo58\n");
    exit(-1);
  }
  if(mkfifo(fifo68, 0606) < 0){
    printf("don't create fifo68\n");
    exit(-1);
  }
  if(mkfifo(fifo48, 0606) < 0){
    printf("don't create fifo48\n");
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
  if(fork() == 0)
    execl("./P6", "P6", NULL);
  if(fork() == 0)
    execl("./P8", "P8", NULL);
  while(wait(&status)>0);
  unlink(fifo12);
  unlink(fifo13);
  unlink(fifo14);
  unlink(fifo25);
  unlink(fifo26);
  unlink(fifo36);
  unlink(fifo58);
  unlink(fifo68);
  unlink(fifo48);
  printf("\ncreatorPid=%d\n", getpid());
  exit(0);
}
