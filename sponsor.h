  #ifndef SPONSOR_H
#define SPONSOR_H
#include <QApplication>
#include"connection.h"
#include<QMessageBox>
#include<QString>
#include<qsqlquerymodel.h>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <Qwidget>
class Sponsor
{
    int ID_spon,Montant_payes;
    QString Nom_spon,Prenom_spon,Phone,Email_spon,rech;
public:
    void setID_spon(int n);
    void setNom_spon(QString n);
    void setPrenom_spon(QString n);
    void setMontant_payes(int n);
    void setPhone(QString n);
    void setEmail_spon(QString n);
    int getID_spon();
    int getMontant_payes();
    QString getNom_spon();
    QString getPrenom_spon();
    QString getPhone();
    QString getEmail_spon();
    QString get_rech();
    bool ajouter_Sponsor();
    bool supprimer(int ids);
    bool modifier_Sponsor();
    QSqlQueryModel* chercher_Sponsor(QString rech);
    QSqlQueryModel* afficher_Sponsor_trie_nom();
    QSqlQueryModel* afficher_Sponsor_trie_prenom();
    QSqlQueryModel* afficher_Sponsor();
     QSqlQueryModel* afficher_Sponsor_numero();
   void  archiversponsor(int ID_spon);
    QSqlQueryModel* afficher_Sponsor_historique();
    void  setdatasupp(int ID_spon,QString da);

    QSqlQuery request(QString);

    QSqlQueryModel* rechercherdynamique(QString input, QString filtrer);
    Sponsor();
    Sponsor(int,QString,QString,int,QString,QString);


};

#endif // SPONSOR_H
