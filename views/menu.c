#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include "../common/commonFunctions.c"
#include <unistd.h>

void printInputLine(char*** input, int count) {

  size_t len = 0;
  int positionYX[2];
  ssize_t readInput;

  *input = (char **)malloc(2 * sizeof(char *));
  (*input)[0] = (char *)malloc(100 * sizeof(char));
  (*input)[1] = (char *)malloc(100 * sizeof(char));

  fgets((*input)[0], 100, stdin);
  (*input)[0][strcspn((*input)[0], "\n")] = 0;
  positionYX[0] = count + 3;
  positionYX[1] = 17;
  moveCursor(positionYX);
  printf(" | ");
  positionYX[1] = 20;
  moveCursor(positionYX);
  fgets((*input)[1], 100, stdin);
  (*input)[1][strcspn((*input)[1], "\n")] = 0;
}

int printMainScreen(sqlite3_stmt *res){
  int count = 0;

  clearTerminal();
  printf("___________________________\n");
  printf("To Do List\n");

  while(sqlite3_step(res) == SQLITE_ROW) {
    printf("%16s | %32s\n",
           sqlite3_column_text(res, 1),
           sqlite3_column_text(res, 2));

    count++;
  }
  
  return count;
}