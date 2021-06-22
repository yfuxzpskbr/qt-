#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPushButton>
#include <QTimer>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setFixedSize(1000,400);
//    ui->pushButton->setAutoRepeat(true);
//    ui->pushButton->setAutoRepeatDelay(100);
//    connect(ui->pushButton,&QPushButton::clicked,[=](){
//        Posx+=10;
//        if(Posx>this->width())
//            Posx=0;
//        update();
//    });
    //////// 第二类定时器 //////////
//    QTimer *timer = new QTimer(this);
//    connect(timer,&QTimer::timeout,[=](){
//        Posx+=10;
//        if(Posx>this->width())
//            Posx=0;
//        update();
//    });
//    timer->start(300);


    startTimer(100);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(Posx,100,QPixmap(":/1.jpg"));
}

void Widget::timerEvent(QTimerEvent *)
{
    Posx+=10;
    if(Posx>this->width())
        Posx=0;
    update();
}
