#include "sponsor.h"

Sponsor::Sponsor()
{
    ID_spon=0;
    Nom_spon="";
    Prenom_spon="";
    Montant_payes=0;
    Phone="";
   Email_spon="";
    rech="";
}
Sponsor::Sponsor(int ID_spon,QString Nom_spon,QString Prenom_spon,int Montant_payes,QString Phone,QString Email_spon)
{
      this->ID_spon=ID_spon;
      this-> Nom_spon= Nom_spon;
      this-> Prenom_spon= Prenom_spon;
      this->Montant_payes=Montant_payes;
      this-> Phone= Phone;
      this->Email_spon=Email_spon;


}
void Sponsor::setID_spon(int ID_spon){this->ID_spon=ID_spon;}
void Sponsor::setNom_spon(QString Nom_spon){ this->Nom_spon=Nom_spon;}
void Sponsor::setPrenom_spon(QString Prenom_spon){this->Prenom_spon=Prenom_spon;}
void Sponsor::setMontant_payes(int Montant_payes){this->Montant_payes=Montant_payes;};
void Sponsor::setPhone(QString Phone){this->Phone=Phone;}
void Sponsor::setEmail_spon(QString Email_spon){this->Email_spon=Email_spon;};



int Sponsor::getID_spon(){return ID_spon;}
QString Sponsor::getNom_spon(){return Nom_spon;}
QString Sponsor::getPrenom_spon(){return Prenom_spon;}
int Sponsor::getMontant_payes(){return Montant_payes ;}
QString Sponsor::getPhone(){return Phone;}
QString Sponsor::getEmail_spon(){return Email_spon;}
QString Sponsor::get_rech(){return rech;}


//ajout d'un Sponsor
bool Sponsor::ajouter_Sponsor()
{
    QSqlQuery query;
    QString id_string=QString::number(ID_spon);
     QString montant_string=QString::number(Montant_payes);
      query.prepare("INSERT INTO GS_SPONSORS (ID_SPON, NOM_SPON,PRENOM_SPON, MONTANT_PAYES,PHONE,EMAIL_SPON) VALUES (:id, :forename,:prenom, :montant,:phone, :Email_spon)");
      query.bindValue(":id", id_string);
      query.bindValue(":forename", Nom_spon);
      query.bindValue(":prenom", Prenom_spon);

      query.bindValue(":montant", montant_string);
       query.bindValue(":phone", Phone);
        query.bindValue(":Email_spon", Email_spon);
      return query.exec();
}





bool Sponsor::modifier_Sponsor(){
 QSqlQuery qry;
 QString ID_spon_string= QString::number(ID_spon);
 QString Montant_payes_string= QString::number(Montant_payes);
 qry.prepare ("update GS_SPONSORS set NOM_SPON=:Nom_spon,PRENOM_SPON=:Prenom_spon,MONTANT_PAYES=:Montant_payes,PHONE=:Phone,EMAIL_SPON=:Email_spon where ID_SPON = :ID_spon" );

         qry.bindValue(":ID_spon",ID_spon_string);
         qry.bindValue(":Nom_spon",Nom_spon);
         qry.bindValue(":Prenom_spon",Prenom_spon);
         qry.bindValue(":Montant_payes",Montant_payes_string);
         qry.bindValue(":Phone",Phone);
         qry.bindValue(":Email_spon",Email_spon);

        return qry.exec();
   }

bool Sponsor::supprimer(int ids)
{
    QSqlQuery query;
    QString res=QString::number(ids);
    query.prepare("Delete from GS_SPONSORS where ID_SPON=  :ID_spon");
    query.bindValue(":ID_spon",res);
    return query.exec();
}

QSqlQueryModel*Sponsor::afficher_Sponsor(){

    QString sQuery="SELECT ID_SPON,NOM_SPON,PRENOM_SPON,MONTANT_PAYES,EMAIL_SPON FROM GS_SPONSORS where archiver=:val";

      QSqlQueryModel* model=new QSqlQueryModel();
      QString val= QString::number(0);

      QSqlQuery qry;

      qry.prepare(sQuery);
      qry.bindValue(":val",val);

      qry.exec();
      model->setQuery(qry);
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("Montant à payer"));
      model->setHeaderData(4,Qt::Horizontal,QObject::tr("Email"));

                return model;
}

QSqlQueryModel* Sponsor::afficher_Sponsor_trie_nom(){
    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery qry ;
    QString val= QString::number(0);

    qry.prepare("Select ID_SPON,NOM_SPON,PRENOM_SPON,MONTANT_PAYES,EMAIL_SPON from GS_SPONSORS where archiver=:val order by NOM_SPON ");
    qry.bindValue(":val",val);

    qry.exec();
    modal->setQuery(qry);
    modal->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    modal->setHeaderData(3,Qt::Horizontal,QObject::tr("Montant à payer"));
    modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Email"));

return modal;
}

