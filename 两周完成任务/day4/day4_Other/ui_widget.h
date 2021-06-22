/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QWidget *tab_3;
    QWidget *page_5;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_8;
    QPushButton *pushButton_6;
    QPushButton *pushButton_2;
    QPushButton *pushButton_7;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QWidget *page_4;
    QVBoxLayout *verticalLayout_2;
    QToolBox *toolBox;
    QWidget *widget;
    QWidget *page;
    QWidget *page_2;
    QWidget *page_6;
    QComboBox *comboBox;
    QPushButton *btn_set1;
    QPushButton *btn_get;
    QWidget *page_7;
    QLabel *label;
    QPushButton *btn_start;
    QPushButton *btn_scroll;
    QPushButton *btn_tool;
    QPushButton *btn_tab;
    QPushButton *btn_combox;
    QPushButton *btn_gif;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(758, 588);
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(140, 100, 481, 351));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        verticalLayout_3 = new QVBoxLayout(page_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        tabWidget = new QTabWidget(page_3);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget->addTab(tab_3, QString());

        verticalLayout_3->addWidget(tabWidget);

        stackedWidget->addWidget(page_3);
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        scrollArea = new QScrollArea(page_5);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(160, 90, 171, 181));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 152, 244));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton = new QPushButton(scrollAreaWidgetContents);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_8 = new QPushButton(scrollAreaWidgetContents);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        verticalLayout->addWidget(pushButton_8);

        pushButton_6 = new QPushButton(scrollAreaWidgetContents);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        verticalLayout->addWidget(pushButton_6);

        pushButton_2 = new QPushButton(scrollAreaWidgetContents);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_7 = new QPushButton(scrollAreaWidgetContents);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        verticalLayout->addWidget(pushButton_7);

        pushButton_5 = new QPushButton(scrollAreaWidgetContents);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        verticalLayout->addWidget(pushButton_5);

        pushButton_4 = new QPushButton(scrollAreaWidgetContents);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(scrollAreaWidgetContents);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        scrollArea->setWidget(scrollAreaWidgetContents);
        stackedWidget->addWidget(page_5);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        verticalLayout_2 = new QVBoxLayout(page_4);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        toolBox = new QToolBox(page_4);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        widget = new QWidget();
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 463, 255));
        toolBox->addItem(widget, QString::fromUtf8("\345\256\266\344\272\272"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 463, 255));
        toolBox->addItem(page, QString::fromUtf8("\346\234\213\345\217\213"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 463, 255));
        toolBox->addItem(page_2, QString::fromUtf8("\351\273\221\345\220\215\345\215\225"));

        verticalLayout_2->addWidget(toolBox);

        stackedWidget->addWidget(page_4);
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        comboBox = new QComboBox(page_6);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(220, 120, 69, 22));
        btn_set1 = new QPushButton(page_6);
        btn_set1->setObjectName(QStringLiteral("btn_set1"));
        btn_set1->setGeometry(QRect(220, 170, 71, 21));
        btn_get = new QPushButton(page_6);
        btn_get->setObjectName(QStringLiteral("btn_get"));
        btn_get->setGeometry(QRect(220, 200, 71, 21));
        stackedWidget->addWidget(page_6);
        page_7 = new QWidget();
        page_7->setObjectName(QStringLiteral("page_7"));
        label = new QLabel(page_7);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 80, 241, 181));
        label->setFrameShape(QFrame::Box);
        btn_start = new QPushButton(page_7);
        btn_start->setObjectName(QStringLiteral("btn_start"));
        btn_start->setGeometry(QRect(190, 290, 75, 23));
        stackedWidget->addWidget(page_7);
        btn_scroll = new QPushButton(Widget);
        btn_scroll->setObjectName(QStringLiteral("btn_scroll"));
        btn_scroll->setGeometry(QRect(670, 110, 75, 23));
        btn_tool = new QPushButton(Widget);
        btn_tool->setObjectName(QStringLiteral("btn_tool"));
        btn_tool->setGeometry(QRect(670, 160, 75, 23));
        btn_tab = new QPushButton(Widget);
        btn_tab->setObjectName(QStringLiteral("btn_tab"));
        btn_tab->setGeometry(QRect(670, 210, 75, 23));
        btn_combox = new QPushButton(Widget);
        btn_combox->setObjectName(QStringLiteral("btn_combox"));
        btn_combox->setGeometry(QRect(670, 250, 75, 23));
        btn_gif = new QPushButton(Widget);
        btn_gif->setObjectName(QStringLiteral("btn_gif"));
        btn_gif->setGeometry(QRect(670, 290, 75, 23));

        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(4);
        tabWidget->setCurrentIndex(2);
        toolBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Widget", "\350\205\276\350\256\257", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Widget", "\347\275\221\346\230\223", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Widget", "\347\231\276\345\272\246", 0));
        pushButton->setText(QApplication::translate("Widget", "PushButton", 0));
        pushButton_8->setText(QApplication::translate("Widget", "PushButton", 0));
        pushButton_6->setText(QApplication::translate("Widget", "PushButton", 0));
        pushButton_2->setText(QApplication::translate("Widget", "PushButton", 0));
        pushButton_7->setText(QApplication::translate("Widget", "PushButton", 0));
        pushButton_5->setText(QApplication::translate("Widget", "PushButton", 0));
        pushButton_4->setText(QApplication::translate("Widget", "PushButton", 0));
        pushButton_3->setText(QApplication::translate("Widget", "PushButton", 0));
        toolBox->setItemText(toolBox->indexOf(widget), QApplication::translate("Widget", "\345\256\266\344\272\272", 0));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("Widget", "\346\234\213\345\217\213", 0));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("Widget", "\351\273\221\345\220\215\345\215\225", 0));
        btn_set1->setText(QApplication::translate("Widget", "\350\256\276\347\275\256\344\270\272\345\214\227\344\272\254", 0));
        btn_get->setText(QApplication::translate("Widget", "\350\216\267\345\217\226\345\275\223\345\211\215", 0));
        label->setText(QString());
        btn_start->setText(QApplication::translate("Widget", "\346\222\255\346\224\276", 0));
        btn_scroll->setText(QApplication::translate("Widget", "\346\214\211\351\222\256\347\273\204", 0));
        btn_tool->setText(QApplication::translate("Widget", "\350\201\212\345\244\251\346\241\206", 0));
        btn_tab->setText(QApplication::translate("Widget", "\347\275\221\351\241\265", 0));
        btn_combox->setText(QApplication::translate("Widget", "\344\270\213\346\213\211\346\241\206", 0));
        btn_gif->setText(QApplication::translate("Widget", "gif\345\212\250\345\233\276", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
