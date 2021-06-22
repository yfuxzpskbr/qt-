#include "chooselevel.h"
#include "ui_chooselevel.h"
#include "mypushbutton.h"
#include <QPixmap>
#include <QPainter>
#include <QTimer>
#include <QLabel>
#include <QSound>
#include <QDebug>


chooseLevel::chooseLevel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::chooseLevel)
{
    ui->setupUi(this);

    //设置窗口固定大小
    this->setFixedSize(500,500);
    //设置窗口图标
    this->setWindowIcon(QIcon(":/res/rabbit.png"));
    //设置退出菜单项图标
    ui->actionQuit->setIcon(QIcon(":/res/start.png"));
    //退出菜单项
    connect(ui->actionQuit , &QAction::triggered,this,close);

    //加载选择关卡按钮的音效
    QSound *levelSound = new QSound(":/res/levelBtn.wav",this);
    //加载返回按钮音效
    QSound *backSound = new QSound(":/res/backBtn.wav",this);

    //返回按钮
    myPushButton *backBtn = new myPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width()-backBtn->width()-10,this->height() - backBtn->height() -10);
    //返回按钮实现事件
    connect(backBtn,&QPushButton::clicked,[=](){
        //播放音效
        backSound->play();
        //延时触发返回
        QTimer::singleShot(200,this,[=](){
            emit this->back();
        });
    });

    //显示关卡数
    for(int i=0 ; i< 25 ;i++){
        //选关按钮
        myPushButton *levelBtn = new myPushButton(":/res/chooseBackground.png");
        levelBtn->setParent(this);
        levelBtn->move(108+(levelBtn->width()+5)*(i%5),140+(levelBtn->height()+5) *(i/5));
        //选关标签 用于放关卡数字
        QLabel * lab = new QLabel(this);
        //设置标签字体
        lab->setFont(QFont("Microsoft Yahei",20,50,false));
        //设置颜色
        lab->setStyleSheet("QLabel {color : white; }");  //样式表
        //设置固定大小
        lab->setFixedSize(levelBtn->width(),levelBtn->height());
        //设置对齐方式  居中对齐
        lab->setAlignment(Qt::AlignCenter);
        //移动到适当位置
        lab->move(108+(levelBtn->width()+5)*(i%5),140+(levelBtn->height()+5) *(i/5));
        //设置文本
        lab->setText(QString::number(i+1));
        //给Label设置穿透
        lab->setAttribute(Qt::WA_TransparentForMouseEvents);

        //实现点击关卡序号进入关卡
        connect(levelBtn,&QPushButton::clicked,[=](){
            //播放音效
            levelSound->play();
            //创建游戏场景
            Game = new gameSence(i+1);
            //隐藏本界面显示游戏场景
            this->hide();
            Game->setGeometry(this->geometry());
            Game->show();
            //监听游戏界面的返回信号
            connect(Game,&gameSence::back,[=](){
                //delete游戏界面显示本界面
                this->setGeometry(Game->geometry());
                delete Game;
                this->show();
            });
        });


    }

}

chooseLevel::~chooseLevel()
{
    delete ui;
}

void chooseLevel::paintEvent(QPaintEvent *)
{
    //加载背景图
    QPixmap pix;
    pix.load(":/res/background.png");
    //画家画背景
    QPainter painter(this);
    painter.drawPixmap(0,0,pix.width(),pix.height(),pix);
    //加载标题图
    pix.load(":/res/title.png");
    //画家画标题
    painter.drawPixmap(20,30,pix.width()*0.5,pix.height()*0.5,pix);
}
