#include "mylabel.h"
#include <QDebug>
#include <QString>
#include <QMouseEvent>

myLabel::myLabel(QWidget *parent) : QLabel(parent)
{
    //setMouseTracking(true);
}
void myLabel::enterEvent(QEvent *event){
    qDebug()<<"鼠标进入了";
}

void myLabel::leaveEvent(QEvent *event){
    qDebug()<<"鼠标离开了";
}

void myLabel::mouseMoveEvent(QMouseEvent *ev){
    QString str = QString("鼠标移动到了:(%1,%2)").arg(ev->x()).arg(ev->y());
    qDebug()<<str.toUtf8().data();
}

void myLabel::mousePressEvent(QMouseEvent *ev){

    switch(ev->button()){
    case Qt::LeftButton:
        qDebug()<<"鼠标在("<<ev->x()<<","<<ev->y()<<")"<<"处按下了左键";
        break;
    case Qt::RightButton:
        qDebug()<<"鼠标在("<<ev->x()<<","<<ev->y()<<")"<<"处按下了右键";
        break;
    case Qt::MidButton:
        qDebug()<<"鼠标在("<<ev->x()<<","<<ev->y()<<")"<<"处按下了滚轮键";
        break;
    case Qt::BackButton:
        qDebug()<<"鼠标在("<<ev->x()<<","<<ev->y()<<")"<<"处按下了后退键";
        break;
    case Qt::ForwardButton:
        qDebug()<<"鼠标在("<<ev->x()<<","<<ev->y()<<")"<<"处按下了前进键";
        break;
    }

}

void myLabel::mouseReleaseEvent(QMouseEvent *ev){
    switch(ev->button()){
    case Qt::LeftButton:
        qDebug()<<"鼠标在("<<ev->x()<<","<<ev->y()<<")"<<"处释放了左键";
        break;
    case Qt::RightButton:
        qDebug()<<"鼠标在("<<ev->x()<<","<<ev->y()<<")"<<"处释放了右键";
        break;
    case Qt::MidButton:
        qDebug()<<"鼠标在("<<ev->x()<<","<<ev->y()<<")"<<"处释放了滚轮键";
        break;
    case Qt::BackButton:
        qDebug()<<"鼠标在("<<ev->globalX()<<","<<ev->globalY()<<")"<<"处释放了后退键";
        break;
    case Qt::ForwardButton:
        qDebug()<<"鼠标在("<<ev->x()<<","<<ev->y()<<")"<<"处释放了前进键";
        break;
    }
}

bool myLabel::event(QEvent *e)
{

    if(e->type() == QEvent::MouseButtonPress){
        QMouseEvent *ev = static_cast<QMouseEvent*>(e);
        qDebug()<<QString("在event::鼠标在(%1,%2)处按下").arg(ev->x()).arg(ev->y());
        return true;
    }
    return QLabel::event(e);
}

