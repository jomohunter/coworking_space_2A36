#include "inter_spon.h"
#include "ui_inter_spon.h"
#include<QtDebug>
#include <QLabel>
#include <QPixmap>
#include<QDebug>
#include <QRadioButton>
#include<QtPrintSupport/QPrinter>
#include<QPdfWriter>
#include <QPainter>
#include<QFileDialog>
#include<QTextDocument>
#include <QTextEdit>
#include <QtSql/QSqlQueryModel>
#include<QtPrintSupport/QPrinter>
#include <QValidator>
#include <QPrintDialog>
#include<QtSql/QSqlQuery>
#include<QVariant>
#include "statistique.h"
#include <QDateTime>

inter_spon::inter_spon(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::inter_spon)
{
    ui->setupUi(this);
    ui->tableView->setModel(s.afficher_Sponsor());
    int ret=A.connect_arduino();
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));


}

inter_spon::~inter_spon()
{
    delete ui;
}

void inter_spon::update_label()
{
    data=A.read_from_arduino();
    bool test = false;

qDebug() << data;
if (data=="D")
{
    QSqlQuery query;

    QString id = ui->forarduino->text();

    query =s.request(id);
    if(query.exec())
    {
        while(query.next())
        {

            test=true;

        }
    }
    if(test)
    {
        A.write_to_arduino("1");

        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("l'id existe"), QMessageBox::Cancel);

    }
    else
    {
         A.write_to_arduino("2");
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("l'id n'existe pas"), QMessageBox::Cancel);

    }


}
else
    ui->forarduino->setText(ui->forarduino->text()+data);



}

