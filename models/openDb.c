#include <sqlite3.h>
#include <stdio.h>

sqlite3 * openDatabase() {
  sqlite3 *db;
  char *zErrMsg = 0;
  int rc;

  rc = sqlite3_open("test.db", &db);

  if(!rc) {
    fprintf(stderr, "Opened database successfully\n");
  }

  if(rc) {
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
  }

  return db;
}