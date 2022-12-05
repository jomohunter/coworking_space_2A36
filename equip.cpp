#include "equip.h"
#include "modify.h"
#include <QDebug>

bool Equip::Ajouter(){
    QSqlQuery query;

    query.prepare("INSERT INTO EQUIPEMENTS(ID_EQUIP, TYPE_MAT, NOM_MAT, LOCAL, QTEEQUIP)"
                  "VALUES (:id, :type, :nom, :local, :qt)");
    query.bindValue(":id", this->getID());
    query.bindValue(":nom", this->getNom());
    query.bindValue(":type", this->gettype());
    query.bindValue(":local", this->getlocal());
    query.bindValue(":qt", this->getqt());
    //query.bindValue(":date", QDate::currentDate().toString());
    return query.exec();
}

bool Equip::Modifier(QString id, QString nom, QString type, QString local, int qt) //update //
{
    QSqlQuery query ;
    query.prepare("UPDATE EQUIPEMENTS SET ID_EQUIP= :id,TYPE_MAT= :type,NOM_MAT= :nom,LOCAL= :local,QTEEQUIP= :qt");
    query.bindValue(":id",id);
    query.bindValue(":type",type);
    query.bindValue(":nom",nom);
    query.bindValue(":local",local);
    query.bindValue(":qt",qt);

    return query.exec();
}
/*
bool Equip::reclamation(QString rec)
{
    QSqlQuery query;

    query.prepare("INSERT INTO EQUIPEMENTS(ID_EQUIP, RECLAMATION)"
                  "VALUES (:id, :rec)");
    query.bindValue(":rec", rec);
    query.bindValue(":id", rec.toInt()%10000^123);

    return query.exec();
}
*/
QSqlQueryModel * Equip::Afficher()
{ //afffichage1//
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT ID_EQUIP, TYPE_MAT, NOM_MAT, LOCAL, QTEEQUIP FROM EQUIPEMENTS");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EQUIP"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE_MAT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM_MAT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("LOCAL"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("QTEEQUIP"));

    return model;
}

QSqlQueryModel * Equip::Afficher_2()//afffichage2//
{
    QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("SELECT ID_EQUIP, TYPE_MAT, NOM_MAT, LOCAL, QTEEQUIP FROM EQUIPEMENTS");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EQUIP"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE_MAT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM_MAT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("LOCAL"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("QTEEQUIP"));

    return model;
}

bool Equip::Supprimer(QString id) //supprimer//
{
  QSqlQuery test ;
  test.prepare("SELECT COUNT(*) from EQUIPEMENTS where ID_EQUIP= :id");
  test.bindValue(":id",id);
  test.exec();
  if (test.next())
  {
if (test.value(0).toInt() == 1)
{
    QSqlQuery query ;
    query.prepare("Delete from EQUIPEMENTS where ID_EQUIP= :id");
    query.bindValue(":id",id);
    return query.exec();
}
   else{return false;}
  }
}

QSqlQueryModel * Equip::researchid(QString i)
{
    QSqlQueryModel * model= new QSqlQueryModel();

         model->setQuery("select * from EQUIPEMENTS where ID_EQUIP = '" +i+ "' ");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EQUIP"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE_MAT"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM_MAT"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("LOCAL"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("QTEEQUIP"));
             return model;
}

