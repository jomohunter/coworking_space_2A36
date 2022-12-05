#include "pdf.h"
#include "ui_pdf.h"
#include"equip.h"
#include"equipwindow.h"
#include<QPdfWriter>
#include<QMessageBox>
#include<QPainter>
#include<QDesktopServices>
#include<QUrl>

pdf::pdf(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pdf)
{
    ui->setupUi(this);
}

pdf::~pdf()
{
    delete ui;
}

void pdf::on_pushButton_clicked() // pdf //
{
    QPdfWriter pdf("C:/Users/maghr/OneDrive/Desktop/mario.pdf");
    QPainter painter(&pdf);
    painter.setPen(Qt::red);
    QString id = ui->line_pdf->text();
    QSqlQuery test ;
    test.prepare("SELECT COUNT(*) from EQUIPEMENTS where ID_EQUIP= :id");
    test.bindValue(":id",id);
    test.exec();
    if (test.next())
    {
  if (test.value(0).toInt() == 1)
  {
    QSqlQuery query ;
    query.prepare("select ID_EQUIP, TYPE_MAT, NOM_MAT, LOCAL, QTEEQUIP from EQUIPEMENTS where ID_EQUIP= :id");
    query.bindValue(":id",id);
    query.exec();
    if (query.next())
    {
    QString ident = query.value(0).toString();
    QString type = query.value(1).toString();
    QString nom = query.value(2).toString();
    QString local = query.value(3).toString();
    QString qt = query.value(4).toString();
    painter.drawText(100,300,"successfully export to PDF");
    painter.drawText(100,500,"identifiant: ");
     painter.setPen(Qt::black);
    painter.drawText(750,500,ident);
    painter.drawText(100,700,nom);
    painter.drawText(100,900,type);
    painter.drawText(100,1100,local);
    painter.drawText(100,1300,qt);
    painter.end();
    QMessageBox::information(nullptr, QObject::tr("OK"),
                            QObject::tr("pdf done.\n"
                                         "Click ok to exit."), QMessageBox::Ok);
    }
 }
  else
  {
      QMessageBox::information(nullptr, QObject::tr("OK"),
                              QObject::tr("pdf not done.\n"
                                          "Click ok to exit."), QMessageBox::Ok);
  }
  }
}
