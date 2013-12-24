//
//  R_SQLite.c
//  R_SQLite
//
//  Created by RocKK on 12/19/13.
//  Copyright (c) 2013 RocKK.
//  All rights reserved.
//
//  Redistribution and use in source and binary forms are permitted
//  provided that the above copyright notice and this paragraph are
//  duplicated in all such forms and that any documentation,
//  advertising materials, and other materials related to such
//  distribution and use acknowledge that the software was developed
//  by the RocKK.  The name of the
//  RocKK may not be used to endorse or promote products derived
//  from this software without specific prior written permission.
//  THIS SOFTWARE IS PROVIDED ''AS IS'' AND WITHOUT ANY EXPRESS OR
//  IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
//  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.

#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   const char *sql;
   const char* data = "Callback function called";

//=================================================//

static int callback(void *data, int argc, char **argv, char **azColName)
{
   int i;
   fprintf(stderr, "%s: ", (const char*)data);
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

//=================================================//

void openDB()
{
   rc = sqlite3_open("Database.db", &db);
   if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      exit(0);
   }else{
      fprintf(stdout, "Opened database successfully\n");
   }
}

//=================================================//

void executeStatement()
{
   rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }else{
      fprintf(stdout, "Operation done successfully\n");
   }
}

//=================================================//

void createTable()
{
   printf("//=====CreateTable=====//\n");
   openDB();

   sql = "CREATE TABLE COMPANY("  \
         "ID INT PRIMARY KEY     NOT NULL," \
         "NAME           TEXT    NOT NULL," \
         "AGE            INT     NOT NULL," \
         "ADDRESS        CHAR(50)," \
         "SALARY         REAL );";
   
   executeStatement();
   sqlite3_close(db);
}

//=================================================//

void insertOperation()
{
   printf("//=====Insert=====//\n");
   openDB();

   sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
         "VALUES (1, 'Paul', 32, 'California', 20000.00 ); " \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
         "VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); "     \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
         "VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );" \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
         "VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000.00 );";

   executeStatement();
   sqlite3_close(db);
}

//=================================================//

void selectOperation()
{
   printf("//=====Select=====//\n");
   openDB();

   sql = "SELECT * from COMPANY";

   executeStatement();
   sqlite3_close(db);
}

//=================================================//

void updateOperation()
{
   printf("//=====Update=====//\n");
   openDB();

   sql = "UPDATE COMPANY set SALARY = 25000.00 where ID=1; " \
         "SELECT * from COMPANY";

   executeStatement();
   sqlite3_close(db);
}

//=================================================//

void deleteOperation()
{
   printf("//=====Delete=====//\n");
   openDB();

   sql = "DELETE from COMPANY where ID=2; " \
         "SELECT * from COMPANY";

   executeStatement();
   sqlite3_close(db);
}
