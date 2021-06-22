#include "widget.h"
#include "ui_widget.h"
#include <QStringList>
#include <QTreeWidget>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->treeWidget->setHeaderLabels(QStringList()<<"高数章节"<<"知识点");
    QTreeWidgetItem *item1 = new QTreeWidgetItem(QStringList()<<"第一章"<<"空间解析几何");
    QTreeWidgetItem *item2 = new QTreeWidgetItem(QStringList()<<"第二章"<<"多元函数");
    QTreeWidgetItem *item3 = new QTreeWidgetItem(QStringList()<<"第三章"<<"重积分");

    ui->treeWidget->addTopLevelItem(item1);
    ui->treeWidget->addTopLevelItem(item2);
    ui->treeWidget->addTopLevelItem(item3);

    QTreeWidgetItem *P1_1 = new QTreeWidgetItem(QStringList()<<"第一节"<<"向量的基本概念");
    QTreeWidgetItem *P1_2 = new QTreeWidgetItem(QStringList()<<"第二节"<<"空间曲线");
    QTreeWidgetItem *P1_3 = new QTreeWidgetItem(QStringList()<<"第三节"<<"空间曲面");


    QTreeWidgetItem *P1_1_1 = new QTreeWidgetItem(QStringList()<<"一"<<"向量的定义");
    QTreeWidgetItem *P1_1_2 = new QTreeWidgetItem(QStringList()<<"二"<<"向量的线性运算");
    QTreeWidgetItem *P1_1_3 = new QTreeWidgetItem(QStringList()<<"三"<<"数量积和向量积");

    P1_1->addChild(P1_1_1);
    P1_1->addChild(P1_1_2);
    P1_1->addChild(P1_1_3);


    item1->addChild(P1_1);
    item1->addChild(P1_2);
    item1->addChild(P1_3);

    QTreeWidgetItem *P2_1 = new QTreeWidgetItem(QStringList()<<"第一节"<<"多元函数基本概念");
    QTreeWidgetItem *P2_2 = new QTreeWidgetItem(QStringList()<<"第二节"<<"多元函数极限");
    QTreeWidgetItem *P2_3 = new QTreeWidgetItem(QStringList()<<"第三节"<<"偏导数");
    QTreeWidgetItem *P2_4 = new QTreeWidgetItem(QStringList()<<"第四节"<<"复合函数偏导数的求法");
    QTreeWidgetItem *P2_5 = new QTreeWidgetItem(QStringList()<<"第五节"<<"隐函数偏导数的求法");
    QTreeWidgetItem *P2_6 = new QTreeWidgetItem(QStringList()<<"第六节"<<"多元函数的极值");

    item2->addChild(P2_1);
    item2->addChild(P2_2);
    item2->addChild(P2_3);
    item2->addChild(P2_4);
    item2->addChild(P2_5);
    item2->addChild(P2_6);



    QTreeWidgetItem *P3_1 =new QTreeWidgetItem(QStringList()<<"第一节"<<"二重积分");
    QTreeWidgetItem *P3_2 =new QTreeWidgetItem(QStringList()<<"第二节"<<"三重积分");
    QTreeWidgetItem *P3_3 =new QTreeWidgetItem(QStringList()<<"第三节"<<"重积分的应用");

    item3->addChild(P3_1);
    item3->addChild(P3_2);
    item3->addChild(P3_3);


}

Widget::~Widget()
{
    delete ui;
}
