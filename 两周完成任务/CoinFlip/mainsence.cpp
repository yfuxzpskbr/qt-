#include "mainsence.h"
#include "ui_mainsence.h"
#include "chooselevelsence.h"
#include <QAction>
#include <QIcon>
#include <QPixmap>
#include <QPainter>
#include <mypushbutton.h>
#include <QString>
#include <QPushButton>
#include <QTimer>
#include <QPushButton>
#include <QSound>


MainSence::MainSence(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainSence)
{
    ui->setupUi(this);
    ////////////// 配置主场景 ////////////
    //退出实现
    connect(ui->actionExit,&QAction::triggered,[=](){
        this->close();
    });
    //设置固定大小
    this->setFixedSize(390,590);
    //设置图标
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));
    //设置窗口名称
    this->setWindowTitle("小王翻金币");

    //加载点击开始按钮的音效
    QSound *startsound = new QSound(":/res/TapButtonSound.wav",this);

    chooseLevel = new chooseLevelSence;
    //设置开始按钮
    myPushButton *btn_start = new myPushButton(":/res/MenuSceneStartButton.png");
    btn_start->setParent(this);
    btn_start->move(this->width()*0.5-btn_start->width()*0.5,this->height()*0.7);

    connect(btn_start,&QPushButton::clicked,[=](){
        //播放音效
        startsound->play();
        btn_start->bounce();
        //延迟进入
        QTimer::singleShot(300,this,[=](){
            //隐藏自身
            this->hide();
            //显示关卡界面
            chooseLevel->show();
        });
    });

    //监听选择关卡发出的信号
    connect(chooseLevel,&chooseLevelSence::chooseBack,[=](){
        //隐藏关卡选择
        chooseLevel->hide();
        //显示主场景
        this->show();
    });

}

MainSence::~MainSence()
{
    delete ui;
}

void MainSence::paintEvent(QPaintEvent *)
{
    QPixmap pix;
    //加载背景图
    pix.load(":/res/MenuSceneBg.png");
    //画背景图
    QPainter painter(this);
    painter.drawPixmap(0,0,390,590,pix);
}
