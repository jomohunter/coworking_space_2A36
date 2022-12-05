#include "inter_fournisseur.h"
#include "ui_inter_fournisseur.h"
#include "qmessagebox.h"
#include "fournisseurs.h"
#include "connection.h"
#include "notification.h"
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

inter_fournisseur::inter_fournisseur(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::inter_fournisseur)
{
    ui->setupUi(this);
    ui->tableView->setModel(etmp.afficher());
    int ret=A.connect_arduino(); // lancer la connexion à arduino
                switch(ret){
                case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
                    break;
                case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
                   break;
                case(-1):qDebug() << "arduino is not available";
                }
                /*
                 QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
                 //le slot update_label suite à la reception du signal readyRead (reception des données).
                 //A.write_to_arduino("0");
                 A.read_from_arduino();
                 QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label2())); // permet de lancer
                 //le slot update_label suite à la reception du signal readyRead (reception des données).
                 //A.write_to_arduino("0");
                 A.read_from_arduino();
                */

}

inter_fournisseur::~inter_fournisseur()
{
    delete ui;
}

void inter_fournisseur::update_label()
{

}
void inter_fournisseur::update_label2()
{

}
void inter_fournisseur::on_pushButton_5_clicked()
{

        //int val=test1.toInt(&num);

        fournisseurs f;





        //get lines


    f.setID(ui->lineEdit_5->text());
    f.setNom(ui->lineEdit->text());
    f.setType(ui->lineEdit_2->text());
    f.setDateD(ui->lineEdit_6->text());
    f.setDateF(ui->lineEdit_7->text());
    bool test=f.ajouter();
    //refresh tab viwer




    if(test)
    {
        N.notification_ajoutfournisseurs();
       ui->tableView->setModel(etmp.afficher());



    }
}


void inter_fournisseur::on_pushButton_3_clicked()
{
    int ID=ui->lineEdit_5->text().toInt();
    bool test=etmp.supprimer(ID);

    if(test)
    {
        N.notification_supprimerfournisseurs();
        ui->tableView->setModel(etmp.afficher())
;

    }
}

void inter_fournisseur::on_radioButton_clicked()
{
    ui->tableView->setModel(etmp.trieID());
}

void inter_fournisseur::on_radioButton_2_clicked()
{
    ui->tableView->setModel(etmp.trieNom());
}

void inter_fournisseur::on_radioButton_3_clicked()
{
    ui->tableView->setModel(etmp.trieType());
}

void inter_fournisseur::on_lineEdit_11_textChanged(const QString &arg1)
{
    QString rech = ui->lineEdit_11->text();

                         etmp.recherche(ui->tableView,rech);

                         if (ui->lineEdit_11->text().isEmpty())

                         {

                             ui->tableView->setModel(etmp.afficher());
                             A.write_to_arduino("1");

                                 }


else{
          A.write_to_arduino("2");
    }
}

void inter_fournisseur::on_pushButton_6_clicked()
{
    etmp.telechargerPDF();



            QMessageBox::information(nullptr,QObject::tr("OK"),

                       QObject::tr("Téléchargement terminé"), QMessageBox::Cancel);

}


void inter_fournisseur::on_pushButton_4_clicked()
{
    fournisseurs res;
        int num=ui->lineEdit_8->text().toInt() ;
        res.setID(ui->lineEdit_5->text());
        res.setNom(ui->lineEdit->text());
        res.setType(ui->lineEdit_6->text());
        res.setDateD(ui->lineEdit_2->text());
        res.setDateF(ui->lineEdit_7->text());
        bool test=res.modifier(num);
        if(test)
        {
             N.notification_modifierfournisseurs();
            ui->tableView->setModel(etmp.afficher());
        }
}

void inter_fournisseur::on_pushButton_7_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
                   model->setQuery("select * from FOURNISSEURS where TYPE_FOUR = 'grossistes'");
                   float dispo1=model->rowCount();

                   model->setQuery("select * from FOURNISSEURS where TYPE_FOUR = 'entreprises'");
                   float dispo=model->rowCount();

                   model->setQuery("select * from FOURNISSEURS where TYPE_FOUR = 'détaillants'");
                   float dispo3=model->rowCount();

                   float total=dispo1+dispo+dispo3;
                       QString a=QString("grossistes " +QString::number((dispo1*100)/total,'f',2)+"%" );
                       QString b=QString("entreprises  " +QString::number((dispo*100)/total,'f',2)+"%" );
                       QString c=QString("détaillants  " +QString::number((dispo3*100)/total,'f',2)+"%" );
                       QPieSeries *series = new QPieSeries();
                       series->append(a,dispo1);
                       series->append(b,dispo);
                       series->append(c,dispo3);
                   if (dispo1!=0)
                   {QPieSlice *slice = series->slices().at(0);
                       slice->setLabelVisible();
                       slice->setPen(QPen());}
                   if ( dispo!=0)
                   {
                       QPieSlice *slice1 = series->slices().at(1);
                       slice1->setLabelVisible();
                       slice1->setPen(QPen());
                   }
                   if (dispo3!=0)
                   {QPieSlice *slice = series->slices().at(2);
                       slice->setLabelVisible();
                       slice->setPen(QPen());}

                   QChart *chart = new QChart();


                   chart->addSeries(series);
                   chart->setTitle("Nombre: "+ QString::number(total));



                   QChartView *chartView = new QChartView(chart);
                   chartView->setRenderHint(QPainter::Antialiasing);
                   chartView->resize(1300,800);
                   chartView->show();
}

void inter_fournisseur::on_pushButton_8_clicked()
{
    QString nomFile="fichier excel ";
                QMessageBox msg;
                if(!nomFile.length()){

                    msg.setText("entrer le nom du fichier");
                    msg.exec();
                }
                else{
                QFile file("C:/Users/iyadh/OneDrive/Bureau/"+nomFile+".csv");
                QString finalmsg="fichier modifie avec succes";
                 if(!file.exists()){
                 finalmsg="fichier cree avec succes";
                 }
                file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);

                QTextStream txt(&file);
                txt<<"Id \t\t                  Nom \t\t                 Type \t\t                 dateD \t\t                  dateF    \n";

                for(int i=0;i<4;i++){

                QString ID= ui->tableView->model()->index(i,0).data().toString();
                QString Nom= ui->tableView->model()->index(i,1).data().toString();
                QString Type= ui->tableView->model()->index(i,2).data().toString();
                QString DateD= ui->tableView->model()->index(i,3).data().toString();
                QString DateF= ui->tableView->model()->index(i,4).data().toString();


                if(ID.length()){

                txt<< "'"+ ID +"' \t";
                txt<< "           '"+ Nom +"' \t";
                txt<< "             '"+ Type +"' \t";
                txt<< "             '"+ DateD +"' \t";
                txt<< "             '"+ DateF +"' \n";

                }
                }
                msg.setText(finalmsg);
                msg.exec();
                file.close();
                }
}

