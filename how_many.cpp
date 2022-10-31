#include "how_many.h"
#include "ui_how_many.h"

How_many::How_many(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::How_many)
{
    ui->setupUi(this);
}

How_many::~How_many()
{
    delete ui;
}
