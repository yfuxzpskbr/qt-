#include "mainscene.h"
#include "ui_mainscene.h"
#include "mypushbutton.h"

#include <QPixmap>
#include <QPainter>
#include <QDebug>
#include <QTimer>
#include <QSound>

MainScene::MainScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainScene)
{
    ui->setupUi(this);

    //设置窗口固定大小
    this->setFixedSize(500,500);

    //关闭按钮
    connect(ui->actionQuit,&QAction::triggered,this,&close);

    //创建开始按钮
    myPushButton *btnStart = new myPushButton(":/res/startBtn.png");
    //按钮加到对象树
    btnStart->setParent(this);
    //移动按钮到固定位置
    btnStart->move((this->width() - btnStart->width()) * 0.5 , this->height() * 0.7);

    //加载开始按钮音效
    QSound *startSound = new QSound(":/res/startBtn.wav",this);

    //创建选择关卡的界面
    choose_Level = new chooseLevel(this);


    //点击按钮事件
    connect(btnStart,&QPushButton::clicked,[=](){
        //按钮跳动
        btnStart->bounce();
        startSound->play();
        //延时300ms
        QTimer::singleShot(300,this,[=](){


            //隐藏本界面，显示选择关卡
            this->hide();
            choose_Level->setGeometry(this->geometry());
            choose_Level->show();

        });
    });
    //监听选择关卡界面的返回
    connect(choose_Level,&chooseLevel::back,[=](){
        //显示本窗口隐藏选择关卡
        choose_Level->hide();
        this->setGeometry(choose_Level->geometry());
        this->show();
    });
}

MainScene::~MainScene()
{
    delete ui;
}

void MainScene::paintEvent(QPaintEvent *)
{
    //加载背景图片
    QPixmap pix;
    pix.load(":/res/background.png");
    //画家画背景
    QPainter painter(this);
    painter.drawPixmap(0,0,pix.width(),pix.height(),pix);

    //画题目
    pix.load(":/res/title.png");
   painter.drawPixmap(0.5 * (this->width() - pix.width()),100,pix.width(),pix.height(),pix);
}
