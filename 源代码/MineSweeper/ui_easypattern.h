/********************************************************************************
** Form generated from reading UI file 'easypattern.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EASYPATTERN_H
#define UI_EASYPATTERN_H

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

class Ui_EasyPattern
{
public:
    QAction *actionQuit;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu;

    void setupUi(QMainWindow *EasyPattern)
    {
        if (EasyPattern->objectName().isEmpty())
            EasyPattern->setObjectName(QStringLiteral("EasyPattern"));
        EasyPattern->resize(800, 600);
        actionQuit = new QAction(EasyPattern);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralwidget = new QWidget(EasyPattern);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        EasyPattern->setCentralWidget(centralwidget);
        menubar = new QMenuBar(EasyPattern);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        EasyPattern->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menu->addAction(actionQuit);

        retranslateUi(EasyPattern);

        QMetaObject::connectSlotsByName(EasyPattern);
    } // setupUi

    void retranslateUi(QMainWindow *EasyPattern)
    {
        EasyPattern->setWindowTitle(QApplication::translate("EasyPattern", "MainWindow", 0));
        actionQuit->setText(QApplication::translate("EasyPattern", "\351\200\200\345\207\272", 0));
        menu->setTitle(QApplication::translate("EasyPattern", "\345\274\200\345\247\213", 0));
    } // retranslateUi

};

namespace Ui {
    class EasyPattern: public Ui_EasyPattern {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EASYPATTERN_H
