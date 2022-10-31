#include "deleteid.h"
#include "ui_deleteid.h"
#include "ui_mainwindow.h"
#include "equipment.h"
#include "QMessageBox"
#include "equipment.h"

deleteID::deleteID(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deleteID)
{
    ui->setupUi(this);
}

deleteID::~deleteID()
{
    delete ui;
}

void deleteID::on_pushButton_clicked()
{
    int d = ui->line_d->text().toInt();
    bool test=true;
    supp.supprimer(d);
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
   }
