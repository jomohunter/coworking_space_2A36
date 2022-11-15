/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox;
    QLabel *label_2;
    QLabel *label_h;
    QLabel *label_i;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *le_id;
    QLineEdit *le_nom_2;
    QLineEdit *le_prenom;
    QLineEdit *le_poste;
    QLineEdit *le_salaire;
    QPushButton *pb_Ajouter;
    QPushButton *pb_Modifier;
    QLabel *label_3;
    QWidget *tab_2;
    QTableView *tableView;
    QLabel *label;
    QLabel *label_7;
    QPushButton *pb_PDF;
    QPushButton *pb_Supprimer;
    QLineEdit *le_supprimer;
    QLabel *label_4;
    QLabel *label_8;
    QPushButton *le_nomtri;
    QPushButton *le_idtri;
    QPushButton *le_salairetri;
    QPushButton *stat;
    QWidget *tab_3;
    QLineEdit *LE_Destinataire;
    QLineEdit *LE_Objet;
    QLineEdit *msq;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QPushButton *pushButton_envoyer;
    QLabel *label_12;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(997, 610);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(40, 10, 871, 521));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(50, 50, 751, 351));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(80, 50, 131, 21));
        label_h = new QLabel(groupBox);
        label_h->setObjectName(QStringLiteral("label_h"));
        label_h->setGeometry(QRect(80, 100, 51, 21));
        label_i = new QLabel(groupBox);
        label_i->setObjectName(QStringLiteral("label_i"));
        label_i->setGeometry(QRect(80, 150, 61, 21));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(80, 200, 141, 21));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(80, 250, 56, 21));
        le_id = new QLineEdit(groupBox);
        le_id->setObjectName(QStringLiteral("le_id"));
        le_id->setGeometry(QRect(290, 50, 181, 22));
        le_nom_2 = new QLineEdit(groupBox);
        le_nom_2->setObjectName(QStringLiteral("le_nom_2"));
        le_nom_2->setGeometry(QRect(290, 100, 181, 22));
        le_prenom = new QLineEdit(groupBox);
        le_prenom->setObjectName(QStringLiteral("le_prenom"));
        le_prenom->setGeometry(QRect(290, 150, 181, 22));
        le_poste = new QLineEdit(groupBox);
        le_poste->setObjectName(QStringLiteral("le_poste"));
        le_poste->setGeometry(QRect(290, 200, 181, 22));
        le_salaire = new QLineEdit(groupBox);
        le_salaire->setObjectName(QStringLiteral("le_salaire"));
        le_salaire->setGeometry(QRect(290, 250, 181, 22));
        pb_Ajouter = new QPushButton(tab);
        pb_Ajouter->setObjectName(QStringLiteral("pb_Ajouter"));
        pb_Ajouter->setGeometry(QRect(560, 410, 93, 28));
        pb_Modifier = new QPushButton(tab);
        pb_Modifier->setObjectName(QStringLiteral("pb_Modifier"));
        pb_Modifier->setGeometry(QRect(660, 410, 93, 28));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, -40, 871, 551));
        label_3->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/projetcppback.png")));
        tabWidget->addTab(tab, QString());
        label_3->raise();
        groupBox->raise();
        pb_Ajouter->raise();
        pb_Modifier->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tableView = new QTableView(tab_2);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(110, 20, 646, 321));
        label = new QLabel(tab_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 375, 231, 21));
        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(610, 375, 91, 21));
        pb_PDF = new QPushButton(tab_2);
        pb_PDF->setObjectName(QStringLiteral("pb_PDF"));
        pb_PDF->setGeometry(QRect(220, 430, 201, 41));
        pb_Supprimer = new QPushButton(tab_2);
        pb_Supprimer->setObjectName(QStringLiteral("pb_Supprimer"));
        pb_Supprimer->setGeometry(QRect(390, 370, 93, 28));
        le_supprimer = new QLineEdit(tab_2);
        le_supprimer->setObjectName(QStringLiteral("le_supprimer"));
        le_supprimer->setGeometry(QRect(210, 370, 171, 31));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, -30, 871, 531));
        label_4->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/projetcppback.png")));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(370, 434, 41, 31));
        label_8->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/PDF_file_icon.svg.png")));
        le_nomtri = new QPushButton(tab_2);
        le_nomtri->setObjectName(QStringLiteral("le_nomtri"));
        le_nomtri->setGeometry(QRect(680, 370, 51, 28));
        le_idtri = new QPushButton(tab_2);
        le_idtri->setObjectName(QStringLiteral("le_idtri"));
        le_idtri->setGeometry(QRect(740, 370, 41, 28));
        le_salairetri = new QPushButton(tab_2);
        le_salairetri->setObjectName(QStringLiteral("le_salairetri"));
        le_salairetri->setGeometry(QRect(790, 370, 61, 28));
        stat = new QPushButton(tab_2);
        stat->setObjectName(QStringLiteral("stat"));
        stat->setGeometry(QRect(440, 430, 201, 41));
        tabWidget->addTab(tab_2, QString());
        label_4->raise();
        tableView->raise();
        label->raise();
        label_7->raise();
        pb_PDF->raise();
        pb_Supprimer->raise();
        le_supprimer->raise();
        label_8->raise();
        le_nomtri->raise();
        le_idtri->raise();
        le_salairetri->raise();
        stat->raise();
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        LE_Destinataire = new QLineEdit(tab_3);
        LE_Destinataire->setObjectName(QStringLiteral("LE_Destinataire"));
        LE_Destinataire->setGeometry(QRect(250, 100, 381, 22));
        LE_Objet = new QLineEdit(tab_3);
        LE_Objet->setObjectName(QStringLiteral("LE_Objet"));
        LE_Objet->setGeometry(QRect(250, 150, 381, 22));
        msq = new QLineEdit(tab_3);
        msq->setObjectName(QStringLiteral("msq"));
        msq->setGeometry(QRect(250, 190, 381, 201));
        label_9 = new QLabel(tab_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(110, 100, 81, 16));
        label_10 = new QLabel(tab_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(120, 150, 56, 16));
        label_11 = new QLabel(tab_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(120, 190, 56, 16));
        pushButton_envoyer = new QPushButton(tab_3);
        pushButton_envoyer->setObjectName(QStringLiteral("pushButton_envoyer"));
        pushButton_envoyer->setGeometry(QRect(390, 420, 93, 28));
        label_12 = new QLabel(tab_3);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(0, -80, 871, 631));
        label_12->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/projetcppback.png")));
        tabWidget->addTab(tab_3, QString());
        label_12->raise();
        LE_Destinataire->raise();
        LE_Objet->raise();
        msq->raise();
        label_9->raise();
        label_10->raise();
        label_11->raise();
        pushButton_envoyer->raise();
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 997, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion des Clients", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Employ\303\251", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">ID Employ\303\251</span></p></body></html>", Q_NULLPTR));
        label_h->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">Nom</span></p></body></html>", Q_NULLPTR));
        label_i->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">Prenom</span></p></body></html>", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">Poste</span></p></body></html>", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">Salaire</span></p></body></html>", Q_NULLPTR));
        pb_Ajouter->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        pb_Modifier->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        label_3->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Ajouter ou Modifier", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">Veuillez saisir le ID de l'employ\303\251 </span></p></body></html>", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">trier selon</span></p></body></html>", Q_NULLPTR));
        pb_PDF->setText(QApplication::translate("MainWindow", "Exporter fichier PDF       ", Q_NULLPTR));
        pb_Supprimer->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        label_4->setText(QString());
        label_8->setText(QString());
        le_nomtri->setText(QApplication::translate("MainWindow", "Nom", Q_NULLPTR));
        le_idtri->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        le_salairetri->setText(QApplication::translate("MainWindow", "Salaire", Q_NULLPTR));
        stat->setText(QApplication::translate("MainWindow", "Statistiques    ", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Afficher les employ\303\251s", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "Destinataire", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Objet", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "Message", Q_NULLPTR));
        pushButton_envoyer->setText(QApplication::translate("MainWindow", "Envoyer", Q_NULLPTR));
        label_12->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Envoi mail", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
