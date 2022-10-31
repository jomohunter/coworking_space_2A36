#ifndef HOW_MANY_H
#define HOW_MANY_H

#include <QDialog>

namespace Ui {
class How_many;
}

class How_many : public QDialog
{
    Q_OBJECT

public:
    explicit How_many(QWidget *parent = nullptr);
    ~How_many();

private:
    Ui::How_many *ui;
};

#endif // HOW_MANY_H
