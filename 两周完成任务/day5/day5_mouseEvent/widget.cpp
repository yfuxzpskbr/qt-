#include "widget.h"
#include "ui_widget.h"
#include <QEvent>
#include <QMouseEvent>
#include <QLabel>
#include <QDebug>
#include <QString>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->installEventFilter(this);
}

bool Widget::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == ui->label){
        if(event->type() ==QEvent::MouseButtonPress ){
            QMouseEvent *ev = static_cast<QMouseEvent*>(event);
            qDebug()<<QString("鼠标在事件过滤器中(%1,%2)处按下了").arg(ev->x()).arg(ev->y());
            return true;
        }
    }
    return QWidget::eventFilter(watched,event);
}



Widget::~Widget()
{
    delete ui;
}
