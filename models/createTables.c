#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

void createTables(sqlite3 *db) {
  char *zErrMsg = 0;
  char *sql;
  char **tablesNames;
  int selectedTable = 10;
  int rc;

  sql = "CREATE TABLE IF NOT EXISTS LIST("  \
        "ID INT PRIMARY KEY     NOT NULL," \
        "TITLE          TEXT    NOT NULL," \
        "CONTENT        TEXT    NOT NULL);";

  rc = sqlite3_exec(db, sql, NULL, 0, &zErrMsg);

  if(rc != SQLITE_OK){
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
  } else {
    fprintf(stdout, "Table list created successfully\n");
  }
}