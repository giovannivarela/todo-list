#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <unistd.h>

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
     printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

sqlite3_stmt* getAll(sqlite3 *db) {
  char *sql;
  int rc;
  sqlite3_stmt *res;
  const char *tail;

  sql = "SELECT * FROM LIST;";

  if(sqlite3_prepare_v2(db, sql, 128, &res, &tail) != SQLITE_OK) {
    sqlite3_close(db);
    printf("Can't retrieve data: %s\n", sqlite3_errmsg(db));
    return NULL;
  }

  return res;
}

void insertRow(sqlite3 *db, char **input, int count) {
  char *sql;
  int rc;
  sqlite3_stmt *stmt;

  sql = "INSERT INTO LIST (ID, TITLE, CONTENT) VALUES(?,?,?)";

  if(sqlite3_prepare_v2(db, sql, -1, &stmt, NULL)) {
    sqlite3_close(db);
    printf("Can't prepare statement: %s\n", sqlite3_errmsg(db));
    return;
  }

  sqlite3_bind_int(stmt, 1, (count + 1));
  sqlite3_bind_text(stmt, 2, input[0], -1, NULL);
  sqlite3_bind_text(stmt, 3, input[1], -1, NULL);

  rc = sqlite3_step(stmt);
  if (rc != SQLITE_DONE) {
    printf("execution failed: %s", sqlite3_errmsg(db));
  }

  sqlite3_finalize(stmt);

  return;
}