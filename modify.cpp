#include "modify.h"
#include "ui_modify.h"
#include "equipwindow.h"
#include "equip.h"
#include "QMessageBox"

modify::modify(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modify)
{
    ui->setupUi(this);
    ui->table_modify->setModel(e.Afficher());

    qDebug()<<"start";
}

modify::~modify()
{
    delete ui;
}
void modify::on_pushButton_clicked()
{
    QString id = ui->line_id_m->text();
    QString nom = ui->line_nom_m->text();
    QString type = ui->line_t_m->text();
    QString local = ui->combo_s_m->currentText();
    int qt = ui->line_q_m->text().toInt();
    int NUMF = ui->line_nom_m_2->text().toInt();
    Equip e(id, nom, type, local, qt, NUMF);
    bool test_modify = e.Modifier(id, nom, type, local, qt);
    if (test_modify)
    {
        ui->table_modify->setModel(e.Afficher());
        QMessageBox::information(nullptr, QObject::tr("YESS :)"),
                                 QObject::tr("DONE.\nClick Cancel to exit."), QMessageBox::Ok);
    }
    else
    { QMessageBox::information(nullptr, QObject::tr("SORRY -_-"),
                            QObject::tr("NOT DONE.\nClick Cancel to exit."), QMessageBox::Ok);
    qDebug() << "test";
    }
}

