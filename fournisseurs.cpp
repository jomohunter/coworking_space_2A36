#include "fournisseurs.h"
#include<QPdfWriter>
#include<QPainter>
fournisseurs::fournisseurs()
{
      ID="";
     Nom="";
    Type="";
   DateD="";
   DateF="";
     num="";

}
void fournisseurs::setID(QString n){ID=n;}
void fournisseurs::setNom(QString n){Nom=n;}
void fournisseurs::setType(QString n){Type=n;}
void fournisseurs::setDateD(QString n){DateD=n;}
void fournisseurs::setDateF(QString n){DateF=n;}

QString fournisseurs::get_ID(){return ID;}
QString fournisseurs::get_Nom(){return Nom;}
QString fournisseurs::get_Type(){return Type;}
QString fournisseurs::get_DateD(){return DateD;}
QString fournisseurs::get_DateF(){return DateF;}
QString fournisseurs::get_num(){return num;}


bool fournisseurs::ajouter(){
    QSqlQuery query;//prep un vr pour cmn sql
    query.prepare("insert into FOURNISSEURS(ID_FOUR,NOM_FOUR,TYPE_FOUR,DATEDEBC,DATEFINC)" "values(:ID, :Nom, :Type, :DateD, :DateF)");
    query.bindValue(":ID",ID);
    query.bindValue(":Nom",Nom);
    query.bindValue(":DateD",Type);
    query.bindValue(":Type",DateD);
    query.bindValue(":DateF",DateF);    
    return query.exec();
}
    //QSqlQueryModel * fournisseurs
bool fournisseurs::supprimer(int ID)
    {
        QSqlQuery query;
        QString res=QString::number(ID);
        query.prepare("delete from FOURNISSEURS where ID_FOUR= :ID");
        query.bindValue(":ID",res);
        return query.exec();

    }
QSqlQueryModel * fournisseurs::afficher()
    {
        QSqlQueryModel * model=new QSqlQueryModel();
        model->setQuery("select * from FOURNISSEURS");//model=tab bd
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_FOUR"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_FOUR"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE_FOUR"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATEDEBC"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATEFINC"));
        return model;


    }
QSqlQueryModel * fournisseurs::trieID()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM FOURNISSEURS ORDER BY ID_FOUR");
     model->setHeaderData(0, Qt::Horizontal,QObject:: tr("ID_FOUR"));
     model->setHeaderData(1, Qt::Horizontal, QObject:: tr("NOM_C"));
     model->setHeaderData(2, Qt::Horizontal, QObject:: tr("TYPE_FOUR"));
     model->setHeaderData(3, Qt::Horizontal, QObject:: tr("DATEDEBC"));
     model->setHeaderData(4, Qt::Horizontal, QObject:: tr("DATEFINC"));
     return model;
 }
 QSqlQueryModel * fournisseurs::trieNom()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM FOURNISSEURS ORDER BY NOM_FOUR");
     model->setHeaderData(0, Qt::Horizontal,QObject:: tr("ID_FOUR"));
     model->setHeaderData(1, Qt::Horizontal, QObject:: tr("NOM_FOUR"));
     model->setHeaderData(2, Qt::Horizontal, QObject:: tr("TYPE_FOUR"));
     model->setHeaderData(3, Qt::Horizontal, QObject:: tr("DATEDEBC"));
     model->setHeaderData(4, Qt::Horizontal, QObject:: tr("DATEFINC"));
     return model;
 }
 QSqlQueryModel * fournisseurs::trieType()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM FOURNISSEURS ORDER BY TYPE_FOUR");
     model->setHeaderData(0, Qt::Horizontal,QObject:: tr("ID_FOUR"));
     model->setHeaderData(1, Qt::Horizontal, QObject:: tr("NOM_FOUR"));
     model->setHeaderData(2, Qt::Horizontal, QObject:: tr("TYPE_FOUR"));
     model->setHeaderData(3, Qt::Horizontal, QObject:: tr("DATEDEBC"));
     model->setHeaderData(4, Qt::Horizontal, QObject:: tr("DATEFINC"));
     return model;
 }
 void fournisseurs::recherche(QTableView * table, QString rech)
  {
      QSqlQueryModel *model= new QSqlQueryModel();
      QSqlQuery *query=new QSqlQuery;
          query->prepare("select * from FOURNISSEURS where ID_FOUR like '%"+rech+"%' or NOM_FOUR like '%"+rech+"%' or TYPE_FOUR like '%"+rech+"%';");
          query->exec();
          model->setQuery(*query);
          table->setModel(model);
          table->show();
  }
 void  fournisseurs::telechargerPDF(){

                       QPdfWriter pdf("C:/Users/iyadh/OneDrive/Bureau/Export PDF/PDF.pdf");



                       QPainter painter(&pdf);
                      int i = 4000;



                           painter.setPen(Qt::blue);
                            painter.setFont(QFont("Century Gothic",35,QFont::Bold));
                           painter.drawText(2000,1500,"LISTES DES FOURNISSEURS");
                           painter.setPen(Qt::black);
                           painter.drawRect(0,2700,9600,500);
                           painter.setFont(QFont("Calibri",14,QFont::Bold));
                           painter.drawText(200,3000,"ID");
                           painter.drawText(1800,3000,"Nom");
                           painter.drawText(3100,3000,"Type");
                           painter.drawText(4900,3000,"DateD");
                           painter.drawText(6800,3000,"DateF");

                          // QString s = QDate::currentDate().toString();
                           //painter.setFont(QFont("Calibri",15,QFont::Bold));
                          // painter.drawText(4000,2000,s);

                           QSqlQuery query;

                           query.prepare("select * from fournisseurs");
                           query.exec();
                           while (query.next())
                           {
                                  painter.setFont(QFont("Calibri",13));
                               painter.drawText(200,i,query.value(1).toString());
                               painter.drawText(1800,i,query.value(0).toString());
                               painter.drawText(3200,i,query.value(2).toString());
                               painter.drawText(4900,i,query.value(3).toString());
                               painter.drawText(6900,i,query.value(4).toString());
                               painter.drawText(8600,i,query.value(5).toString());



                              i = i + 500;
                           }}

 bool fournisseurs::modifier(int num)
  {
      QSqlQuery query;
      QString res=QString::number(num);

            query.prepare("update FOURNISSEURS set ID_FOUR=:ID, NOM_FOUR=:Nom,TYPE_FOUR=:Type,DATEDEBC=:DateD,DATEFINC=:DateF Where ID_FOUR=:num ");
            query.bindValue(":num",res);
            query.bindValue(":ID", ID);
            query.bindValue(":Nom", Nom);
            query.bindValue(":Type", Type);
            query.bindValue(":DateD", DateD);
            query.bindValue(":DateF", DateF);


            return query.exec();
  }







/*bool fournisseurs::update(QString Nom,QString ID)
    {
      QSqlQuery query;
      query.prepare("update fournisseurs set NOM_FOUR='"+Nom+"' ,ID-FOUR='"+ID+"'");
      return query.exec();
    }
*/
