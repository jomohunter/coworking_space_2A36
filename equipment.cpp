#include "equipment.h"

bool Equipment::ajouter(QString n,QString t,QString l,int i,int q)
{
    QSqlQuery query;
        query.prepare("INSERT INTO EQUIPEMENTS(ID_EQUIP, TYPE_MAT, NOM_MAT,LOCAL,QTEEQUIP"
                      "VALUES (:id, :type, :name, :local, :quantite)");//
        query.bindValue(":id", i);
        query.bindValue(":name", n);
        query.bindValue(":type", t);
        query.bindValue(":local", l);
        query.bindValue(":quantite", q);

        return query.exec();

}

QSqlQueryModel * Equipment::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();

        model->setQuery("SELECT ID_EQUIP, TYPE_MAT, NOM_MAT,LOCAL, QTEEQUIP FROM EQUIPEMENTS");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EQUIP"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE_MAT"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM_MAT"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("LOCAL"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("QTEEQUIP"));
      return model;
}

bool Equipment::supprimer(int id) //supprimer//
{
  QSqlQuery query ;
  query.prepare("Delete from EQUIPEMENTS where ID_EQUIP= :id");
  query.bindValue(":id",id);
  return query.exec();
}

bool Equipment::modify(int id,QString type ,QString nom,QString localisation,int qt) //update //
{
    QSqlQuery query ;
    query.prepare("UPDATE EQUIPEMENTS SET ID_EQUIP= :id,TYPE_MAT= :type,NOM_MAT= :nom,LOCALISATION_EQUIP= :localisation,"
                  "QTEEQUIP= :qt");
    query.bindValue(":id",this->getid());
    query.bindValue(":type",this->gettype());
    query.bindValue(":nom",this->getname());
    query.bindValue(":localisation",this->getlocalisation());
    query.bindValue(":qt",this->getquantity());
    return query.exec();
}

