#include "mywidget.h"
#include <QString>
#include <QPushButton>
myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    this->stu=new student(this);
    this->tea=new teacher(this);

    void(teacher::*teacherSignal)(QString);
    void(student::*studentSlot)(QString);
    teacherSignal=&teacher::hungry;
    studentSlot=&student::treat;
    //connect(tea,teacherSignal,stu,studentSlot);
    //classOver();

    QPushButton *btn=new QPushButton;
    btn->setText("下课吃饭");
    btn->setParent(this);

    //connect(btn,&QPushButton::clicked,this,&myWidget::classOver);

    void(teacher::*teacherSignal2)(void);
    void(student::*studentSlot2)(void);
    teacherSignal2=&teacher::hungry;
    studentSlot2=&student::treat;
    connect(tea,teacherSignal2,stu,studentSlot2);
    connect(btn,&QPushButton::clicked,tea,teacherSignal2);

}

myWidget::~myWidget()
{

}


void myWidget::classOver(){
    //emit tea->hungry();
    emit tea->hungry("宫爆鸡丁");
}
