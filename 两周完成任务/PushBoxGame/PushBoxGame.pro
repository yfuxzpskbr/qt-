#-------------------------------------------------
#
# Project created by QtCreator 2020-06-24T22:16:47
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PushBoxGame
TEMPLATE = app


SOURCES += main.cpp\
        mainscene.cpp \
    mypushbutton.cpp \
    chooselevel.cpp \
    gamesence.cpp \
    dataconfig.cpp \
    item.cpp

HEADERS  += mainscene.h \
    mypushbutton.h \
    chooselevel.h \
    gamesence.h \
    dataconfig.h \
    item.h

FORMS    += mainscene.ui \
    chooselevel.ui

RESOURCES += \
    res.qrc
