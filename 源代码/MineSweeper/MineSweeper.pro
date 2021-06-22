#-------------------------------------------------
#
# Project created by QtCreator 2020-08-16T16:46:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MineSweeper
TEMPLATE = app


SOURCES += main.cpp\
        mainscene.cpp \
    mypushbutton.cpp \
    easypattern.cpp \
    gameoverdialog.cpp \
    commonpattern.cpp \
    difficultpattern.cpp

HEADERS  += mainscene.h \
    mypushbutton.h \
    easypattern.h \
    gameoverdialog.h \
    commonpattern.h \
    difficultpattern.h

FORMS    += mainscene.ui \
    easypattern.ui \
    gameoverdialog.ui \
    commonpattern.ui \
    difficultpattern.ui

RESOURCES += \
    res.qrc

DISTFILES += \
    readme.txt
