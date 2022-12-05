#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include<QDebug>
#include "login.h"
#include "connection.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;

    bool test=c.createConnection();
    MainWindow w;
    login l;
    menu me;


    if(test)
    {
        l.show();




}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}
