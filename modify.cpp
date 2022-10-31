#include "modify.h"
#include "ui_modify.h"
#include "qmessagebox.h"


modify::modify(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modify)
{
    ui->setupUi(this);
}

modify::~modify()
{
    delete ui;
}


void modify::on_pushButton_2_clicked()
{
    QString nom = ui->nameLineEdit->text();
    int qt = ui->quantitySpinBox->value();
    QString type = ui->typeLineEdit->text();
    QString localisation = ui->localisationComboBox->currentText();
    int id = ui->iDLineEdit->text().toInt();

    Equipment e(nom,qt,type,localisation,id);
    bool test_modify = e.modify(id,type ,nom,localisation,qt);
    if (test_modify)
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                                 QObject::tr("DONE.\nClick Cancel to exit."), QMessageBox::Ok);
    }
    else
    { QMessageBox::information(nullptr, QObject::tr("database is not open"),
                            QObject::tr("NOT DONE.\nClick Cancel to exit."), QMessageBox::Ok);

    }
}

void modify::on_ADD_accepted()
{
    QString nom = ui->nameLineEdit->text();
    int qt = ui->quantitySpinBox->value();
    QString type = ui->typeLineEdit->text();
    QString localisation = ui->localisationComboBox->currentText();
    int id = ui->iDLineEdit->text().toInt();

    Equipment e(nom,qt,type,localisation,id);
    bool test_modify = e.modify(id,type ,nom,localisation,qt);
    if (test_modify)
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                                 QObject::tr("DONE.\nClick Cancel to exit."), QMessageBox::Ok);
    }
    else
    { QMessageBox::information(nullptr, QObject::tr("database is not open"),
                            QObject::tr("NOT DONE.\nClick Cancel to exit."), QMessageBox::Ok);

    }
}
