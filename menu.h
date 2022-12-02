#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include "mainwindow.h"
#include "equipwindow.h"

namespace Ui {
class menu;
}

class menu : public QDialog
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();

private slots:
    void on_menu_employee_clicked();


    void on_menu_customers_clicked();

    void on_menu_sponsor_clicked();

    void on_menu_Ffournisseurs_clicked();

    void on_menu_reservations_clicked();

    void on_menu_equipements_clicked();

public:
    Ui::menu *ui;

private:
    MainWindow R;
    equipwindow E;


};

#endif // MENU_H
