#ifndef RESERVATION_H
#define RESERVATION_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class Reservation
{
public:
    //constracs
    Reservation(QString,QString,QString,QString,QString,QString,QString);

    //setters
    void setid(QString n);
    void setidres0(QString n);
    void setidres(QString n);
    void setespace(QString n);
    void setnbr(QString n);
    void setdated(QString n);
    void setdatef(QString n);




    //getters
    QString get_id();
    QString get_idres0();
    QString get_idres();
    QString get_nbr();
    QString get_espace();
    QString get_dated();
    QString get_datef();





    //BD
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);
    Reservation();
    QSqlQueryModel * recherche(int);
    QSqlQueryModel * recherche1();
    QSqlQueryModel * rechercheuid(QString);
    QSqlQueryModel * recherche2();
    QSqlQueryModel * recherche3();
    QSqlQueryModel * recherche4();
    QSqlQueryModel * triid();
    QSqlQueryModel * triespace();
    QSqlQueryModel * tridate();
    void PDF();
    void Confirmation(int);
    private:
    QString id,idres0,idres,espace,nbr,dated,datef;




};

#endif // RESERVATION_H
