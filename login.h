#ifndef LOGIN_H
#define LOGIN_H
#include "mainwindow.h"
#include <QDialog>
#include"employe.h"
#include "menu.h"
namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_pb_seconnecter_clicked();

private:
    Ui::login *ui;
    menu m;

};

#endif // LOGIN_H
