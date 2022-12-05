#ifndef INTER_FOURNISSEUR_H
#define INTER_FOURNISSEUR_H

#include<fournisseurs.h>
#include <QMainWindow>
#include <arduino.h>
#include "notification.h"

namespace Ui {
class inter_fournisseur;
}

class inter_fournisseur : public QMainWindow
{
    Q_OBJECT

public:
    explicit inter_fournisseur(QWidget *parent = nullptr);
    ~inter_fournisseur();
    void  set_fournisseurs(fournisseurs f);
private slots:
    void on_pushButton_5_clicked();
    void on_pushButton_3_clicked();


    //void on_pushButton_9_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_lineEdit_11_textChanged(const QString &arg1);

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void update_label();

    void update_label2();

private:
    Ui::inter_fournisseur *ui;
    fournisseurs etmp;
    Arduino A;
    notification N;

};

#endif // INTER_FOURNISSEUR_H
