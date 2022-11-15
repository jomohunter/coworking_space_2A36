#include "employe.h"
#include "QtDebug"
#include <QObject>



employe ::employe(int id,QString nom,QString prenom,QString poste,int salaire){
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->poste=poste;
    this->salaire=salaire;

}
bool employe :: ajouter()
{
    QSqlQuery query;
      QString res=QString::number(id);
            query.prepare("INSERT INTO EMPLOYES (ID_EMP,NOM_EMP,PRENOM_EMP,POSTE_EMP,SALAIRE_EMP) "
                          "VALUES (:ID_EMP, :NOM_EMP, :PRENOM_EMP,:POSTE_EMP,:SALAIRE_EMP)");
            query.bindValue(":ID_EMP", res);
            query.bindValue(":NOM_EMP",nom);
            query.bindValue(":PRENOM_EMP", prenom);
            query.bindValue(":POSTE_EMP", poste);
            query.bindValue(":SALAIRE_EMP", salaire);
            return query.exec();

}

QSqlQueryModel * employe :: afficher()
{
QSqlQueryModel *model=new QSqlQueryModel();
model->setQuery("select * from EMPLOYES");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_EMP"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_EMP"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM_EMP"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("POSTE_EMP"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("SALAIRE_EMP"));
return model;
}

bool employe :: supprimer(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("Delete from EMPLOYES where ID_EMP=:id");
    query.bindValue(":id",res);
    return query.exec();
}
bool employe::modifier(int id,QString nom,QString prenom,QString poste,int salaire)
   {
     QSqlQuery query;
      QString res=QString::number(id);
     query.prepare("update EMPLOYES set  ID_EMP=:ID_EMP, NOM_EMP=:NOM_EMP,PRENOM_EMP=:PRENOM_EMP,POSTE_EMP=:POSTE_EMP,SALAIRE_EMP=:SALAIRE_EMP Where ID_EMP=:ID_EMP  ");



     query.bindValue(":ID_EMP", res);
     query.bindValue(":NOM_EMP",nom);
     query.bindValue(":PRENOM_EMP", prenom);
     query.bindValue(":POSTE_EMP", poste);
     query.bindValue(":SALAIRE_EMP", salaire);
     return query.exec();


 }
QSqlQueryModel* employe::tri_id()
{
    QSqlQueryModel* model=new QSqlQueryModel();
          model->setQuery("SELECT *  FROM EMPLOYES ORDER BY ID_EMP");
          model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_EMP"));
          model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_EMP"));
          model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM_EMP"));
          model->setHeaderData(3,Qt::Horizontal,QObject::tr("POSTE_EMP"));
          model->setHeaderData(4,Qt::Horizontal,QObject::tr("SALAIRE_EMP"));
          return model;

    return model;
}

QSqlQueryModel * employe::tri_salaire()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT *  FROM EMPLOYES ORDER BY SALAIRE_EMP");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_EMP"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_EMP"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM_EMP"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("POSTE_EMP"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("SALAIRE_EMP"));
    return model;
}

QSqlQueryModel * employe::tri_nom()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT *  FROM EMPLOYES ORDER BY NOM_EMP");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_EMP"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_EMP"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM_EMP"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("POSTE_EMP"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("SALAIRE_EMP"));
    return model;
}


void employe::clearTable(QTableView *table)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->clear();
    table->setModel(model);
}



QSqlQueryModel * employe ::rechercher(QString CIN)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM EMPLOYES WHERE ID_EMP LIKE '%"+CIN+"%' ");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_EMP"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_EMP"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM_EMP"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("POSTE_EMP"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("SALAIRE_EMP"));
    return model;
}
