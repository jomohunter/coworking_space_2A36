#include "dialog.h"
#include "ui_dialog.h"
#include "equipment.h"
#include "mainwindow.h"
#include "QMessageBox"
#include <bits/stdc++.h>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_ADD_accepted()
{
    QString name = ui->nameLabel->text();

    int qt = ui->quantitySpinBox->value();

   QString type = ui->typeLabel->text();

    QString localisation = ui->localisationComboBox->currentText();

   int id = ui->iDLabel->text().toInt();

    Equipment e(name,qt,type,localisation,id);
    bool test = e.ajouter(name,type,localisation,id,qt);

    if(test)
        {

        QMessageBox::information(nullptr, QObject::tr("database is open"),
                                     QObject::tr("Ajout avec succés.\nClick Cancel to exit."), QMessageBox::Ok);

        }
        else
        {
        QMessageBox::information(nullptr, QObject::tr("database is not open"),
                                QObject::tr("Ajout échoué.\nClick Cancel to exit."), QMessageBox::Ok);
        }
}
