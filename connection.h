#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
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
