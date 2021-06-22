#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QString>
#include <QFile>
#include <QIODevice>
#include <QTextEdit>
#include <QFileInfo>
#include <QDebug>
#include <QDateTime>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
        QString path("C:\\Users\\安慕忆风尘\\OneDrive\\桌面\\离骚.txt");
        QFile file(path);
        file.open(QIODevice::WriteOnly);
        QByteArray array;
        array += ui->textEdit->toPlainText();
        file.write(array);
        file.close();
    });

    connect(ui->pushButton_3,&QPushButton::clicked,[=](){
        QString path = QFileDialog::getSaveFileName(this,"另存为","./未命名1.txt","文本文档(*.txt)");
        QFile file(path);
        file.open(QIODevice::WriteOnly);
        QByteArray array;
        array += ui->textEdit->toPlainText();
        file.write(array);
        file.close();
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this,"打开文件");
    QFileInfo info(path);
    ui->lineEdit->setText(info.fileName());
    qDebug()<<" 文件大小："<<info.size()<<" 文件路径："<<info.filePath()<<" 文件后缀名："<<info.suffix()
           <<" 文件创建日期："<<info.created().toString("yyyy-MM-dd hh:mm:ss")
            <<" 文件修改日期："<<info.lastModified().toString("yyyy-MM-dd hh:mm:ss");
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    QByteArray array;
    while(!file.atEnd()){
        array += file.readLine();
    }
    ui->textEdit->setText(array);
    file.close();
}

