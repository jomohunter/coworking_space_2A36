#include "reservation.h"
#include <QSqlQueryModel>
#include <QTableView>
#include <QPdfWriter>
#include <QPainter>
#include <QDebug>
#include <QMessageBox>


Reservation::Reservation()
{
id="";
idres0="";
idres="";
espace="";
nbr="";
dated ="";
datef="";

}

void Reservation::setid(QString n){id=n;}
void Reservation::setidres0(QString n){idres0=n;}
void Reservation::setidres(QString n){idres=n;}
//void Reservation::setidcli(QString n){idcli=n;}
void Reservation::setespace(QString n){espace=n;}
void Reservation::setnbr(QString n){nbr=n;}
void Reservation::setdated(QString n){dated=n;}
void Reservation::setdatef(QString n){datef=n;}



QString Reservation::get_id(){
    return id;}
QString Reservation::get_idres0(){
    return idres0;}
QString Reservation::get_idres(){
    return idres;}
//QString Reservation::get_idcli(){
   // return idcli;}
QString Reservation::get_espace(){
    return espace;}
QString Reservation::get_nbr(){
    return nbr;}
QString Reservation::get_dated(){
    return dated;}
QString Reservation::get_datef(){
    return datef;}



bool Reservation::ajouter(){

        QSqlQuery query;
        query.prepare("insert into RESERVATIONS(ID_RESERVATION,ESPACE_LOUE,NB_PERS,DATEDEBUT,DATEFIN)" "values(:idres, :espace, :nbr, :dated, :datef)");
        query.bindValue(":idres",idres);
        //query.bindValue(":idcli",idcli);
        query.bindValue(":espace",espace);
        query.bindValue(":nbr",nbr);
        query.bindValue(":dated",dated);
        query.bindValue(":datef",datef);

        return query.exec();
    }


bool Reservation::supprimer(int idres)
    {
        QSqlQuery query;
        QString res=QString::number(idres);
        query.prepare("delete from RESERVATIONS where ID_RESERVATION= :idres");
        query.bindValue(":idres",res);
        return query.exec();

    }

QSqlQueryModel * Reservation::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel () ;
    model->setQuery("select * from RESERVATIONS");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_RESERVATION"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("ESPACE_LOUE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("NB_PERS"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATEDEBUT"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATEFIN"));
   /* QTableView *t1= new QTableView();;
    t1->setModel(model);
    t1->setSortingEnabled(true);
    t1->sortByColumn(0, Qt::AscendingOrder);
    t1->reset();
    t1->show();
*/


    return model;

}



bool Reservation::modifier(int idres0)
   {


    QSqlQuery query;
    QString res=QString::number(idres0);

    query.prepare("update RESERVATIONS set  ID_RESERVATION=:idres, ESPACE_LOUE=:espace,NB_PERS=:nbr,DATEDEBUT=:dated,DATEFIN=:datef Where ID_RESERVATION=:idres0 ");
    query.bindValue(":idres0",res);

     //int res1=idres.toInt(&ok);


     query.bindValue(":idres", idres);
     query.bindValue(":espace",espace);
     query.bindValue(":nbr", nbr);
     query.bindValue(":dated", dated);
     query.bindValue(":datef", datef);

     return query.exec();
}

QSqlQueryModel*     Reservation::recherche(int id)
{
    QSqlQuery* query = new QSqlQuery();
    QString res11=QString::number(id);

    query->prepare("select * from RESERVATIONS where ID_RESERVATION=:id");
    query->bindValue(":id",res11);
    query->exec();
    QSqlQueryModel * model1=new QSqlQueryModel () ;


   model1->setQuery(*query);
   model1->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_RESERVATION"));
   model1->setHeaderData(1,Qt::Horizontal,QObject::tr("ESPACE_LOUE"));
   model1->setHeaderData(2,Qt::Horizontal,QObject::tr("NB_PERS"));
   model1->setHeaderData(3,Qt::Horizontal,QObject::tr("DATEDEBUT"));
   model1->setHeaderData(4,Qt::Horizontal,QObject::tr("DATEFIN"));
   QTableView* tableView = new QTableView();
   tableView->setModel(model1);

   return model1;
}



