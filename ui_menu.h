/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_menu
{
public:
    QPushButton *menu_employee;
    QPushButton *menu_Ffournisseurs;
    QLabel *label;
    QPushButton *menu_sponsor;
    QPushButton *menu_customers;
    QPushButton *menu_reservations;
    QLabel *label_4;

    void setupUi(QDialog *menu)
    {
        if (menu->objectName().isEmpty())
            menu->setObjectName(QStringLiteral("menu"));
        menu->resize(1128, 733);
        menu_employee = new QPushButton(menu);
        menu_employee->setObjectName(QStringLiteral("menu_employee"));
        menu_employee->setGeometry(QRect(313, 140, 181, 28));
        menu_employee->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"boder-width:5px;\n"
"    border-style: outset;\n"
"    border-radius: 10px;\n"
" "));
        menu_Ffournisseurs = new QPushButton(menu);
        menu_Ffournisseurs->setObjectName(QStringLiteral("menu_Ffournisseurs"));
        menu_Ffournisseurs->setGeometry(QRect(313, 290, 181, 28));
        menu_Ffournisseurs->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"    border-style: outset;\n"
"    border-radius: 10px;\n"
" "));
        label = new QLabel(menu);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(350, 80, 120, 51));
        QFont font;
        font.setFamily(QStringLiteral("Myanmar Text"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setTextFormat(Qt::PlainText);
        menu_sponsor = new QPushButton(menu);
        menu_sponsor->setObjectName(QStringLiteral("menu_sponsor"));
        menu_sponsor->setGeometry(QRect(313, 240, 181, 28));
        menu_sponsor->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"    border-style: outset;\n"
"    border-radius: 10px;\n"
" "));
        menu_customers = new QPushButton(menu);
        menu_customers->setObjectName(QStringLiteral("menu_customers"));
        menu_customers->setGeometry(QRect(313, 190, 181, 31));
        menu_customers->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"    border-style: outset;\n"
"    border-radius: 10px;\n"
" "));
        menu_reservations = new QPushButton(menu);
        menu_reservations->setObjectName(QStringLiteral("menu_reservations"));
        menu_reservations->setGeometry(QRect(313, 340, 181, 28));
        menu_reservations->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"    border-style: outset;\n"
"    border-radius: 10px;\n"
" "));
        label_4 = new QLabel(menu);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, 0, 871, 531));
        label_4->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/projetcppback.png")));
        label_4->raise();
        menu_employee->raise();
        menu_Ffournisseurs->raise();
        label->raise();
        menu_sponsor->raise();
        menu_customers->raise();
        menu_reservations->raise();

        retranslateUi(menu);

        QMetaObject::connectSlotsByName(menu);
    } // setupUi

    void retranslateUi(QDialog *menu)
    {
        menu->setWindowTitle(QApplication::translate("menu", "Dialog", Q_NULLPTR));
        menu_employee->setText(QApplication::translate("menu", "GESTION DES EMPLOYEES", Q_NULLPTR));
        menu_Ffournisseurs->setText(QApplication::translate("menu", "GESTION DES FOURNISSEURS", Q_NULLPTR));
        label->setText(QApplication::translate("menu", "MENU", Q_NULLPTR));
        menu_sponsor->setText(QApplication::translate("menu", "GESTION DES SPONSORS", Q_NULLPTR));
        menu_customers->setText(QApplication::translate("menu", "GESTION DES CLIENTS", Q_NULLPTR));
        menu_reservations->setText(QApplication::translate("menu", "GESTION DES RESERVATIONS", Q_NULLPTR));
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class menu: public Ui_menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
