#ifndef EQUIP_H
#define EQUIP_H

#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QDate>
#include <QTime>
#include <QMessageBox>
#include <QDebug>


class Equip
{
   protected: // attributs //
        QString id;
        QString nom;
        QString type;
        QString local;
        int qt;
        int NUMF;

    public: // methode //
        Equip(){};
        Equip(QString i, QString n, QString t, QString l, int q, int NUMF)
        {
            this->id = i;
            this->nom = n;
            this->type = t;
            this->local = l;
            this->qt = q;
            this->NUMF = NUMF;
        };

        QString getID(){return this->id;};
        QString getNom(){return this->nom;};
        QString gettype(){return this->type;};
        QString getlocal(){return this->local;};
        int getqt(){return this->qt;};
        int getNUMF(){return this->NUMF;};
        // set functions //

        void setID(QString);
        bool Ajouter();
        bool Supprimer(QString);
        bool Modifier(QString , QString , QString, QString, int);
        bool reclamation(QString);

        QSqlQueryModel * researchid(QString i);
        QSqlQueryModel * Afficher();
        QSqlQueryModel * Afficher_2();
};

#endif // EQUIP_H
