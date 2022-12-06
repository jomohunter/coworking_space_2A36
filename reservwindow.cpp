#include "reservwindow.h"
#include "ui_reservwindow.h"
#include "qmessagebox.h"
#include "connection.h"
#include "reservation.h"
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
#include <QDebug>
#include <seriallink.h>


reservwindow::reservwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::reservwindow)
{

    ui->setupUi(this);
    arduino = new seriallink;
    arduino->openConnection();
    connect(arduino , &seriallink::gotNewData, this, &MainWindow::updateGUI );
    QPixmap pixmap("C:/Users/ilyes/OneDrive/Bureau/salle4");
    QIcon ButtonIcon(pixmap);
    ui->mlll->setIcon(ButtonIcon);
    ui->mlll->setIconSize(pixmap.rect().size());
    QPixmap pixmap1("C:/Users/ilyes/OneDrive/Bureau/salle2");
    QPixmap pixmap2("C:/Users/ilyes/OneDrive/Bureau/salle3");
    QIcon ButtonIcon1(pixmap1);
    QIcon ButtonIcon2(pixmap2);
    ui->im2->setIcon(ButtonIcon1);
    ui->im2->setIconSize(pixmap1.rect().size());
    ui->im3->setIcon(ButtonIcon1);
    ui->im3->setIconSize(pixmap1.rect().size());
    ui->s33->setIcon(ButtonIcon2);
    ui->s33->setIconSize(pixmap2.rect().size());
    ui->lm1->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->lm1->setOpenExternalLinks(true);
    ui->lm1->setTextFormat(Qt::RichText);
    ui->lm1->setText( "<a href=\"C:/Users/ilyes/OneDrive/Bureau/exportpdf/Confirmation.pdf/\">Confirmation génerée</a>");

    ui->tableView->setModel(etmp.afficher());
    ui->S1->setChecked(false);
    ui->S2->setChecked(false);
    ui->S3->setChecked(false);
    ui->S4->setChecked(false);
    ui->Nbr->setValidator( new QIntValidator(1,20, this));
    ui->nnbr9->setValidator( new QIntValidator(1,20, this));
    ui->Idres1->setValidator( new QIntValidator(111111,99999, this));
    ui->Idres2->setValidator( new QIntValidator(111111,99999, this));
    ui->nidres9->setValidator( new QIntValidator(111111,99999, this));




}

reservwindow::~reservwindow()
{
    delete ui;
}




void reservwindow::updateGUI(QByteArray data){


    //QString Q1 =QString (data);
    data=data.left(11);
    ui->lcd->display(ui->lcd->value()+data.size());

    ui->rechh->setModel(etmp.rechercheuid(QString(data)));

    //QString x=QString (data);
     //QString res11=etmp.rechercheuid();
    //ui->rechh->setModel(etmp.rechercheuid(QString(data)));
    QString res11 = ui->rechh->model()->data(ui->rechh->indexAt(QPoint(0,0))).toString();
    QString res12="Reserve d'id :"+res11;
    // QString res12=res11.toStdString().c_str();
    //QByteArray x=res11.toUtf8();
    ui->luii->setText(res11);
    ui->yhul->setText(data);


    //res12=res12+"..";
    if (res11!="")
    arduino->write(res11.toUtf8());
    else {
       arduino->write("0");
    }
}




void reservwindow::on_OKBUTT_clicked()
{
        Reservation res;


// ui->datedd->setDisplayFormat("yyyy/MMM/dd");

QTime t1(00, 00);
QDate d1(2022,11,14);

    //get


    res.setidres(ui->Idres1->text());


   res.setdated(ui->datedd->text()+" "+ui->l11->text());
   res.setdatef(ui->dateff->text()+" "+ui->hff->text());










    //Salle deb

    if (ui->S1->isChecked()){res.setespace("Salle 1");}
    else if (ui->S2->isChecked()){res.setespace("Salle 2");}
    else if (ui->S3->isChecked()){res.setespace("Salle 3");}
    else if (ui->S4->isChecked()){res.setespace("Salle 4");}

    //Salle fin

    res.setnbr(ui->Nbr->text());

    bool test=res.ajouter();

    if(test)
    {
        //rafraichir
        ui->tableView->setModel(etmp.afficher());

    }
    else
       { QMessageBox::critical(nullptr, QObject::tr(""),
                    QObject::tr(" Echec de l'ajout"), QMessageBox::Cancel);

 }

    ui->Idres1->setText("");
    ui->Nbr->setText("");
    ui->Idres2->setText("");
    ui->nidres9->setText("");
    ui->nnbr9->setText("");
    ui->sidres->setText("");
    ui->mlk->setText("");
    ui->datedd->setDate(d1);
    ui->dateff->setDate(d1);
    ui->hff->setTime(t1);
    ui->mdatedd->setDate(d1);
    ui->mhd->setTime(t1);
    ui->mdatef->setDate(d1);
    ui->mhf->setTime(t1);
    ui->l11->setTime(t1);
}

