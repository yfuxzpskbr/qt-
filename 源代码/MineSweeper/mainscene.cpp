/**
 * @note 主场景类
 */

#include "mainscene.h"
#include "ui_mainscene.h"

MainScene::MainScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainScene)
{
    ui->setupUi(this);
    ///设置图标
    this->setWindowIcon(QIcon(":/res/MineClearance.png"));
    ///设置窗口固定大小
    this->setFixedSize(600,450);

    ///加载标题
    this->loadTitle();

    ///实现退出按钮
    connect(ui->actionQuit,&QAction::triggered,this,&QWidget::close);

    ///新建简单模式按钮
    MyPushButton *easyBtn = new MyPushButton(":/res/EasyBtn.png");
    easyBtn->setParent(this);

    ///新建一般模式按钮
    MyPushButton *commonBtn = new MyPushButton(":/res/CommonBtn.png");
    commonBtn->setParent(this);

    ///新建困难模式
    MyPushButton *difficultBtn = new MyPushButton(":/res/DifficultBtn.png");
    difficultBtn->setParent(this);

    ///按钮移动到对应位置
    easyBtn->move(60,300);
    commonBtn->move(230,300);
    difficultBtn->move(400,300);

    ///实现简单按钮功能
    connect(easyBtn,&QPushButton::clicked,[=](){
        easyBtn->bounce();
//        qDebug()<<"你选择了简单模式";

        this->easy = new EasyPattern();

        ///延时确保按钮已跳动
        QTimer::singleShot(250,this,[=](){
            easy->setGeometry(this->geometry());
            easy->show();
            this->hide();

            ///监听返回信号
            connect(easy,&EasyPattern::back,[=](){
                this->setGeometry(easy->geometry());
                this->show();
                delete easy;
            });
        });
    });

    ///实现一般按钮功能
    connect(commonBtn,&QPushButton::clicked,[=](){
        commonBtn->bounce();
//        qDebug()<<"你选择了一般模式";
        this->common = new CommonPattern();

        ///延时确保按钮已跳动
        QTimer::singleShot(250,this,[=](){
            common->setGeometry(this->geometry());
            common->show();
            this->hide();

            ///监听返回信号
            connect(common,&CommonPattern::back,[=](){
                this->setGeometry(common->geometry());
                this->show();
                delete common;
            });
        });
    });

    ///实现困难按钮功能
    connect(difficultBtn,&QPushButton::clicked,[=](){
        difficultBtn->bounce();
//        qDebug()<<"你选择了困难模式";
        this->difficult = new DifficultPattern();

        ///延时确保按钮已跳动
        QTimer::singleShot(250,this,[=](){
            difficult->show();
            this->hide();

            ///监听返回信号
            connect(difficult,&DifficultPattern::back,[=](){
                this->show();
                delete difficult;
            });
        });
    });

}

MainScene::~MainScene()
{
    delete ui;
}

/**
 * 绘制窗口背景
 * @brief MainScene::paintEvent
 * @param QPaintEvent* //不需要使用参数，故不需要指定变量名
 */
void MainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this); ///定义画家对象
    QPixmap pix;    ///定义图片对象
    pix.load(":/res/BackGround.png");   ///加载背景图片
    painter.drawPixmap(0,0,pix.width(),pix.height(),pix);   ///画家画背景
}

/**
 * 通过动画类加载“经典扫雷”的标题
 * @brief MainScene::loadTitle
 */
void MainScene::loadTitle()
{
    QPixmap pix;
    pix.load(":/res/Title.png");   ///加载标题图片
    //pix = pix.scaled(pix.width()*1.2,pix.height()*1.2);
    QLabel *label = new QLabel(this);
    label->setFixedSize(pix.width(),pix.height());
    label->setPixmap(pix);
    label->move((this->width()-pix.width())*0.5,-label->height());
    QPropertyAnimation *animation = new QPropertyAnimation(label,"geometry");
    animation->setDuration(1000);
    animation->setStartValue(QRect((this->width()-pix.width())*0.5,-label->height(),label->width(),label->height()));
    animation->setEndValue(QRect(QRect((this->width()-pix.width())*0.5,60,label->width(),label->height())));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
}
