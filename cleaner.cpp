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

  unlink(fifo12);
  unlink(fifo13);
  unlink(fifo14);
  unlink(fifo25);
  unlink(fifo26);
  unlink(fifo36);
  unlink(fifo58);
  unlink(fifo68);
  unlink(fifo48);
}
