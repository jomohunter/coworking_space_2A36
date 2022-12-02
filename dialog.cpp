#include "dialog.h"
#include "ui_dialog.h"
#include "equip.h"
ahmed::ahmed(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    popUp = new PopUp();

}

ahmed::~ahmed()
{
    delete ui;
}


void ahmed::on_buttonBox_accepted()
{
    /*

    Equip E;
    QString k = nom + quantite;
    */

    QString nom = ui->lineEdit->text();
    QString quantite = ui->lineEdit_2->text();

    popUp->setPopupText("Reclamation : \n"+ nom + "\n" + quantite);

   popUp->show();
}

