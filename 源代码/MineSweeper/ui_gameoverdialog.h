/********************************************************************************
** Form generated from reading UI file 'gameoverdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEOVERDIALOG_H
#define UI_GAMEOVERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_GameOverDialog
{
public:
    QLabel *label;

    void setupUi(QDialog *GameOverDialog)
    {
        if (GameOverDialog->objectName().isEmpty())
            GameOverDialog->setObjectName(QStringLiteral("GameOverDialog"));
        GameOverDialog->resize(250, 150);
        GameOverDialog->setMinimumSize(QSize(250, 150));
        GameOverDialog->setMaximumSize(QSize(250, 150));
        label = new QLabel(GameOverDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 250, 150));
        label->setTextFormat(Qt::PlainText);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(GameOverDialog);

        QMetaObject::connectSlotsByName(GameOverDialog);
    } // setupUi

    void retranslateUi(QDialog *GameOverDialog)
    {
        GameOverDialog->setWindowTitle(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GameOverDialog: public Ui_GameOverDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOVERDIALOG_H
