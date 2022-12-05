
QT       += core gui sql printsupport charts network serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    QrCode.cpp \
    arduino.cpp \
    client.cpp \
    connection.cpp \
    dialog.cpp \
    employe.cpp \
    equip.cpp \
    equipwindow.cpp \
    fournisseurs.cpp \
    inter_client.cpp \
    inter_fournisseur.cpp \
    inter_spon.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    modify.cpp \
    notification.cpp \
    pdf.cpp \
    popup.cpp \
    qcustomplot.cpp \
    seriallink.cpp \
    smtp.cpp \
    sponsor.cpp \
    statistics.cpp \
    statistique.cpp

HEADERS += \
    QrCode.hpp \
    arduino.h \
    client.h \
    connection.h \
    dialog.h \
    employe.h \
    equip.h \
    equipwindow.h \
    fournisseurs.h \
    inter_client.h \
    inter_fournisseur.h \
    inter_spon.h \
    login.h \
    mainwindow.h \
    menu.h \
    modify.h \
    notification.h \
    pdf.h \
    popup.h \
    qcustomplot.h \
    seriallink.h \
    smtp.h \
    sponsor.h \
    statistics.h \
    statistique.h

FORMS += \
    dialog.ui \
    equipwindow.ui \
    inter_client.ui \
    inter_fournisseur.ui \
    inter_spon.ui \
    login.ui \
    mainwindow.ui \
    menu.ui \
    modify.ui \
    pdf.ui \
    statistics.ui \
    statistique.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    backs.qrc
