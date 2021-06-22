#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->btn_set,&QPushButton::clicked,[=](){
        ui->widget->setValue(74);
    });
    connect(ui->btn_get,&QPushButton::clicked,[=](){
        qDebug()<<ui->widget->getValue();
    });
}

Widget::~Widget()
{
    delete ui;
}
