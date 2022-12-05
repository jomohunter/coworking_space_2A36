#include "connection.h"
#include "ui_mainwindow.h"

Connection::Connection()
{

}

bool Connection::createConnection()
{
db = QSqlDatabase ::addDatabase("QODBC");
bool test=false;
db.setDatabaseName("gestionCLIENT");
db.setUserName("chaima44");//inserer nom de l'utilisateur
db.setPassword("bd23");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;




    return  test;
}
int Connection::Authentification(int loginn,QString nom)
{
    QSqlDatabase bd = QSqlDatabase::database();

        QSqlQuery query;
        QString log=QString::number(loginn);
        query.prepare("SELECT * FROM EMPLOYES where ID_EMP=\'"+log+"\' AND NOM_EMP=\'"+nom+"\'");

        query.exec();
        if (query.next())
        {
             return 1;
        }

        else {
            return 0;
        }



}




void Connection ::closeConnection() {db.close();}
