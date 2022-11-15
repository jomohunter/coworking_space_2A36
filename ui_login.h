/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QGroupBox *groupBox;
    QLabel *label_2;
    QLineEdit *password;
    QLineEdit *nom;
    QLabel *label_h;
    QPushButton *pb_seconnecter;
    QLabel *label_3;

    void setupUi(QDialog *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QStringLiteral("login"));
        login->resize(993, 603);
        groupBox = new QGroupBox(login);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(100, 100, 751, 351));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(130, 170, 131, 21));
        password = new QLineEdit(groupBox);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(340, 170, 181, 22));
        nom = new QLineEdit(groupBox);
        nom->setObjectName(QStringLiteral("nom"));
        nom->setGeometry(QRect(340, 110, 181, 22));
        label_h = new QLabel(groupBox);
        label_h->setObjectName(QStringLiteral("label_h"));
        label_h->setGeometry(QRect(130, 110, 51, 21));
        pb_seconnecter = new QPushButton(groupBox);
        pb_seconnecter->setObjectName(QStringLiteral("pb_seconnecter"));
        pb_seconnecter->setGeometry(QRect(280, 240, 93, 28));
        label_3 = new QLabel(login);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 20, 871, 551));
        label_3->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/projetcppback.png")));
        label_3->raise();
        groupBox->raise();

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QDialog *login)
    {
        login->setWindowTitle(QApplication::translate("login", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("login", "Authentification", Q_NULLPTR));
        label_2->setText(QApplication::translate("login", "<html><head/><body><p><span style=\" color:#ffffff;\">ID Employ\303\251</span></p></body></html>", Q_NULLPTR));
        label_h->setText(QApplication::translate("login", "<html><head/><body><p><span style=\" color:#ffffff;\">Nom</span></p></body></html>", Q_NULLPTR));
        pb_seconnecter->setText(QApplication::translate("login", "Se connecter", Q_NULLPTR));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
