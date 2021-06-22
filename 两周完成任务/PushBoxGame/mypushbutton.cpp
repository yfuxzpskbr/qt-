#include "mypushbutton.h"
#include <QPixmap>
#include <QPropertyAnimation>

myPushButton::myPushButton(QString ImagePath1, QString ImagePath2)
{
    //储存
    this->path1 = ImagePath1;
    this->path2 = ImagePath2;
    //加载按钮背景图
    QPixmap pix;
    pix.load(ImagePath1);

    //设置按钮大小
    this->setFixedSize(pix.width(),pix.height());
    //设置不规则按钮
    this->setStyleSheet("QPushButton { border: 0px;}");
    //设置图标
    this->setIcon(pix);
    //设置图标大小
    this->setIconSize(QSize(pix.width(),pix.height()));
}

void myPushButton::bounce()
{
    //新建一个动画类
    QPropertyAnimation * animation1 = new QPropertyAnimation(this,"geometry");
    //设置动画间隔
    animation1->setDuration(300);
    //设置初始位置
    animation1->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //设置末位置
    animation1->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //设置曲线
    animation1->setEasingCurve(QEasingCurve::OutBack);
    //开始
    animation1->start();

    //新建一个动画类
    QPropertyAnimation * animation2 = new QPropertyAnimation(this,"geometry");
    //设置动画间隔
    animation2->setDuration(300);
    //设置初始位置
    animation2->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //设置末位置
    animation2->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //设置曲线
    animation2->setEasingCurve(QEasingCurve::OutBack);
    //开始
    animation2->start();
}

void myPushButton::mousePressEvent(QMouseEvent *e)
{
    if(this->path2 != ""){
        QPixmap pix;
        pix.load(this->path2);

        //设置按钮大小
        this->setFixedSize(pix.width(),pix.height());
        //设置不规则按钮
        this->setStyleSheet("QPushButton { border: 0px;}");
        //设置图标
        this->setIcon(pix);
        //设置图标大小
        this->setIconSize(QSize(pix.width(),pix.height()));
    }
    return QPushButton::mousePressEvent(e);
}

void myPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    if(this->path2 != ""){
        QPixmap pix;
        pix.load(this->path1);

        //设置按钮大小
        this->setFixedSize(pix.width(),pix.height());
        //设置不规则按钮
        this->setStyleSheet("QPushButton { border: 0px;}");
        //设置图标
        this->setIcon(pix);
        //设置图标大小
        this->setIconSize(QSize(pix.width(),pix.height()));
    }
    return QPushButton::mouseReleaseEvent(e);
}
