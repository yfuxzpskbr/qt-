#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
#include <QDebug>
#include <QString>
#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    [=](){
        ui->label->setFont(QFont("宋体",80,50));
        ui->label_2->setFont(QFont("宋体",80,50));
        ui->label_3->setFont(QFont("宋体",80,50));
        ui->label_4->setFont(QFont("宋体",80,50));

        ui->label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->label_2->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->label_3->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->label_4->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

        ui->label->setText("0");
        ui->label_2->setText("0");
        ui->label_3->setText("0");
        ui->label_4->setText("0");

        sec_1 = 0;
        sec_2 = 0;
        min_1 = 0;
        min_2 = 0;
        sec   = false;
        sec2  = false;
        min   = false;
    }();


    QTimer *timer_sec_1 = new QTimer(this);
    connect(timer_sec_1,&QTimer::timeout,[=](){
        ++sec_1;
        if(sec_1 == 10){
            sec   = true;
            sec_1 = 0;
        }
        ui->label->setText(QString::number(sec_1));
    });


    connect(timer_sec_1,&QTimer::timeout,[=](){
        if(sec == true)
        {
            ++sec_2;
            sec = false;
        }
        if(sec_2 == 10){
             sec_2 = 0;
             sec2  = true;
        }
        ui->label_2->setText(QString::number(sec_2));
    });

    connect(timer_sec_1,&QTimer::timeout,[=](){
        if(sec2 == true){
            ++min_1;
            sec2 = false;
        }
        if(min_1 == 10){
            min_1 = 0;
            min   = true;
        }
        ui->label_3->setText(QString::number(min_1));
    });

    connect(timer_sec_1,&QTimer::timeout,[=](){
        if(min == true){
            ++min_2;
            min = false;
        }
        if(min_2 == 6) min_2 = 0;
        ui->label_4->setText(QString::number(min_2));
    });

    connect(ui->pushButton,&QPushButton::clicked,[=](){
        timer_sec_1->setTimerType(Qt::PreciseTimer);
        timer_sec_1->start(10);
    });

    connect(ui->pushButton_3,&QPushButton::clicked,[=](){
        timer_sec_1->stop();
    });
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
        static int cnt=0;
        qDebug()<<QString("第%1次计次：%2%3:%4%5").arg(++cnt)
                  .arg(ui->label_4->text()).arg(ui->label_3->text())
                  .arg(ui->label_2->text()).arg(ui->label->text()).toUtf8().data();
    });
    connect(ui->pushButton_4,&QPushButton::clicked,[=](){
        timer_sec_1->stop();
        ui->label->setText("0");
        ui->label_2->setText("0");
        ui->label_3->setText("0");
        ui->label_4->setText("0");
    });
}

Widget::~Widget()
{
    delete ui;
}
