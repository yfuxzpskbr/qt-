/********************************************************************************
** Form generated from reading UI file 'chooselevel.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSELEVEL_H
#define UI_CHOOSELEVEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chooseLevel
{
public:
    QAction *actionQuit;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *chooseLevel)
    {
        if (chooseLevel->objectName().isEmpty())
            chooseLevel->setObjectName(QStringLiteral("chooseLevel"));
        chooseLevel->resize(800, 600);
        actionQuit = new QAction(chooseLevel);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralwidget = new QWidget(chooseLevel);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        chooseLevel->setCentralWidget(centralwidget);
        menubar = new QMenuBar(chooseLevel);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        chooseLevel->setMenuBar(menubar);
        statusbar = new QStatusBar(chooseLevel);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        chooseLevel->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(actionQuit);

        retranslateUi(chooseLevel);

        QMetaObject::connectSlotsByName(chooseLevel);
    } // setupUi

    void retranslateUi(QMainWindow *chooseLevel)
    {
        chooseLevel->setWindowTitle(QApplication::translate("chooseLevel", "\345\205\263\345\215\241\351\200\211\346\213\251", 0));
        actionQuit->setText(QApplication::translate("chooseLevel", "\351\200\200\345\207\272", 0));
        menu->setTitle(QApplication::translate("chooseLevel", "\345\274\200\345\247\213", 0));
    } // retranslateUi

};

namespace Ui {
    class chooseLevel: public Ui_chooseLevel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSELEVEL_H
