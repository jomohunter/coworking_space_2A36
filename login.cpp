#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connection.h"
#include <QMessageBox>
#include <QDebug>
#include "menu.h"


login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}


//74 auth nbaddel assemi

void login::on_pb_seconnecter_clicked()
{
   // menu m(nullptr);
    Connection  c;
    QString nom=ui->nom->text();;
    int loginn=ui->password->text().toInt();

    if(c.Authentification(loginn,nom)==1)
    {
       QMessageBox::information(this,"Connexion","login et mdp correcte");
     qDebug()<< "Mot de passe et login correct";
     this->hide();
     m.show();
   //  menu* me = new menu(this);

   // m->show();

}
    if(c.Authentification(loginn,nom)==0)
    {
      QMessageBox::critical(this,"Connexion","login et mdp incorrecte");
      qDebug()<< "Mot de passe et login incorrect";
    }
}
