/**
 * @note 自定义按钮类
 */

#include "mypushbutton.h"

MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
{

}

/**
 * 自定义按钮的构造函数
 * @brief MyPushButton::MyPushButton
 * @param path 按钮图标的路径
 */
MyPushButton::MyPushButton(QString path)
{
    ///设置按钮图标和按钮大小
    this->setFixedSize(150,75);
    this->setIcon(QIcon(path));
    this->setIconSize(QSize(150,75));

    ///设置边界为0，代表不规则按钮
    this->setStyleSheet("QPushButton{border:0px;}");
}

/**
 * 完成按钮的跳动
 * @brief MyPushButton::bounce
 */
void MyPushButton::bounce()
{
    ///定义一个动画对象
    QPropertyAnimation *animation = new QPropertyAnimation(this,"geometry");
    ///设置动画间隔
    animation->setDuration(100);
    ///设置初始位置
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    ///设置末位置
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    ///设置曲线
    animation->setEasingCurve(QEasingCurve::OutInCubic);
    ///开始跳动
    animation->start();

    ///停止跳动
    animation->stop();
    ///让按钮再跳回来
    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation->start();
}
