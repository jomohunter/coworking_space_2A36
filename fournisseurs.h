#ifndef FOURNISSEURS_H
#define FOURNISSEURS_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QTableView>

class fournisseurs
{
public:
    //constracteures
    fournisseurs();
    fournisseurs(QString,QString,QString,QString,QString,QString);
    //setters
    void setID(QString n);
    void setNom(QString n);
    void setType(QString n);
    void setDateD(QString n);
    void setDateF(QString n);
    void setnum(QString n);

    //getters
    QString get_ID();
    QString get_Nom();
    QString get_Type();
    QString get_DateD();
    QString get_DateF();
    QString get_num();

    //base de donner
    bool ajouter();// bool true=maaneha yzyyd sinn erreur
    bool supprimer(int);//supp selon l'id
        QSqlQueryModel * afficher();
        QSqlQueryModel * trieID();
            QSqlQueryModel * trieNom();
            QSqlQueryModel * trieType();
            void recherche(QTableView * table, QString);
            void telechargerPDF();
            bool modifier(int);



private:
    QString ID,Nom,Type,DateD,DateF,num;
};

#endif // FOURNISSEURS_H
