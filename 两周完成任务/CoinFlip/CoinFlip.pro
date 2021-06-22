#-------------------------------------------------
#
# Project created by QtCreator 2020-06-22T10:00:00
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CoinFlip
TEMPLATE = app


SOURCES += main.cpp\
        mainsence.cpp \
    mypushbutton.cpp \
    chooselevelsence.cpp \
    playgame.cpp \
    mycoin.cpp \
    dataconfig.cpp

HEADERS  += mainsence.h \
    mypushbutton.h \
    chooselevelsence.h \
    playgame.h \
    mycoin.h \
    dataconfig.h

FORMS    += mainsence.ui

RESOURCES += \
    res.qrc
