/********************************************************************************
** Form generated from reading UI file 'commonpattern.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMONPATTERN_H
#define UI_COMMONPATTERN_H

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

class Ui_CommonPattern
{
public:
    QAction *actionQuit;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu;

    void setupUi(QMainWindow *CommonPattern)
    {
        if (CommonPattern->objectName().isEmpty())
            CommonPattern->setObjectName(QStringLiteral("CommonPattern"));
        CommonPattern->resize(640, 640);
        CommonPattern->setMinimumSize(QSize(640, 640));
        CommonPattern->setMaximumSize(QSize(640, 640));
        actionQuit = new QAction(CommonPattern);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralwidget = new QWidget(CommonPattern);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        CommonPattern->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CommonPattern);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 640, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        CommonPattern->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menu->addAction(actionQuit);

        retranslateUi(CommonPattern);

        QMetaObject::connectSlotsByName(CommonPattern);
    } // setupUi

    void retranslateUi(QMainWindow *CommonPattern)
    {
        CommonPattern->setWindowTitle(QApplication::translate("CommonPattern", "\344\270\200\350\210\254\346\250\241\345\274\217", 0));
        actionQuit->setText(QApplication::translate("CommonPattern", "\351\200\200\345\207\272", 0));
        menu->setTitle(QApplication::translate("CommonPattern", "\345\274\200\345\247\213", 0));
    } // retranslateUi

};

namespace Ui {
    class CommonPattern: public Ui_CommonPattern {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMONPATTERN_H
