#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPen>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setFixedSize(400,210);
    setWindowTitle("假的奥运五环");
    setWindowIcon(QIcon(":/1.png"));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);
    painter->setRenderHint(QPainter::HighQualityAntialiasing);

    QPen pen(Qt::blue);
    pen.setWidth(10);
    painter->setPen(pen);
    painter->drawEllipse(QPoint(80,80),50,50);

    pen.setColor(Qt::black);
    painter->setPen(pen);
    painter->drawEllipse(QPoint(200,80),50,50);

    pen.setColor(Qt::red);
    painter->setPen(pen);
    painter->drawEllipse(QPoint(320,80),50,50);

    pen.setColor(Qt::yellow);
    painter->setPen(pen);
    painter->drawEllipse(QPoint(140,130),50,50);

    pen.setColor(Qt::green);
    painter->setPen(pen);
    painter->drawEllipse(QPoint(260,130),50,50);

    pen.setWidth(2);
    pen.setStyle(Qt::DotLine);
    pen.setColor(Qt::cyan);
    painter->setPen(pen);
    painter->drawRect(QRect(QPoint(20,20),QPoint(380,190)));
}
