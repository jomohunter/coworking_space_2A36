#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>


class Equipment
{
    QString name,type,localisation;
    int id,qt;
public:
    Equipment(){}
    Equipment(QString n,int q,QString t,QString l,int i)
    {
        this->name = n ;
        this->qt = q ;
        this->type = t ;
        this->localisation = l ;
        this->id = i;
    };
    QString getname(){return this->name;}
    int getquantity(){return this->qt;}
    QString gettype(){return this->type;}
    QString getlocalisation(){return this->localisation;}
    int getid(){return this->id;}

    void setName(QString n){name=n;}
    void settype(QString t){type=t;}
    void setlocalisation(QString l){localisation=l;}
    void setid(int id){this->id=id;}
    void setqt(int qt){this->qt=qt;}

    bool ajouter(QString,QString ,QString ,int , int);
    bool supprimer(int);
    bool modify(int ,QString,QString ,QString ,int);
    QSqlQueryModel * afficher();


};

#endif // EQUIPMENT_H
