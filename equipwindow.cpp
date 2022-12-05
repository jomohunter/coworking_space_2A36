#include "equipwindow.h"
#include "ui_equipwindow.h"
#include "equip.h"
#include "modify.h"
#include "pdf.h"
#include <qdebug.h>
#include "QMessageBox"
#include <bits/stdc++.h>
#include "dialog.h"
#include <QUrl>
#include <QtCore>
#include <QDesktopServices>
#include <QPainter>
#include <QAbstractItemModel>
#include "statistics.h"
#include "QtSql/QSqlQuery"
#include "arduino.h"

using namespace std;

// valid id code : only uppercase and number (4 caracters exaclty) //
bool valid_id(QString id)
{
    for (int i = 0;i < id.length(); i++)
    {
       if((id[i] >= 'A' && id[i] <= 'Z') || (id[i] >= '0' && id[i] <= '9'))
       {

       }
           else
       {
       return false ;
       }
    }
    return true ;
}

bool isChar(QChar c)
{
    return ((c >= 'a' && c <= 'z')
            || (c >= 'A' && c <= 'Z'));
}

bool isDigit(QChar c)
{
    return (c >= '0' && c <= '9');
}
bool nbis_valid(QString numb)
{
    for (int i = 0; i < numb.length(); i++) {
        if(!isDigit(numb[i])){
            return false;
        }
        else {
            return true;
        }
    }
}
bool is_valid(QString email)
{
    // Check the first character
    // is an alphabet or not
    if (!isChar(email[0])) {

        // If it's not an alphabet
        // email id is not valid
        return 0;
    }
    // Variable to store position
    // of At and Dot
    int At = -1, Dot = -1;

    // Traverse over the email id
    // string to find position of
    // Dot and At
    for (int i = 0;i < email.length(); i++)
    {
        // If the character is '@'
        if (email[i] == '@')
        {
            At = i;
        }
        // If character is '.'
        else if (email[i] == '.') {

            Dot = i;
        }
    }

    // If At or Dot is not present
    if (At == -1 || Dot == -1)
        return 0;

    // If Dot is present before At
    if (At > Dot)
        return 0;

    // If Dot is present at the end
    return !(Dot >= (email.length() - 1));
}
void equipwindow::test(){
    data="";
             data=A.read_from_arduino();


    qDebug() << data ;
    int D=data.toInt();
    qDebug() << D ;
    if (A.cherchercode(D) != -1){
        qDebug() << "Writing to arduino" ;
        A.write_to_arduino("1");
        QString name = A.chercher(D);
        qDebug() << name ;
        QString nom = A.chercher(D) + "haw d5al tawa";
        QMessageBox msgBox;
        msgBox.setText(nom);
        msgBox.exec();
    }else{
        data= "";
    }
                       }


equipwindow::equipwindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::equipwindow)
{
    ui->setupUi((QDialog *)this);
    ui->tableView->setModel(g.Afficher());

    qDebug()<<"start";


    int ret=A.connect_arduino(); // lancer la connexion à arduino
                     switch(ret){
                     case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();


                         break;
                     case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
                        break;
                     case(-1):qDebug() << "arduino is not available";
                     }
            QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(test()));

                       // permet de lancer
                      //le slot update_label suite à la reception du signal readyRead (reception des données).
}

equipwindow::~equipwindow()
{
    delete ui;
}

void equipwindow::on_modify_clicked() //second window opener function //
{
    modify m;
    m.setModal(true);
    m.exec();
    ui->tableView->setModel(g.Afficher());
}

void equipwindow::on_pushButton_clicked()
{
    QString id = ui->lineID_E->text();
    QString nom = ui->lineNom_E->text();
    QString type = ui->lineType_E->text();
    QString local = ui->combo_local->currentText();
    int qt = ui->spinqt_E->value();
    int NUMF =ui->lineType_E_2->text().toInt();

    Equip E(id, nom, type, local, qt, NUMF);
    bool test = true;

    if(test)
        {
        E.Ajouter();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                                     QObject::tr("Ajout avec succés.\nClick Cancel to exit."), QMessageBox::Ok);

        }
        else
        {
        QMessageBox::information(nullptr, QObject::tr("database is not open"),
                                QObject::tr("Ajout échoué.\nClick Cancel to exit."), QMessageBox::Ok);
        }
    ui->tableView->setModel(g.Afficher());

}

void equipwindow::on_pushButton_2_clicked()// delete //
{
    QString d=ui->lineID_d->text();
    bool test=supp.Supprimer(d);
     if(test)
     {

          QMessageBox::information(nullptr, QObject::tr("OK"),
                                  QObject::tr("suppression effectué.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
           }
               else
         {
         QMessageBox::information(nullptr, QObject::tr("supprimer equipement"),
                               QObject::tr("suppression echouée.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
         }
ui->tableView->setModel(g.Afficher());

}

void equipwindow::on_checkBox_stateChanged(int arg1) //search //
{
    if (ui->checkBox->isChecked())
    {
    Equip s ;
    QString id = ui->line_research->text();
        ui->tableView->setModel(s.researchid(id));
    }
    else {
        ui->tableView->setModel(g.Afficher());
}
}

void equipwindow::on_radioButton_clicked()
{
    QMessageBox msgBox ;
                QSqlQueryModel * model= new QSqlQueryModel();

                   model->setQuery("select * from EQUIPEMENTS order by ID_EQUIP");
                   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EQUIP"));
                   model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE_MAT"));
                   model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM_MAT"));
                   model->setHeaderData(3, Qt::Horizontal, QObject::tr("LOCAL"));
                   model->setHeaderData(4, Qt::Horizontal, QObject::tr("QTEEQUIP"));
                   if (ui->radioButton->isChecked())
                   {
                            ui->tableView->setModel(model);
                            ui->tableView->show();
                            msgBox.setText("Tri avec succés.");
                            msgBox.exec();
                   }
                   else {
                       ui->tableView->setModel(g.Afficher());
                   }
}

void equipwindow::on_pushButton_3_clicked()
{
    pdf p;
    p.setModal(true);
    p.exec();

}

void equipwindow::on_pushButton_4_clicked()
{
    ahmed d;
    d.setModal(true);
    d.exec();
}

void equipwindow::on_pushButton_5_clicked()
{
    QSqlQuery q1;
    QString x = ui->lineID_d->text();
    q1.prepare("SELECT NUMF, QTEEQUIP FROM EQUIPEMENTS WHERE ID_EQUIP='"+x+"'");

    QVariant a = q1.value(0);
    QString link = a.toString();
    //QDesktopServices::openUrl(QUrl(link, QUrl::TolerantMode));
    QDesktopServices::openUrl(QUrl("https://wa.me/+216"+x, QUrl::TolerantMode));
    q1.exec();

}

void equipwindow::on_pushButton_6_clicked()
{
    statistics *s = new statistics;
    s->choix_bar();
    s->show();
}

