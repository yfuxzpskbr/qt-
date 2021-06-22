#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>
#include <QPainter>
#include <QBitmap>
#include <QImage>
#include <QPicture>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //////////////   QPixmap绘图设备   /////////////
//    QPixmap pix(300,300);
//    QPainter painter(&pix);
//    pix.fill(Qt::white);
//    painter.setPen(QPen(Qt::blue));
//    painter.drawRect(QRect(QPoint(20,20),QPoint(200,200)));
//    pix.save("D:\\my.png");

    //////////////   QBitmap绘图设备   /////////////
//    QBitmap bit(300,300);
//    bit.fill(Qt::white);
//    QPainter painter(&bit);
//    painter.setPen(QPen(Qt::red));
//    painter.drawEllipse(QPoint(100,100),80,80);
//    bit.save("D:\\my2.png");

    //////////////   QImage绘图设备   /////////////
//    QImage img(300,300,QImage::Format_RGB32);
//    QPainter painter(&img);
//    img.fill(Qt::red);
//    painter.setPen(QPen(Qt::cyan));
//    painter.drawEllipse(QPoint(100,100),80,80);
//    img.save("D:\\my3.png");

    ///////////// QPicture 用于保存和重现指令
    QPicture pic;
    QPainter painter;
    painter.begin(&pic);
    painter.setPen(QPen(Qt::green));
    painter.drawEllipse(QPoint(100,100),20,20);
    painter.end();
    //保存到磁盘
    pic.save("D:\\my.jh");

}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    ////////  QImage可以修改像素  //////////
//    QImage img;
//    img.load(":/1.jpg");
//    for(int i=50;i<100;i++){
//        for(int j=50;j<100;j++){
//            img.setPixel(QPoint(i,j),qRgb(255,255,0));
//        }
//    }
//    QPainter painter(this);
//    painter.drawImage(20,20,img);

    /////// 重现QPicture指令 //////
    QPicture pic;
    pic.load("D:\\my.jh");
    QPainter painter(this);
    painter.drawPicture(QPoint(20,20),pic);


}