void inter_spon::on_pushButton_ajouter_2_clicked()
{
    int ID_spon=ui->lineEdit_ID_2->text().toInt();
       QString Nom_spon=ui->lineEdit_nom_2->text();
       QString Prenom_spon=ui->lineEdit_prenom_2->text();
       int Montant_payes=ui->lineEdit_Montant_2->text().toInt();
      QString Phone=ui->lineEdit_phone_2->text();
      QString Email_spon=ui->lineEdit_email_2->text();

     Sponsor S(ID_spon,Nom_spon,Prenom_spon,Montant_payes,Phone,Email_spon);

  bool test= S.ajouter_Sponsor();
  if (test)
{
 ui->tableView->setModel(S.afficher_Sponsor());


 QMessageBox::information(nullptr, QObject::tr("OK"),
                          QObject::tr("Ajout effectue.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
}
else

QMessageBox::critical(nullptr, QObject::tr("Not OK"),
               QObject::tr("Ajout non effectue.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
}

void inter_spon::on_tableView_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
        QString sQuery="SELECT ID_SPON,NOM_SPON,PRENOM_SPON,MONTANT_PAYES,EMAIL_SPON,PHONE FROM GS_SPONSORS WHERE ID_SPON='"+val+"' or NOM_SPON='"+val+"' or PRENOM_SPON='"+val+"' or MONTANT_PAYES='"+val+"' or EMAIL_SPON='"+val+"' or PHONE='"+val+"'";
        QSqlQuery qry;
        qry.prepare(sQuery);

        if(qry.exec()){
            while(qry.next())
            {
                ui->label_cin->setText(qry.value(0).toString());
                ui->lineEdit_nom_2->setText(qry.value(1).toString());
                ui->lineEdit_prenom_2->setText(qry.value(2).toString());
                ui->lineEdit_Montant_2->setText(qry.value(3).toString());
                ui->lineEdit_email_2->setText(qry.value(4).toString());
                ui->lineEdit_phone_2->setText(qry.value(5).toString());

            }
        }
        else{
            QMessageBox::critical(nullptr, QObject::tr("sql query unsuccessful"),
                               QObject::tr("row not shown.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
        }
}

void inter_spon::on_pushButton_afficher_clicked()
{
    ui->tableView->setModel(s.afficher_Sponsor());

}

void inter_spon::on_pushButton_modifier_2_clicked()
{
    int ID_spon=ui->label_cin->text().toInt();
       QString Nom_spon=ui->lineEdit_nom_2->text();
       QString Prenom_spon=ui->lineEdit_prenom_2->text();
       int Montant_payes=ui->lineEdit_Montant_2->text().toInt();
        QString Telephone_spon=ui->lineEdit_phone_2->text();
       QString Mail_spon=ui->lineEdit_email_2->text();



     Sponsor S(ID_spon,Nom_spon,Prenom_spon,Montant_payes,Telephone_spon,Mail_spon);

    bool test=S.modifier_Sponsor();
    if (test)
  {
   ui->tableView->setModel(S.afficher_Sponsor());


   QMessageBox::information(nullptr, QObject::tr("OK"),
                            QObject::tr("modification effectue.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
  }
  else

  QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                 QObject::tr("modification non effectue.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

}

void inter_spon::on_pushButton_supprimer_clicked()
{
    Sponsor S;
      int id=ui->label_cin->text().toInt();
      //S.supprimer(id);
      s.archiversponsor(id);
      ui->tableView->setModel(S.afficher_Sponsor());
      QDateTime date = QDateTime::currentDateTime();
      QString formattedTime = date.toString("dd.MM.yyyy");
        s.setdatasupp(id,formattedTime);

}




void inter_spon::on_lineEdit_prenomcher_cursorPositionChanged(int arg1, int arg2)
{

            QString inputValue,filtrerChecked;
                    inputValue=ui->lineEdit_prenomcher->text();
                    ui->tableView->setModel(s.rechercherdynamique(inputValue,"Prenom_spon"));
}

void inter_spon::on_comboBox_activated(const QString &arg1)
{

    if (arg1=="Prénom")
    {

     ui->tableView->setModel(s.afficher_Sponsor_trie_prenom());
     ui->tableView->show();
    }
   else if (arg1=="Nom")
    {

     ui->tableView->setModel(s.afficher_Sponsor_trie_nom());
     ui->tableView->show();
    }


}

void inter_spon::on_pushButton_clicked()
{
    QString rech =ui->lineEdit_chercher->text();
    ui->tableView->setModel(s.chercher_Sponsor(rech));
}


void inter_spon::on_pushButton_2_clicked()
{
    QString strStream;
    QTextStream out(&strStream);

     const int rowCount = ui->tableView->model()->rowCount();
     const int columnCount = ui->tableView->model()->columnCount();
    out <<  "<html>\n"
    "<head>\n"
                     "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                     <<  QString("<title>%1</title>\n").arg("strTitle")
                     <<  "</head>\n"
                     "<body bgcolor=#ffffff link=#5000A0>\n"

                    //     "<align='right'> " << datefich << "</align>"
                     "<center> <H1>Liste des Sponsors </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                 // headers
                 out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                 for (int column = 0; column < columnCount; column++)
                     if (!ui->tableView->isColumnHidden(column))
                         out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
                 out << "</tr></thead>\n";

                 // data table
                 for (int row = 0; row < rowCount; row++) {
                     out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                     for (int column = 0; column < columnCount; column++) {
                         if (!ui->tableView->isColumnHidden(column)) {
                             QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                             out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                         }
                     }
                     out << "</tr>\n";
                 }
                 out <<  "</table> </center>\n"
                     "</body>\n"
                     "</html>\n";

           QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
             if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

            QPrinter printer (QPrinter::PrinterResolution);
             printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setPaperSize(QPrinter::A4);
           printer.setOutputFileName(fileName);

            QTextDocument doc;
             doc.setHtml(strStream);
             doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
             doc.print(&printer);
}

void inter_spon::on_pushButton_3_clicked()
{
    ui->tableView->setModel(s.afficher_Sponsor_numero());
    ui->tableView->show();
}

void inter_spon::on_pushButton_4_clicked()
{
    int ID_spon=ui->label_cin->text().toInt();
         s.archiversponsor(ID_spon);
         ui->tableView->setModel(s.afficher_Sponsor());
         ui->tableView->show();
}

void inter_spon::on_pushButton_5_clicked()
{

         ui->tableView->setModel(s.afficher_Sponsor_historique());
         ui->tableView->show();
}



void inter_spon::on_pushButton_6_clicked()
{
    Statistique s;
    s.exec();
}

void inter_spon::on_lineEdit_chercher_cursorPositionChanged(int arg1, int arg2)
{
    QString inputValue,filtrerChecked;
            inputValue=ui->lineEdit_chercher->text();
            ui->tableView->setModel(s.rechercherdynamique(inputValue,"Nom_spon"));
}

void inter_spon::on_pushButton_supprimer_2_clicked()
{  Sponsor S;
    int id=ui->label_cin->text().toInt();
    S.supprimer(id);
    ui->tableView->setModel(S.afficher_Sponsor_historique());


}
