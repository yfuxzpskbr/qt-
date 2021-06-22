#include "student.h"
#include <QDebug>
student::student(QObject *parent) : QObject(parent)
{

}


void student::treat(){
    qDebug()<<"老师饿了，学生请老师吃饭！";
}

void student::treat(QString food){
    qDebug()<<"老师饿了，学生请老师吃"<<food.toUtf8().data();
}
