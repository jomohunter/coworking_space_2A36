#ifndef RESERVWINDOW_H
#define RESERVWINDOW_H
#include "reservation.h"
#include <QtCharts/QLineSeries>
#include "seriallink.h"

#include <QMainWindow>

namespace Ui {
class reservwindow;
}

class reservwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit reservwindow(QWidget *parent = nullptr);
    ~reservwindow();

public slots:
    void updateGUI(QByteArray);

private slots:
    // void on_pushButton_3_clicked();

    void on_OKBUTT_clicked();

    void on_pushButton_2_clicked();

    void on_Modif_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_Salles_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_s33_clicked();

    void on_im3_clicked();

    void on_im2_clicked();

    void on_mlll_clicked();

    void on_conf_clicked();



    void on_ledon_clicked();

   // void on_ledoff_clicked();

private:
    Ui::reservwindow *ui;
    Reservation etmp;
    seriallink *arduino;
};

#endif // RESERVWINDOW_H
