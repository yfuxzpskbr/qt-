#include "mycoin.h"
#include <QPixmap>
#include <QString>


myCoin::myCoin(QWidget *parent) : QPushButton(parent)
{

}

myCoin::myCoin(QString adImage)
{
    this->ImagePath = adImage;
    QPixmap pix;
    bool ret = pix.load(this->ImagePath);
    if(!ret){
        return ;
    }
    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));

    connect(timer1,&QTimer::timeout,[=](){
        QString str=QString(":/res/Coin000%1.png").arg(this->start++);
        QPixmap pix(str);
        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border: 0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
        if(start > end){
            start =1;
            timer1->stop();
            this->isAnimation = false;
        }
    });
    connect(timer2,&QTimer::timeout,[=](){
        QString str=QString(":/res/Coin000%1.png").arg(this->end--);
        QPixmap pix(str);
        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border: 0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
        if(end < start){
            timer2->stop();
            end =8;
            this->isAnimation = false;
        }
    });
}

void myCoin::setPosX(int x)
{
    this->posX  = x;
}

void myCoin::setPosY(int y)
{
    this->posY = y;
}

void myCoin::setflag(bool flag)
{
    this->flag = flag;
}

void myCoin::changeFlag()
{

    if(this->flag){
        timer1->start(40);
        this->isAnimation = true;
        this->flag = false;
    }
    else
    {
        timer2->start(40);
        this->isAnimation = true;
        this->flag = true;
    }
}

int myCoin::getPosX()
{
    return posX;
}

int myCoin::getPosY()
{
    return posY;
}

void myCoin::mousePressEvent(QMouseEvent *e){
    if(this->isAnimation || this->isSucceed){
        return ;
    }
    else {
        return QPushButton::mousePressEvent(e);
    }
}

bool myCoin::getFlag()
{
    return this->flag;
}

void myCoin::setIsSucceed(bool t)
{
    this->isSucceed = t;
}
