#ifndef DIALOG_H
#define DIALOG_H
#include "popup.h"
#include <QDialog>

namespace Ui {
class Dialog;
}

class ahmed : public QDialog
{
    Q_OBJECT

public:
    explicit ahmed(QWidget *parent = nullptr);
    ~ahmed();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Dialog *ui;
    PopUp *popUp;
};

#endif // DIALOG_H
