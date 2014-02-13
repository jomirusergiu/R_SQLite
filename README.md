R_SQLite
=================

R_SQLite is a small c class that implements SQLite library for managing databases.
SQLite is a software library that implements a self-contained, serverless, zero-configuration, transactional SQL database engine. SQLite is the most widely deployed SQL database engine in the world. The source code for SQLite is in the public domain.

Usage
-------------

Before we start using SQLite in our C/C++ programs, we need to make sure that we have SQLite library set up on the machine. You can check SQLite Installation chapter to understand installation process from this link:
http://www.tutorialspoint.com/sqlite/pdf/sqlite_installation.pdf

```C
#include "R_SQLite.c"

int main(int argc, char* argv[])
{
   createTable();
   insertOperation();
   selectOperation();
   updateOperation();
   deleteOperation();
   return 0;
}
```

```Bash
$ gcc main.cpp -l sqlite3
$ ./a.out
$ RocKK$ ./a.out 
//=====CreateTable=====//
Opened database successfully
Operation done successfully
//=====Insert=====//
Opened database successfully
Operation done successfully
//=====Select=====//
Opened database successfully
Callback function called: ID = 1
NAME = Paul
AGE = 32
ADDRESS = California
SALARY = 20000.0

Callback function called: ID = 2
NAME = Allen
AGE = 25
ADDRESS = Texas
SALARY = 15000.0

Callback function called: ID = 3
NAME = Teddy
AGE = 23
ADDRESS = Norway
SALARY = 20000.0

Callback function called: ID = 4
NAME = Mark
AGE = 25
ADDRESS = Rich-Mond 
SALARY = 65000.0

Operation done successfully
//=====Update=====//
Opened database successfully
Callback function called: ID = 1
NAME = Paul
AGE = 32
ADDRESS = California
SALARY = 25000.0

Callback function called: ID = 2
NAME = Allen
AGE = 25
ADDRESS = Texas
SALARY = 15000.0

Callback function called: ID = 3
NAME = Teddy
AGE = 23
ADDRESS = Norway
SALARY = 20000.0

Callback function called: ID = 4
NAME = Mark
AGE = 25
ADDRESS = Rich-Mond 
SALARY = 65000.0

Operation done successfully
//=====Delete=====//
Opened database successfully
Callback function called: ID = 1
NAME = Paul
AGE = 32
ADDRESS = California
SALARY = 25000.0

Callback function called: ID = 3
NAME = Teddy
AGE = 23
ADDRESS = Norway
SALARY = 20000.0

Callback function called: ID = 4
NAME = Mark
AGE = 25
ADDRESS = Rich-Mond 
SALARY = 65000.0

Operation done successfully
```

License
--------

This code is under the BSD license.
