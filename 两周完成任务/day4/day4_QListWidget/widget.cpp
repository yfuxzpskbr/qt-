#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
//    QListWidgetItem *item = new QListWidgetItem("闹钟虐我千万遍");
//    item->setTextAlignment(Qt::AlignHCenter);
//    ui->listWidget->addItem(item);
//    QListWidgetItem *item2 = new QListWidgetItem("我对被窝如初恋");
//    item2->setTextAlignment(Qt::AlignHCenter);
//    ui->listWidget->addItem(item2);
      QStringList list;
      list<<"闹钟虐我千万遍"<<"我对被窝如初恋";
      ui->listWidget->addItems(list);

}

Widget::~Widget()
{
    delete ui;
}
