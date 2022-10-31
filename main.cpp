#include "mainwindow.h"
#include "connection.h"
#include "equipment.h"
#include "modify.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    Connection c;
    QApplication a(argc, argv);
    bool test=c.createconnection();
    MainWindow w;
    if(test)
    {
    w.show();
    QMessageBox::information(nullptr, QObject::tr("database is open"),QObject::tr("connection succeful.\n"), QMessageBox::Cancel);

    }
    else{
         w.show();
    QMessageBox::critical(nullptr, QObject::tr("database is not open"),QObject::tr("connection failed. \n" "Click Cancel to exit."), QMessageBox::Cancel);
}



    return a.exec();
}
