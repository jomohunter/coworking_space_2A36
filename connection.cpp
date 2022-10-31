#include "connection.h"

Connection::Connection(){}

bool Connection::createconnection()
{
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
bool test=false;
db.setDatabaseName("hama_ghrab");
db.setUserName("system");
db.setPassword("khalil");

if (db.open()) test=true;
return test;

}

void Connection::closeconnection(){db.close();}
