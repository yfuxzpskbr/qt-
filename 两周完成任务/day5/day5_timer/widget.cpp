#include "widget.h"
#include "ui_widget.h"
#include <QTimerEvent>
#include <QString>
#include <QFont>
#include <QTimer>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    connect(timer,&QTimer::timeout,[=](){
        static int number_=1;
        ui->label_3->setText(QString::number(number_++));
    });
    connect(ui->btn_begin3,&QPushButton::clicked,[=](){
        timer->start(1000);
    });
    connect(ui->btn_stop3,&QPushButton::clicked,[=](){
        timer->stop();
    });
    ui->label->setFont(QFont("Microsoft YaHei",50,50));
    ui->label_2->setFont(QFont("Microsoft YaHei",50,50,1));
    ui->label_3->setFont(QFont("Microsoft YaHei",50,50,true));
    ui->label->setText("0");
    ui->label_2->setText("0");
    ui->label_3->setText("0");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == id1){
        static int number=1;


        ui->label->setText(QString("%1").arg(number++));
    }
    if(event->timerId() == id2){
        static int number2 = 1;

        ui->label_2->setText(QString::number(number2++));
    }

}

void Widget::on_btn_begin1_clicked()
{
    id1 = startTimer(100);
}


void Widget::on_btn_begin2_clicked()
{
    id2 = startTimer(100);

}
