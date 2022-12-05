#ifndef equipwindow_H
#define equipwindow_H

#include <QMainWindow>
#include "equip.h"
#include "arduino.h"

namespace Ui {
class equipwindow;
}

class equipwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit equipwindow(QWidget *parent = nullptr);//
    ~equipwindow();
    void update_label();

private slots:
    void on_modify_clicked(); // modify thezk second window //

    void on_pushButton_clicked(); // add //

    void on_pushButton_2_clicked(); // delete //

    void on_checkBox_stateChanged(int arg1); // checkbox for research employee by id //

    void on_radioButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void test();


private:
    Ui::equipwindow *ui;
    Equip g;
    Equip d;
    Equip supp;
    Arduino A;
    QByteArray data; // variable contenant les données reçues
};

#endif // MAINWINDOW_H
