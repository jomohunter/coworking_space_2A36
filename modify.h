#ifndef MODIFY_H
#define MODIFY_H


#include <QDialog>
#include"equipment.h"

namespace Ui {
class modify;
}

class modify : public QDialog
{
    Q_OBJECT

public:
    explicit modify(QWidget *parent = nullptr);
    ~modify();

private slots:
    void on_confirm_delete_clicked();

    void on_confirm_modify_clicked();

    void on_pushButton_clicked();

    void on_pushButton_released();

    void on_pushButton_2_clicked();

    void on_ADD_accepted();

private:
    Ui::modify *ui;
    Equipment e ;
};


#endif // MODIFY_H