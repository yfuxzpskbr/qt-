#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton *btn = new QPushButton(this);
    btn->setText("最大化");
    btn->setCheckable(true);
    connect(btn,&QPushButton::clicked,this,[=](bool checked){
        if(checked){
            showMaximized();
        }
        else {
            showNormal();
        }
    });

}

Widget::~Widget()
{
    delete ui;
}
