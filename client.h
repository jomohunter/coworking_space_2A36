#ifndef CLIENT_H
#define CLIENT_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class Client
{
 public:
    Client();
    Client(int);
    Client(int , QString , QString , QString , int);
    int getId();
    QString getNom();
    QString getPrenom();
    QString getEmail();
    int getNumTel();
    void setId(int);
    void setNom(QString);
    void setPrenom(QString);
    void setEmail(QString);
    void setNumTel(int);

    bool ajouter();
    bool supprimer(int id);
    QSqlQueryModel* afficher();
    bool modifier(int);
    void chercherClient(int );
    QSqlQueryModel* afficherfacture();
    bool ajouterfacture(QString description,QString quantite,QString prix,QString totals);
    QSqlQueryModel* afficherid(QString);
    QSqlQueryModel* affichernom(QString );
    QSqlQueryModel* afficherprenom(QString );

private:
    int id;

    QString nom;
    QString prenom;
    QString email;
    int numTel;
};

#endif // CLIENT_H
