#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <sqlite3.h>
#include "models/openDb.c"
#include "models/createTables.c"
#include "views/menu.c"
#include "models/lists.c"
#include <unistd.h>

int main(){
  int printedLines = 0;
  char *stop = "D";
  char **lines;

  //configure sqlite
  sqlite3 *db = openDatabase();
  createTables(db);
  //get data
  sqlite3_stmt *res = getAll(db);
  //show main screen
  printedLines = printMainScreen(res);
  printInputLine(&lines, printedLines);

  while(strcmp(lines[0], stop) != 0) {
    // update data in the screen
    insertRow(db, lines, printedLines);
    res = getAll(db);
    printedLines = printMainScreen(res);
    printInputLine(&lines, printedLines);
  }
}