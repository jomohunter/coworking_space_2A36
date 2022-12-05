#ifndef INTER_SPON_H
#define INTER_SPON_H

#include <QMainWindow>
#include "sponsor.h"
#include "arduino.h"

namespace Ui {
class inter_spon;
}

class inter_spon : public QMainWindow
{
    Q_OBJECT

public:
    explicit inter_spon(QWidget *parent = nullptr);
    ~inter_spon();
private slots:

    void update_label();

    void on_pushButton_ajouter_2_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_afficher_clicked();

    void on_pushButton_modifier_2_clicked();

    void on_pushButton_supprimer_clicked();



    void on_lineEdit_prenomcher_cursorPositionChanged(int arg1, int arg2);

    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();


    void on_pushButton_6_clicked();

    void on_lineEdit_chercher_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_supprimer_2_clicked();


private:
    Ui::inter_spon *ui;
    Sponsor s;

    QByteArray data;

    Arduino A;

};

#endif // INTER_SPON_H
