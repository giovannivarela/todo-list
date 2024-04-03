#include <stdio.h>
#include <stdlib.h>

void clearTerminal(){
  printf("\033[2J\033[1;1H");
}

void moveCursor(int *position){
  printf("\033[%d;%dH", position[0], position[1]);
}