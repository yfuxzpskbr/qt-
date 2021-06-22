#include "mypushbutton.h"
#include <QPushButton>
#include <QDebug>
myPushButton::myPushButton(QPushButton *parent) : QPushButton(parent)
{
    qDebug()<<"myPushButton的构造函数被调用\n";
}
myPushButton::~myPushButton(){
    qDebug()<<"myPushButton的析构函数被调用\n";
}
