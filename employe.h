#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
class employe
{int id,salaire;
    QString nom,prenom,poste;
public:
    //contructeurs
    employe(){};
    employe(int,QString,QString,QString,int);
    //getters
    int getId(){return id;};
    QString getNom(){return nom;};
    QString getPrenom(){return prenom;};
    QString getPoste(){return poste;};
    int getSalaire(){return salaire;};

    //setters
    void setId(int id){this->id=id;}
    void setNom(QString n){nom=n;}
    void setPrenom(QString p){prenom=p;}
    void setPoste(QString ps){poste=ps;}
    void setSalaire(int s){salaire=s;}

    //fonctionnalités
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);
    bool modifier(int,QString,QString,QString,int);
    QSqlQueryModel* tri_id();
    QSqlQueryModel *tri_salaire();
    QSqlQueryModel * tri_nom();
    void clearTable(QTableView * table);
    QSqlQueryModel * rechercher(QString);



};

#endif // EMPLOYE_H
