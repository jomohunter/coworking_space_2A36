#ifndef CONNECTION_H
#define CONNECTION_H
#include "QtSql/QSqlDatabase"
#include "QtSql/qsqlquery.h"
#include "QtSql/QSqlError"
#include"employe.h"

class Connection
{
    QSqlDatabase db;
public:
    Connection();
    bool createConnection();
    int Authentification(int loginn,QString nom);

    void closeConnection();
};

#endif // CONNECTION_H
