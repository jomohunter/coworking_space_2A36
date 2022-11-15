#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employe.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_Ajouter_clicked();

    void on_pb_Supprimer_clicked();

    void on_pb_Modifier_clicked();
    //void test();

    void on_le_nomtri_clicked();

    void on_le_idtri_clicked();

    void on_le_salairetri_clicked();

    void on_pb_PDF_clicked();

    void on_stat_clicked();

   // void on_stat_clicked();


    void on_le_supprimer_textChanged(const QString &arg1);

    void on_pushButton_envoyer_clicked();

private:
    Ui::MainWindow *ui;

    employe E;

};

#endif // MAINWINDOW_H