QSqlQueryModel* Sponsor::afficher_Sponsor_trie_prenom(){
    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery * qry = new QSqlQuery();
    QString val= QString::number(0);

    qry->prepare("Select ID_SPON,NOM_SPON,PRENOM_SPON,MONTANT_PAYES,EMAIL_SPON from GS_SPONSORS where archiver=:val order by Prenom_spon ");
    qry->bindValue(":val",val);

    qry->exec();
    modal->setQuery(*qry);
    modal->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    modal->setHeaderData(3,Qt::Horizontal,QObject::tr("Montant à payer"));
    modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Email"));


    return modal;
}
QSqlQueryModel* Sponsor::rechercherdynamique(QString input, QString filtrer)
{
    QSqlQueryModel * modal=new QSqlQueryModel();
    QSqlQuery query;
    QString val= QString::number(0);

    query.prepare("SELECT ID_SPON,NOM_SPON,PRENOM_SPON,MONTANT_PAYES,EMAIL_SPON FROM GS_SPONSORS WHERE ("+filtrer+" LIKE '%' || :inputValue || '%' and  archiver=:val )");
    query.bindValue(":inputValue",input);
    query.bindValue(":val",val);

    query.exec();
    modal->setQuery(query);
    modal->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    modal->setHeaderData(3,Qt::Horizontal,QObject::tr("Montant à payer"));
    modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Email"));
    return modal;
}
QSqlQueryModel* Sponsor::chercher_Sponsor(QString rech){
    QString val= QString::number(0);

    QString sQuery="SELECT ID_SPON,NOM_SPON,PRENOM_SPON,MONTANT_PAYES,EMAIL_SPON FROM GS_SPONSORS WHERE NOM_SPON LIKE'%"+rech+"%' and archiver=:val";

    QSqlQueryModel*model4=new QSqlQueryModel();

    QSqlQuery qry;

    qry.prepare(sQuery);
    qry.bindValue(":val",val);

    qry.exec();
    model4->setQuery(qry);
    model4->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model4->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model4->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    model4->setHeaderData(3,Qt::Horizontal,QObject::tr("Montant à payer"));
    model4->setHeaderData(4,Qt::Horizontal,QObject::tr("Email"));
    return model4;
}
QSqlQueryModel* Sponsor::afficher_Sponsor_numero()
{

    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery * qry = new QSqlQuery();
    QString val= QString::number(0);

    qry->prepare("Select NOM_SPON,Prenom_spon,PHONE from GS_SPONSORS where archiver=:val");
    qry->bindValue(":val",val);
    qry->exec();
    modal->setQuery(*qry);
    modal->setHeaderData(0,Qt::Horizontal,QObject::tr("Nom"));
    modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Prenom"));
    modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Phone"));

    return modal;
}
void  Sponsor::archiversponsor(int ID_spon)
{
    QSqlQuery qry;
    QString ID_spon_string= QString::number(ID_spon);
    QString val= QString::number(1);
    qry.prepare ("update GS_SPONSORS set archiver=:val where ID_SPON = :ID_spon" );

            qry.bindValue(":ID_spon",ID_spon_string);
            qry.bindValue(":val",val);
            qry.bindValue(":Prenom_spon",Prenom_spon);
            qry.exec();
}
QSqlQueryModel* Sponsor::afficher_Sponsor_historique()
{
    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery * qry = new QSqlQuery();
    QString val= QString::number(1);

    qry->prepare("Select ID_SPON,NOM_SPON,PRENOM_SPON,MONTANT_PAYES,EMAIL_SPON,date_supp from GS_SPONSORS where archiver=:val");
    qry->bindValue(":val",val);
    qry->exec();
    modal->setQuery(*qry);
    modal->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    modal->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    modal->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    modal->setHeaderData(3,Qt::Horizontal,QObject::tr("Montant à payer"));
    modal->setHeaderData(4,Qt::Horizontal,QObject::tr("Email"));
    modal->setHeaderData(5,Qt::Horizontal,QObject::tr("Date suppression"));


    return modal;
}

void  Sponsor::setdatasupp(int ID_spon,QString da)
{
    QSqlQuery qry;
    QString ID_spon_string= QString::number(ID_spon);
    qry.prepare ("update GS_SPONSORS set date_supp=:val where ID_SPON = :ID_spon" );

            qry.bindValue(":ID_spon",ID_spon_string);
            qry.bindValue(":val",da);
            qry.exec();
}




QSqlQuery Sponsor::request(QString id)
{
    QSqlQuery query;
    query.prepare("select * from GS_SPONSORS where ID_SPON= '"+id+"'");
    query.addBindValue(id);
    query.exec();
    return query;
}
