#include "mywidget.h"
#include "ui_mywidget.h"
#include <QPushButton>
#include "mypushbutton.h"
myWidget::myWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myWidget)
{
    QPushButton* btn=new QPushButton;
    btn->setParent(this);
    btn->setText("闹钟虐我千万遍");
    this->setFixedSize(800,600);
    btn->move(200,200);
    btn->resize(100,30);
    myPushButton *btn2=new myPushButton;
    btn2->setParent(this);
    btn2->setText("我对被窝如初恋");
    btn2->move(200,230);
    btn2->resize(100,30);
    ui->setupUi(this);
}

myWidget::~myWidget()
{
    delete ui;
}