void reservwindow::on_pushButton_2_clicked()
{
    int idres=ui->sidres->text().toInt();
    bool test=etmp.supprimer(idres);

    if(test)
    {
        //rafraichir
         ui->tableView->setModel(etmp.afficher());
    }
    else
       { QMessageBox::critical(nullptr, QObject::tr(" "),
                    QObject::tr("Echec de la suppression"), QMessageBox::Cancel);




    }

    QTime t1(00, 00);
    QDate d1(2022,11,14);

    ui->Idres1->setText("");
    ui->Nbr->setText("");
    ui->Idres2->setText("");
    ui->nidres9->setText("");
    ui->nnbr9->setText("");
    ui->sidres->setText("");
    ui->mlk->setText("");
    ui->datedd->setDate(d1);
    ui->dateff->setDate(d1);
    ui->hff->setTime(t1);
    ui->mdatedd->setDate(d1);
    ui->mhd->setTime(t1);
    ui->mdatef->setDate(d1);
    ui->mhf->setTime(t1);
    ui->l11->setTime(t1);

}





void reservwindow::on_Modif_clicked()
{

        Reservation res;

    //get

    int idres0=ui->Idres2->text().toInt();
    res.setidres(ui->nidres9->text());
    res.setdated(ui->mdatedd->text()+" "+ui->mhd->text());
    res.setdatef(ui->mdatef->text()+" "+ui->mhf->text());


    //Salle deb

    if (ui->nS1->isChecked()){res.setespace("Salle 1");}
    else if (ui->nS2->isChecked()){res.setespace("Salle 2");}
    else if (ui->nS3->isChecked()){res.setespace("Salle 3");}
    else if (ui->nS4->isChecked()){res.setespace("Salle 4");}

    //Salle fin

    res.setnbr(ui->nnbr9->text());

    bool test=res.modifier(idres0);

    if(test)
    {
        //rafraichir
        ui->tableView->setModel(etmp.afficher());

    }
    else
       { QMessageBox::critical(nullptr, QObject::tr(" "),
                    QObject::tr("Echec de la modification"), QMessageBox::Cancel);




    }



    QTime t1(00, 00);
    QDate d1(2022,11,14);

    ui->Idres1->setText("");
    ui->Nbr->setText("");
    ui->Idres2->setText("");
    ui->nidres9->setText("");
    ui->nnbr9->setText("");
    ui->sidres->setText("");
    ui->mlk->setText("");
    ui->datedd->setDate(d1);
    ui->dateff->setDate(d1);
    ui->hff->setTime(t1);
    ui->mdatedd->setDate(d1);
    ui->mhd->setTime(t1);
    ui->mdatef->setDate(d1);
    ui->mhf->setTime(t1);
    ui->l11->setTime(t1);

}

void reservwindow::on_pushButton_4_clicked()
{

   Reservation res;
   int id;
   id=ui->mlk->text().toInt();

       ui->tab_rech->setModel(etmp.recherche(id));




       QTime t1(00, 00);
       QDate d1(2022,11,14);

       ui->Idres1->setText("");
       ui->Nbr->setText("");
       ui->Idres2->setText("");
       ui->nidres9->setText("");
       ui->nnbr9->setText("");
       ui->sidres->setText("");
       ui->mlk->setText("");
       ui->datedd->setDate(d1);
       ui->dateff->setDate(d1);
       ui->hff->setTime(t1);
       ui->mdatedd->setDate(d1);
       ui->mhd->setTime(t1);
       ui->mdatef->setDate(d1);
       ui->mhf->setTime(t1);
       ui->l11->setTime(t1);
}


