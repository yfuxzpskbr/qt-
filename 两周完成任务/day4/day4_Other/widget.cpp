#include "widget.h"
#include "ui_widget.h"
#include "QPushButton"
#include <QDebug>
#include <QMovie>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(4);
    connect(ui->btn_scroll,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(1);
    });
    connect(ui->btn_tab,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->btn_tool,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(2);
    });

    ui->comboBox->addItem("重庆");
    ui->comboBox->addItem("北京");
    ui->comboBox->addItem("上海");
    ui->comboBox->addItem("天津");

    connect(ui->btn_combox,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(3);
    });

    connect(ui->btn_set1,&QPushButton::clicked,[=](){
       // ui->comboBox->setCurrentIndex(1);
        ui->comboBox->setCurrentText("北京");
    });

    connect(ui->btn_get,&QPushButton::clicked,[=](){
        qDebug()<< ui->comboBox->currentText().toUtf8().data();
    });


    QMovie *movie = new QMovie(":/Image/mario");
    ui->label->setMovie(movie);
    connect(ui->btn_start,&QPushButton::clicked,[=](){
        movie->start();
    });

    connect(ui->btn_gif,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(4);
    });
}

Widget::~Widget()
{
    delete ui;
}