QSqlQueryModel *   Reservation::rechercheuid(QString id)
{

    QSqlQuery* query = new QSqlQuery();
    // QString res11=QString::number(id);



    query->prepare("select ESPACE_LOUE from RESERVATIONS where UIDD=:id");
    query->bindValue(":id",id);
    query->exec();
    QSqlQueryModel * model1=new QSqlQueryModel () ;


   model1->setQuery(*query);
   model1->setHeaderData(0,Qt::Horizontal,QObject::tr("La salle"));
   QTableView* tableView = new QTableView();
   tableView->setModel(model1);

   return model1;
/*
     QSqlDatabase bd = QSqlDatabase::database();
     QString nom;
     QSqlQuery query(bd);
     query.prepare("select NOM_CL from CLIENTS where UIDC=:id");
     query.bindValue(":id",id);
     query.exec();
     query.next();

                if(query.next())
            {

                nom=query.value(0).toString();
                QByteArray nom1=query.value(0).toByteArray();
                qDebug() << nom;
                return nom;
            }
            else {
                return " ";
            }
    */
    //QSqlQuery* query = new QSqlQuery();
    // QString res12=id;


    //query->prepare("select NOM_CL from CLIENTS  where UIDC=:res12");
    //query->bindValue(":res12",id);
    //query->exec();
    //QSqlQueryModel * model1=new QSqlQueryModel () ;


   //model1->setQuery(*query);
   //model1->setHeaderData(0,Qt::Horizontal,QObject::tr("NOM_CL"));
   //QTableView* tableView = new QTableView();
   //tableView->setModel(model1);


   //return model1;

    // return r11;

}











QSqlQueryModel*     Reservation::recherche1()
{
    QSqlQuery* query = new QSqlQuery();

    query->prepare("select DATEDEBUT,DATEFIN from RESERVATIONS  where ESPACE_LOUE='Salle 1'");
    query->exec();
    QSqlQueryModel * model1=new QSqlQueryModel () ;


   model1->setQuery(*query);
   model1->setHeaderData(0,Qt::Horizontal,QObject::tr("DATEDEBUT"));
   model1->setHeaderData(1,Qt::Horizontal,QObject::tr("DATEFIN"));
   QTableView* tableView = new QTableView();
   tableView->setModel(model1);

   return model1;
}

QSqlQueryModel*     Reservation::recherche2()
{
    QSqlQuery* query = new QSqlQuery();

    query->prepare("select DATEDEBUT,DATEFIN from RESERVATIONS  where ESPACE_LOUE='Salle 2'");
    query->exec();
    QSqlQueryModel * model1=new QSqlQueryModel () ;


   model1->setQuery(*query);
   model1->setHeaderData(0,Qt::Horizontal,QObject::tr("DATEDEBUT"));
   model1->setHeaderData(1,Qt::Horizontal,QObject::tr("DATEFIN"));
   QTableView* tableView = new QTableView();
   tableView->setModel(model1);

   return model1;
}


QSqlQueryModel*     Reservation::recherche3()
{
    QSqlQuery* query = new QSqlQuery();

    query->prepare("select DATEDEBUT,DATEFIN from RESERVATIONS  where ESPACE_LOUE='Salle 3'");
    query->exec();
    QSqlQueryModel * model1=new QSqlQueryModel () ;


   model1->setQuery(*query);
   model1->setHeaderData(0,Qt::Horizontal,QObject::tr("DATEDEBUT"));
   model1->setHeaderData(1,Qt::Horizontal,QObject::tr("DATEFIN"));
   QTableView* tableView = new QTableView();
   tableView->setModel(model1);

   return model1;
}


QSqlQueryModel*     Reservation::recherche4()
{
    QSqlQuery* query = new QSqlQuery();

    query->prepare("select DATEDEBUT,DATEFIN from RESERVATIONS  where ESPACE_LOUE='Salle 4'");
    query->exec();
    QSqlQueryModel * model1=new QSqlQueryModel () ;


   model1->setQuery(*query);
   model1->setHeaderData(0,Qt::Horizontal,QObject::tr("DATEDEBUT"));
   model1->setHeaderData(1,Qt::Horizontal,QObject::tr("DATEFIN"));
   QTableView* tableView = new QTableView();
   tableView->setModel(model1);

   return model1;
}