void reservwindow::on_pushButton_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
           model->setQuery("select * from RESERVATIONS where NB_PERS between 4 and 8");
           float dispo1=model->rowCount();

           model->setQuery("select * from RESERVATIONS where 4 > NB_PERS  ");
           float dispo=model->rowCount();

           model->setQuery("select * from RESERVATIONS where NB_PERS >= 8  ");
           float dispo3=model->rowCount();

           float total=dispo1+dispo+dispo3;
               QString a=QString("Groupe moyen (Nombre entre 4 et 8)  " +QString::number((dispo1*100)/total,'f',2)+"%" );
               QString b=QString("Petit groupe (Nombre inférieur à 4)  " +QString::number((dispo*100)/total,'f',2)+"%" );
               QString c=QString("Groupe de réunion (Nombre supérieur à 8)  " +QString::number((dispo3*100)/total,'f',2)+"%" );
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
           chart->setTitle("Nombre d'échantillons : "+ QString::number(total));



           QChartView *chartView = new QChartView(chart);
           chartView->setRenderHint(QPainter::Antialiasing);
           chartView->resize(1300,800);
           chartView->show();
}

void reservwindow::on_Salles_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
           model->setQuery("select * from RESERVATIONS where ESPACE_LOUE = 'Salle 1'");
           float dispo1=model->rowCount();

           model->setQuery("select * from RESERVATIONS where ESPACE_LOUE = 'Salle 2'");
           float dispo=model->rowCount();

           model->setQuery("select * from RESERVATIONS where ESPACE_LOUE = 'Salle 3'");
           float dispo3=model->rowCount();

           model->setQuery("select * from RESERVATIONS where ESPACE_LOUE = 'Salle 4'");
           float dispo4=model->rowCount();


           float total=dispo1+dispo+dispo3+dispo4;
               QString a=QString("Salle 1  " +QString::number((dispo1*100)/total,'f',2)+"%" );
               QString b=QString("Salle 2  " +QString::number((dispo*100)/total,'f',2)+"%" );
               QString c=QString("Salle 3  " +QString::number((dispo3*100)/total,'f',2)+"%" );
               QString d=QString("Salle 4  " +QString::number((dispo4*100)/total,'f',2)+"%" );
               QPieSeries *series = new QPieSeries();
               series->append(a,dispo1);
               series->append(b,dispo);
               series->append(c,dispo3);
               series->append(d,dispo4);
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
           if (dispo4!=0)
           {QPieSlice *slice = series->slices().at(3);
               slice->setLabelVisible();
               slice->setPen(QPen());}

           QChart *chart = new QChart();


           chart->addSeries(series);
           chart->setTitle("Nombre d'échantillons : "+ QString::number(total));



           QChartView *chartView = new QChartView(chart);
           chartView->setRenderHint(QPainter::Antialiasing);
           chartView->resize(1300,800);
           chartView->show();
}

void reservwindow::on_pushButton_3_clicked()
{
    if (ui->comboBox->currentText()=="Id")
    {ui->tableView->setModel(etmp.triid());}
    if (ui->comboBox->currentText()=="Espace loué")
    {
        ui->tableView->setModel(etmp.triespace());
}
   if (ui->comboBox->currentText()=="Date")
 {ui->tableView->setModel(etmp.tridate());}

}















void reservwindow::on_pushButton_5_clicked()
{
    etmp.PDF();







                QMessageBox::information(nullptr,QObject::tr(" "),



                           QObject::tr("Fichier prêt !"), QMessageBox::Cancel);
}



void reservwindow::on_s33_clicked()
{
 ui->t17->setModel(etmp.recherche4()) ;
}

void reservwindow::on_im3_clicked()
{
    //QTableView* tableView = new QTableView();
    //tableView->setModel(model1);
    ui->t17->setModel(etmp.recherche1()) ;
}

void reservwindow::on_im2_clicked()
{
    ui->t17->setModel(etmp.recherche2()) ;
}

void reservwindow::on_mlll_clicked()
{
    ui->t17->setModel(etmp.recherche3()) ;
}

void reservwindow::on_conf_clicked()
{
    Reservation res;
    int id;
    id=ui->p11->text().toInt();
    etmp.Confirmation(id);







                QMessageBox::information(nullptr,QObject::tr(" "),



                           QObject::tr("Confirmé!"), QMessageBox::Cancel);

ui->p11->clear();
}



/*void MainWindow::on_ledoff_clicked()
{
    if (arduino->isWritable())
        arduino->write("n");
    else qDebug() <<"Cant ";
}
*/
