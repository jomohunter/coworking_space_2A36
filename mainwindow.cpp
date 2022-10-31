#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "how_many.h"
#include "equipment.h"
#include "deleteid.h"
#include "modify.h"
#include "QMessageBox"
#include <bits/stdc++.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->table_menu->setModel(g.afficher());
  }

MainWindow::~MainWindow()
{
    delete ui;
    ui->table_menu->setModel(g.afficher());
}

void MainWindow::on_pushButton_clicked()
{
    Dialog d;
    d.setModal(true);
    d.exec();
     ui->table_menu->setModel(g.afficher());
}

void MainWindow::on_pushButton_2_clicked()
{
    Dialog d;
    d.setModal(true);
    d.exec();
     ui->table_menu->setModel(g.afficher());
}


void MainWindow::on_pushButton_6_clicked()
{
    How_many m;
    m.setModal(true);
    m.exec();
     ui->table_menu->setModel(g.afficher());

}


void MainWindow::on_pushButton_3_clicked()
{
    deleteID d;
    d.setModal(true);
    d.exec();
    ui->table_menu->setModel(g.afficher());
}

void MainWindow::on_pushButton_4_clicked()
{
    deleteID d;
    d.setModal(true);
    d.exec();
    ui->table_menu->setModel(g.afficher());
}

void MainWindow::on_pushButton_7_clicked()
{
    How_many m;
    m.setModal(true);
    m.exec();
     ui->table_menu->setModel(g.afficher());
}

void MainWindow::on_pushButton_8_clicked()
{
    modify m;
    m.setModal(true);
    m.exec();
     ui->table_menu->setModel(g.afficher());
}