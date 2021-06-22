/********************************************************************************
** Form generated from reading UI file 'difficultpattern.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIFFICULTPATTERN_H
#define UI_DIFFICULTPATTERN_H

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

class Ui_DifficultPattern
{
public:
    QAction *actionQuit;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DifficultPattern)
    {
        if (DifficultPattern->objectName().isEmpty())
            DifficultPattern->setObjectName(QStringLiteral("DifficultPattern"));
        DifficultPattern->resize(800, 600);
        actionQuit = new QAction(DifficultPattern);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralwidget = new QWidget(DifficultPattern);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        DifficultPattern->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DifficultPattern);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        DifficultPattern->setMenuBar(menubar);
        statusbar = new QStatusBar(DifficultPattern);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        DifficultPattern->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(actionQuit);

        retranslateUi(DifficultPattern);

        QMetaObject::connectSlotsByName(DifficultPattern);
    } // setupUi

    void retranslateUi(QMainWindow *DifficultPattern)
    {
        DifficultPattern->setWindowTitle(QApplication::translate("DifficultPattern", "MainWindow", 0));
        actionQuit->setText(QApplication::translate("DifficultPattern", "\351\200\200\345\207\272", 0));
        menu->setTitle(QApplication::translate("DifficultPattern", "\345\274\200\345\247\213", 0));
    } // retranslateUi

};

namespace Ui {
    class DifficultPattern: public Ui_DifficultPattern {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIFFICULTPATTERN_H
