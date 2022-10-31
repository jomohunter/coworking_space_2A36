#ifndef DIALOG_H
#define DIALOG_H
#include "equipment.h"
#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_ADD_accepted();

    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    Equipment e;
};

#endif // DIALOG_H
