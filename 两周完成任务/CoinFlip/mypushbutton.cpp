#include "mypushbutton.h"
#include <QPixmap>
#include <QDebug>
#include <QPropertyAnimation>
#include <QSize>

myPushButton::myPushButton(QWidget *parent) : QPushButton(parent)
{

}

myPushButton::myPushButton(QString normalImage, QString pressedImage)
{
    this->normalImagePath = normalImage;
    this->pressedImagePath = pressedImage;
    QPixmap pix;
    bool ret = pix.load(normalImage);
    if(!ret){
        //qDebug()<<"图片加载失败";
        return ;

    }
    //设置固定大小
    this->setFixedSize(pix.width(),pix.height());
    //设置不规则按钮
    this->setStyleSheet("QPushButton{border: 0px;}");
    //设置图标
    this->setIcon(QIcon(pix));
    //设置图标大小
    this->setIconSize(QSize(pix.width(),pix.height()));

}

void myPushButton::bounce()
{
    //新建动画类
    QPropertyAnimation *animation = new QPropertyAnimation(this,"geometry");
    //设置动画间隔
    animation->setDuration(100);
    //设置起始位置
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //设置目的位置
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //设置曲线
    animation->setEasingCurve(QEasingCurve::OutElastic);
    animation->start();


    QPropertyAnimation *animation2 = new QPropertyAnimation(this,"geometry");
    //设置动画间隔
    animation->setDuration(100);
    //设置起始位置
    animation2->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //设置目的位置
    animation2->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //设置曲线
    animation2->setEasingCurve(QEasingCurve::OutElastic);
    animation2->start();
}

void myPushButton::mousePressEvent(QMouseEvent *e)
{
    if(this->pressedImagePath != ""){
        QPixmap pix;
        bool ret = pix.load(this->pressedImagePath);
        if(!ret){
            //qDebug()<<"图片加载失败";
            return ;
        }
        //设置固定大小
        this->setFixedSize(pix.width(),pix.height());
        //设置不规则按钮
        this->setStyleSheet("QPushButton{border:0px}");
        //设置图标
        this->setIcon(pix);
        //设置图标大小
        this->setIconSize(QSize(pix.width(),pix.height()));
    }
    return QPushButton::mousePressEvent(e);
}

void myPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    if(this->pressedImagePath != ""){
        QPixmap pix;
        bool ret = pix.load(this->normalImagePath);
        if(!ret){
            //qDebug()<<"图片加载失败";
            return ;
        }
        //设置按钮大小
        this->setFixedSize(pix.width(),pix.height());
        //设置不规则按钮
        this->setStyleSheet("QPushButton{border:0px}");
        //设置图标
        this->setIcon(pix);
        //设置图标大小
        this->setIconSize(QSize(pix.width(),pix.height()));
    }
    return QPushButton::mouseReleaseEvent(e);
}

