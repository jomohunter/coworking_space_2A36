#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"
#include "connection.h"
#include "employe.h"
#include <QIntValidator>
#include <QTableView>
#include <QMessageBox>
#include <QPixmap>
#include<QPrinter>
#include<QPainter>
#include<QPrintDialog>
#include <QPrintPreviewDialog>
#include <QPdfWriter>
#include <QtCharts>
#include <QDesktopServices>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QPieSlice>
#include <QPieSeries>
#include <QChartView>
#include "smtp.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->le_id->setValidator( new QIntValidator(111111,999999, this));
    ui->le_salaire->setValidator( new QIntValidator(111111,99999, this));
    ui->le_prenom->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
    ui->le_nom_2->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
    ui->le_poste->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
    ui->tableView->setModel(E.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pb_Ajouter_clicked()
{
    int id=ui->le_id->text().toInt();
        QString nom=ui->le_nom_2->text();
        QString prenom=ui->le_prenom->text();
        QString poste=ui->le_poste->text();
 int salaire=ui->le_salaire->text().toInt();
employe  E(id,nom,prenom,poste,salaire);
    bool test=E.ajouter();
    if(test)
    {//refresh
        ui->tableView->setModel(E.afficher());
        ui->le_nom_2->text().clear();
        ui->le_id->text()="";
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Ajout effectue\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                    QObject::tr("Ajout non effectue.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}



void MainWindow::on_pb_Supprimer_clicked()
{
 //int id =ui->le_id->text().toInt();
 E.setId(ui->le_supprimer->text().toInt());
 bool test=E.supprimer(E.getId());


 if(test)
 {

     QMessageBox::information(nullptr, QObject::tr("Suppression"),
                 QObject::tr("Suppression effectué.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
 ui->tableView->setModel(E.afficher());
 }
 else
     QMessageBox::critical(nullptr, QObject::tr("Suppression"),
                 QObject::tr("OUPS, Suppression non effectué.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);



}





void MainWindow::on_pb_Modifier_clicked()
{     E.clearTable(ui->tableView);

    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom_2->text();
    QString prenom=ui->le_prenom->text();
    QString poste=ui->le_poste->text();
int salaire=ui->le_salaire->text().toInt();
  employe E(id,nom,prenom,poste,salaire);

 bool test=E.modifier(id,nom,prenom,poste,salaire);
    if(test)
    {
        ui->tableView->setModel(E.afficher());

        QMessageBox::information(nullptr, QObject::tr("Modification"),
                    QObject::tr("La modification est effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(E.afficher());


}
    else
        QMessageBox::critical(nullptr, QObject::tr("Modification"),
                    QObject::tr("OUPS, La modification n'a pas été effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_le_nomtri_clicked()
{
    ui->tableView->setModel(E.tri_nom());

}

void MainWindow::on_le_idtri_clicked()
{
  ui->tableView->setModel(E.tri_id());
}

void MainWindow::on_le_salairetri_clicked()
{
    ui->tableView->setModel(E.tri_salaire());
}

void MainWindow::on_pb_PDF_clicked()
{
    QPdfWriter pdf("C:/Users/user/OneDrive/Bureau/gestion_employes/Liste.pdf");

       QPainter painter(&pdf);

       int i = 4000;
       painter.setPen(Qt::black);
       painter.setFont(QFont("Konztante", 30));
       painter.drawPixmap(QRect(100,400,2000,2000),QPixmap("C:/Users/user/OneDrive/Bureau/gestion_employes/cowrkinggg.png"));
       painter.drawText(3000,1500,"LISTE DES EMPLOYES");
       painter.setPen(Qt::black);
       painter.setFont(QFont("Konztante", 50));
       painter.setPen(Qt::black);
       painter.setFont(QFont("Konztante", 9));
       painter.drawText(300,3300,"ID");
       painter.drawText(2300,3300,"Nom");
       painter.drawText(4300,3300,"Prenom");
       painter.drawText(6000,3300,"Poste");
       painter.drawText(8300,3300,"Salaire");
       QSqlQuery query;
       query.prepare("select * from EMPLOYES");
       query.exec();
       while (query.next())
       {
           painter.drawText(300,i,query.value(0).toString());
           painter.drawText(2300,i,query.value(1).toString());
           painter.drawText(4300,i,query.value(2).toString());
           painter.drawText(6300,i,query.value(3).toString());
           painter.drawText(8000,i,query.value(4).toString());
           i = i +500;
       }

       int reponse = QMessageBox::question(this, "PDF généré", "Afficher le PDF ?", QMessageBox::Yes |  QMessageBox::No);
       if (reponse == QMessageBox::Yes)
       {
           QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/user/OneDrive/Bureau/gestion_employes/Liste.pdf"));

           painter.end();
       }
       if (reponse == QMessageBox::No)
       {
           painter.end();
       }
}



/*void MainWindow::on_le_recherche_clicked()
{

     E.clearTable(ui->tableView);
     int id=ui->le_supprimer->text().toInt();
       E.rechercher(ui->tableView,id);
       //E.afficher();

}*/





void MainWindow::on_stat_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
       model->setQuery("select * from EMPLOYES where SALAIRE_EMP >= 1000");
       float dispo1=model->rowCount();

       model->setQuery("select * from EMPLOYES where SALAIRE_EMP <1000");
       float dispo=model->rowCount();

       float total=dispo1+dispo;
           QString a=QString("Salaire plus de 1000 ," +QString::number((dispo1*100)/total,'f',2)+"%" );
           QString b=QString("Salaire moins de 1000 ,"+QString::number((dispo*100)/total,'f',2)+"%" );
           QPieSeries *series = new QPieSeries();
           series->append(a,dispo1);
           series->append(b,dispo);
       if (dispo1!=0)
       {QPieSlice *slice = series->slices().at(0);
           slice->setLabelVisible();
           slice->setPen(QPen());}
       if ( dispo!=0)
       {
           QPieSlice *slice1 = series->slices().at(1);
           slice1->setLabelVisible();
       }

       QChart *chart = new QChart();


       chart->addSeries(series);
       chart->setTitle("Salaire des employes :Nombre d'employes: "+ QString::number(total));



       QChartView *chartView = new QChartView(chart);
       chartView->setRenderHint(QPainter::Antialiasing);
       chartView->resize(1000,500);
       chartView->show();

}






void MainWindow::on_le_supprimer_textChanged(const QString &arg1)
{
    ui->le_supprimer->setValidator( new QIntValidator(0, 999999, this));
     if(ui->le_supprimer->text()!="")
     {
       QString CIN=ui->le_supprimer->text();
       ui->tableView->setModel(E.rechercher(CIN));
     }
     else
      ui->tableView->setModel(E.afficher());
}



void MainWindow::on_pushButton_envoyer_clicked()
{
    Smtp* smtp = new Smtp("rania.khedri@esprit.tn", "211JMT8822", "smtp.gmail.com", 465);


        connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


        QString a=ui->LE_Destinataire->text();


        QString b=ui->LE_Objet->text();


        QString c=ui->msq->text();




        smtp->sendMail("rania.khedri@esprit.tn",a,b,c);
}