QSqlQueryModel * Reservation::triid()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM RESERVATIONS ORDER BY ID_RESERVATION");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_RESERVATION"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("ESPACE_LOUE"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("NB_PERS"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATEDEBUT"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATEFIN"));

     return model;
 }

QSqlQueryModel * Reservation::triespace()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM RESERVATIONS ORDER BY ESPACE_LOUE,ID_RESERVATION");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_RESERVATION"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("ESPACE_LOUE"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("NB_PERS"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATEDEBUT"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATEFIN"));

     return model;
 }

QSqlQueryModel * Reservation::tridate()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM RESERVATIONS ORDER BY DATEDEBUT");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_RESERVATION"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("ESPACE_LOUE"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("NB_PERS"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATEDEBUT"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATEFIN"));

     return model;
 }

void  Reservation::PDF(){

                      QPdfWriter pdf("C:/Users/ilyes/OneDrive/Bureau/exportpdf/PDF.pdf");



                      QPainter painter(&pdf);
                     int i = 4000;



                          painter.setPen(Qt::cyan);
                           painter.setFont(QFont("Haas Grotesk",35,QFont::Bold));
                          painter.drawText(2000,1500,"Reservations");
                          painter.setPen(Qt::black);
                          painter.drawRect(0,2700,9600,500);
                          painter.setFont(QFont("Calibri",14,QFont::Bold));
                          painter.drawText(200,3000,"Id");
                          painter.drawText(1800,3000,"Espace loué");
                          painter.drawText(3100,3000,"Nombre");
                          painter.drawText(4900,3000,"Date debut");
                          painter.drawText(6800,3000,"Date fin");




                          QSqlQuery query;

                          query.prepare("SELECT * FROM RESERVATIONS");
                          query.exec();
                          while (query.next())
                          {
                                 painter.setFont(QFont("Haas Grotesk",13));
                              painter.drawText(200,i,query.value(0).toString());
                              painter.drawText(1800,i,query.value(1).toString());
                              painter.drawText(3200,i,query.value(2).toString());
                              painter.drawText(4900,i,query.value(3).toString());
                              painter.drawText(6900,i,query.value(4).toString());
                              painter.drawText(8600,i,query.value(5).toString());



                             i = i + 500;
                          }}


void  Reservation::Confirmation(int id){

                      QPdfWriter pdf("C:/Users/ilyes/OneDrive/Bureau/exportpdf/Confirmation.pdf");

                      QString res11=QString::number(id);
                      QPainter painter(&pdf);


                      QSqlQuery query;
                      query.prepare("select * from RESERVATIONS where ID_RESERVATION=:id");
                      query.bindValue(":id",res11);
                      query.exec();




                          painter.setPen(Qt::black);
                          painter.setFont(QFont("Haas Grotesk",11,QFont::Bold));
                          painter.drawText(1500,1000,"Madame, Monsieur,");
                          painter.drawText(1500,1500,"Par la présente, je me permets de vous confirmer la réservation de la         ");
                          painter.drawText(1500,2000,"pour      personnes; ");
                          painter.drawText(1500,2500,"pour la période allant du                                   au                                   est confirmée");
                          painter.drawText(1500,3000,"Madame, Monsieur, l'expression de mes salutations les plus distinguées.");




                          while (query.next())
                          {
                                 painter.setFont(QFont("Haas Grotesk",11,QFont::Bold));
                              painter.drawText(1500,500,"Id:  "+query.value(0).toString());
                              painter.drawText(2000,2000,query.value(2).toString());
                              painter.drawText(7900,1500,query.value(1).toString());
                              painter.drawText(3800,2500,query.value(3).toString());
                              painter.drawText(6000,2500,query.value(4).toString());





                          }










//query.exec();
//query1.exec();
}







