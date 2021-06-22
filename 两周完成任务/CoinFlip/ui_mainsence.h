/********************************************************************************
** Form generated from reading UI file 'mainsence.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSENCE_H
#define UI_MAINSENCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainSence
{
public:
    QAction *actionExit;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu;

    void setupUi(QMainWindow *MainSence)
    {
        if (MainSence->objectName().isEmpty())
            MainSence->setObjectName(QStringLiteral("MainSence"));
        MainSence->setEnabled(true);
        MainSence->resize(390, 590);
        actionExit = new QAction(MainSence);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(MainSence);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainSence->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainSence);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 390, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainSence->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionExit);

        retranslateUi(MainSence);

        QMetaObject::connectSlotsByName(MainSence);
    } // setupUi

    void retranslateUi(QMainWindow *MainSence)
    {
        MainSence->setWindowTitle(QApplication::translate("MainSence", "MainSence", 0));
        actionExit->setText(QApplication::translate("MainSence", "\351\200\200\345\207\272", 0));
        menu->setTitle(QApplication::translate("MainSence", "\345\274\200\345\247\213", 0));
    } // retranslateUi

};

namespace Ui {
    class MainSence: public Ui_MainSence {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSENCE_H
