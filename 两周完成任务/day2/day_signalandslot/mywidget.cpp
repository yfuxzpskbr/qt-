#include "mywidget.h"
#include <QPushButton>
myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *btn=new QPushButton;
    btn->setParent(this);
    btn->setText("关闭");
    this->resize(800,600);
    btn->move(0,0);
    connect(btn,&QPushButton::clicked,this,&QWidget::close);

    QPushButton *btn2=new QPushButton;
    btn2->setParent(this);
    btn2->setText("最大化");
    this->resize(800,600);
    btn2->move(100,0);
    connect(btn2,&QPushButton::clicked,this,&QWidget::showMaximized);

    QPushButton *btn3=new QPushButton;
    btn3->setParent(this);
    btn3->setText("最小化");
    this->resize(800,600);
    btn3->move(200,0);
    connect(btn3,&QPushButton::clicked,this,&QWidget::showMinimized);

}

myWidget::~myWidget()
{

}
