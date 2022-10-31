#ifndef DELETEID_H
#define DELETEID_H

#include <QDialog>
#include "equipment.h"

namespace Ui {
class deleteID;
}

class deleteID : public QDialog
{
    Q_OBJECT

public:
    explicit deleteID(QWidget *parent = nullptr);
    ~deleteID();

private slots:
    void on_pushButton_clicked();

private:
    Ui::deleteID *ui;
    Equipment supp ;
};

#endif // DELETEID_H
