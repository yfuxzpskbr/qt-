#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMessageBox>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pushButton->setCheckable(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked(bool checked)
{
    if(checked){
        int score=0;
        if(ui->radioButton_2->isChecked() == true ){
            score+=50;
        }
        if(ui->checkBox_2->isChecked() == true && ui->checkBox->isChecked() == false){
            score+=10;
        }
        if(ui->checkBox_3->isChecked() == true && ui->checkBox->isChecked() == false){
            score+=20;
        }
        if(ui->checkBox_4->isChecked() == true && ui->checkBox->isChecked() == false){
            score+=20;
        }
        QString str="你的分数是：";
        str.append(QString::number(score));
        if(QMessageBox::Help == QMessageBox::information(this,"结果",str,
                                QMessageBox::Ok|QMessageBox::Help,QMessageBox::Ok))
        {
            QString str2="1、你确定是绝对值而不是行列式？\n2、你自己去百度吧";
            QMessageBox::information(this,"解析",str2);
        }

    }

   // ui->pushButton->setCheckable(false);
}
