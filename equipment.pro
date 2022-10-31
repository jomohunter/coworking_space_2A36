greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += sql
CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connection.cpp \
    deleteid.cpp \
    dialog.cpp \
    equipment.cpp \
    how_many.cpp \
    main.cpp \
    mainwindow.cpp \
    modify.cpp

HEADERS += \
    connection.h \
    deleteid.h \
    dialog.h \
    equipment.h \
    how_many.h \
    mainwindow.h \
    modify.h

FORMS += \
    deleteid.ui \
    dialog.ui \
    how_many.ui \
    mainwindow.ui \
    modify.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
