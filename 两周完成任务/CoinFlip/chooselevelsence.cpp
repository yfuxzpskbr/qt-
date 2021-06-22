#include "chooselevelsence.h"
#include "mypushbutton.h"
#include <QPixmap>
#include <QIcon>
#include <QPainter>
#include <QMenuBar>
#include <QMenu>
#include <QDebug>
#include <QAction>
#include <QTimer>
#include <QLabel>
#include <QSound>

chooseLevelSence::chooseLevelSence(QWidget *parent) : QMainWindow(parent)
{
    /////////////  配置关卡  //////////////
    this->setFixedSize(390,590);
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));
    this->setWindowTitle("小王翻金币-关卡选择");
    QMenuBar *mBar = menuBar();
    setMenuBar(mBar);
    QMenu *START = mBar->addMenu("开始");
    QAction *exit = START->addAction("退出");
    connect(exit,&QAction::triggered,this,&close);

    //加载返回按钮的音效
    QSound *backsound = new QSound(":/res/BackButtonSound.wav",this);
    //加载选关按钮音效
    QSound *choosesound = new QSound(":/res/TapButtonSound.wav",this);

    //返回按钮
    myPushButton *btn_back = new myPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    btn_back->setParent(this);
    btn_back->move(this->width() - btn_back->width(),this->height() - btn_back->height());
    connect(btn_back,&QPushButton::clicked,[=](){
        //播放返回按钮音效
        backsound->play();
        //延时返回
        QTimer::singleShot(200,this,[=](){
            emit this->chooseBack();
        });
    });
    //选择关卡按钮
    for(int i=0;i<20;i++){
        //创建按钮
        myPushButton *menuBtn = new myPushButton(":/res/LevelIcon.png");
        //加到窗口  设置父亲
        menuBtn->setParent(this);
        //移动位置
        menuBtn->move(60 + i%4 * 70,160 + i/4 * 70);

        //监听事件
        connect(menuBtn,&QPushButton::clicked,[=](){
            //qDebug()<<QString("你选择了第%1关").arg(i+1);
            //播放音效
            choosesound->play();
           // menuBtn->bounce();
            /////////// 进入游戏场景  ////////////
            //新建游戏窗口
            Game = new playGame(i+1);

            //隐藏关卡选择界面
            this->hide();
            //显示游戏界面
            Game->show();
            //监听游戏界面的返回信号
            connect(Game,&playGame::chooseBack,[=](){
                //显示显示关卡界面
                this->show();
                delete Game;
            });

        });




        //创建标签来放文字 标签位于按钮上层会屏蔽按钮的点击事件
        QLabel *label = new QLabel(this);
        //设置标签大小
        label->setFixedSize(menuBtn->width(),menuBtn->height());
        //设置标签文本
        label->setText(QString::number(i+1));
        //移动标签
        label->move(60 + i%4 * 70 , 160 + i/4 * 70);
        //设置对齐方式
        label->setAlignment(Qt::AlignCenter);
        //设置对齐格式
        label->setFont(QFont("微软雅黑",10));

        //设置鼠标穿透
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }
}

void chooseLevelSence::paintEvent(QPaintEvent *){
    ////////// 加载背景  ////////////
    QPainter painter(this);
    QPixmap pix;
    //加载图片
    pix.load(":/res/OtherSceneBg.png");
    //画家画背景
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //画标题
    pix.load(":/res/Title.png");
    painter.drawPixmap(this->width()*0.5-pix.width()*0.5,30,pix);
}
