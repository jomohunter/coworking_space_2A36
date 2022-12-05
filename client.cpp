#include "client.h"
#include<QSqlQuery>
#include<QDebug>
#include<QObject>
#include<QtGlobal>
#include<QTableView>
Client::Client()//default constructor
{
id=0;
nom="";
prenom="";
this->email="";
numTel=0;
}
Client::Client(int id)//default constructor
{
this->id=id;
nom="";
prenom="";
this->email="";
this->numTel=0;
}
Client::Client(int id ,QString nom,QString prenom,QString email, int numTel)//parameter constructor
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->email=email;
    this->numTel=numTel;
}

//getters
int Client::getId(){return id;}
QString Client::getNom(){return nom;}
QString Client::getPrenom(){return prenom;}
QString Client::getEmail(){return this->email;}
int Client::getNumTel(){return numTel;}
//setters
void Client::setId(int id){this->id=id;}
void Client::setNom(QString nom){this->nom=nom;}
void Client::setPrenom(QString prenom){this->prenom=prenom;}
void Client::setEmail(QString email){this->email=email;}
void Client::setNumTel(int num){this->numTel=num;}



bool Client::ajouter()
{
    //bool test=false;
    QSqlQuery query;
    QString id_string;
            id_string=QString::number(id);


    QString numTelString=QString::number(numTel);
    //qDebug( qUtf8Printable(numTelString) );

    query.prepare("INSERT INTO CLIENTS(ID, NOM, PRENOM, EMAIL , NUMTEL)"
                  "VALUES (:ID, :NOM, :PRENOM, :EMAIL, :NUMTEL)");
    query.bindValue(":ID",id_string);
    query.bindValue(":NOM",nom);
    query.bindValue(":PRENOM",prenom);
    query.bindValue(":EMAIL",email);
    query.bindValue(":NUMTEL",numTelString);


    return query.exec();
}
QSqlQueryModel*    Client::afficher()
{

    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* from CLIENTS");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("name "));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("surname "));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("e-mail "));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("phone "));



    return model;

}
bool Client::supprimer(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("Delete from CLIENTS where ID= :ID");
    query.bindValue(":ID",res);
    return query.exec();
}
bool Client::modifier(int id)
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("Update CLIENTS set ID = :ID , NOM = :NOM , PRENOM = :PRENOM , EMAIL  = :EMAIL , NUMTEL = :NUMTEL  where ID = :ID ");
    query.bindValue(":ID", res);
    query.bindValue(":NOM", nom);
    query.bindValue(":PRENOM", prenom);
    query.bindValue(":EMAIL", email);
    query.bindValue(":NUMTEL", numTel);
    return    query.exec();
}
void Client::chercherClient(int critere)
{
    QSqlQuery query;


    if(critere==1)
    {
        query.prepare("SELECT * FROM CLIENTS WHERE ID =:ID " );
        query.bindValue(":ID", id);
        query.exec();




        while(query.next())
       {
            this->id=query.value(0).toInt();

            this->nom=query.value(1).toString();
            this->prenom=query.value(2).toString();
            this->email=query.value(3).toString();
            this->numTel=query.value(4).toInt();

       }
    }

}
QSqlQueryModel*    Client::afficherfacture()
{



    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* from facture");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("description"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("periode "));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix  "));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("total "));


    return model;

}
bool Client::ajouterfacture(QString description,QString periode,QString prix,QString totals)
{

    QSqlQuery query;



    QString numTelString=QString::number(numTel);

    query.prepare("INSERT INTO facture(description, periode, prix , total)"
                   "VALUES (:description, :periode, :prix, :total)");
     query.bindValue(":description",description);
     query.bindValue(":periode",periode);
     query.bindValue(":prix",prix);
     query.bindValue(":total",totals);
     return query.exec();
}
QSqlQueryModel* Client::afficherid(QString q)
{
         //QString res =QString::number(id);
         QSqlQueryModel *model=new QSqlQueryModel();
          model->setQuery("SELECT * FROM CLIENTS  WHERE ID like '%"+q+"%'" );
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("name "));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("surname "));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("e-mail "));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("phone "));

          return model;

}
QSqlQueryModel* Client::affichernom(QString q)
{
        // QString res =QString::number(nom);
         QSqlQueryModel *model=new QSqlQueryModel();
          model->setQuery("SELECT * FROM CLIENTS  WHERE NOM like '%"+q+"%'" );
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("name "));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("surname "));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("e-mail "));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("phone "));

          return model;

}
QSqlQueryModel* Client::afficherprenom(QString q)
{
        // QString res =QString::number(nom);
         QSqlQueryModel *model=new QSqlQueryModel();
          model->setQuery("SELECT * FROM CLIENTS  WHERE PRENOM like '%"+q+"%'" );
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("name "));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("surname "));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("e-mail "));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("phone "));

          return model;

}







QSqlQueryModel *   Client::rechercheuid(QString id)
{

    QSqlQuery* query = new QSqlQuery();
    // QString res11=QString::number(id);



    query->prepare("select NOM from CLIENTS where UIDD=:id");
    query->bindValue(":id",id);
    query->exec();
    QSqlQueryModel * model1=new QSqlQueryModel () ;


   model1->setQuery(*query);
   model1->setHeaderData(0,Qt::Horizontal,QObject::tr("NOM"));
   QTableView* tableView = new QTableView();
   tableView->setModel(model1);

   return model1;
}
