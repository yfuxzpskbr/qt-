#include "gamesence.h"
#include "dataconfig.h"
#include "mypushbutton.h"
#include <QMap>
#include <QLabel>
#include <QDebug>
#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include <QMenuBar>
#include <QEvent>
#include <QLabel>
#include <QPropertyAnimation>
#include <QSound>
#include <QMouseEvent>

////////////////// 游戏算法实现
////////////////// 下一关和返回上一级
////////////////// 键盘事件  鼠标事件实现下一关
////////////////// 链表


//0上 1下 2左 3右  键盘按下信号
const int Up = 0;
const int Down = 1;
const int Left = 2;
const int Right = 3;

const int row = 7;
const int col = 7;

gameSence::gameSence(int level)
{
    //地图资源
    Data = new dataconfig;
    //设置窗口固定大小
    this->setFixedSize(500,500);
    //设置窗口图标和标题
    this->setWindowIcon(QIcon(":/res/rabbit.png"));
    this->setWindowTitle(QString("第%1关").arg(level));
    //储存关卡数
    this->Level = level;
    //储存关卡地图的行数和列数
    this->I = Data->row[this->Level];
    this->J = Data->col[this->Level];

    //加载返回音效
    QSound *backSound = new QSound(":/res/backBtn.wav",this);
    //加载移动音效
    QSound *moveSound = new QSound(":/res/moveSound.wav",this);
    //加载胜利音效
    QSound *succeedSound = new QSound(":/res/succeedSound.wav",this);

    //菜单栏
    QMenuBar *mBar = menuBar();
    setMenuBar(mBar);
    QMenu *START = mBar->addMenu("开始");
    QAction *Quit = START->addAction("退出");
    Quit->setIcon(QIcon(":/res/start.png"));

    //退出按钮实现
    connect(Quit,&QAction::triggered,this,&close);

    //返回按钮
    myPushButton *backBtn = new myPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width() - backBtn->width() - 10,this->height() - backBtn->height() -10);
    //返回按钮的点击事件
    connect(backBtn,&QPushButton::clicked,[=](){
        //播放音效
        backSound->play();
        //延迟发送返回信号
        QTimer::singleShot(200,this,[=](){
            //如果游戏没赢就可以按下，游戏赢了就禁止按下
            if(Win == false)
                emit this->back();
        });
    });

    //保存地图
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            map[i][j] = new int(Data->mapdata[this->Level][i][j]);
            if(*(map[i][j]) == 3 || *(map[i][j]) == 7){
                this->boxcnt++;//统计箱子个数
            }
        }
//        qDebug()<<*(map[i][0])<<*(map[i][1])<<*(map[i][2])<<*(map[i][3])<<*(map[i][4])
//                <<*(map[i][5])<<*(map[i][6]);
        qDebug()<<"boxcnt: "<<this->boxcnt;
    }

    //画地图
    int defX = (this->width()-this->J*50)*0.5; //初始x位置
    int defY = (this->height()-this->I*50)*0.5 +10;  //初始y位置
    qDebug()<<"I ="<<I<<" J ="<<J;
    qDebug()<<"defX = "<<defX<<" defY = "<<defY;
    //画图
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            //画地图
            Item * it = new Item();//Item是地图元素类 ：空地 人 箱子 ...
            dmap[i][j] = it;
            dmap[i][j]->setParent(this);
            dmap[i][j]->SetmyIcon(*(map[i][j]));
            dmap[i][j]->setPos(i,j);
            dmap[i][j]->move(defX + 50 *j ,defY + 50*i);
        }
        qDebug()<<*(map[i][0])<<*(map[i][1])<<*(map[i][2])<<*(map[i][3])<<*(map[i][4])
                <<*(map[i][5])<<*(map[i][6]);
    }

    qDebug()<<this->playerPosX<<this->playerPosY;
    //捕获键盘事件
    this->grabKeyboard();
    //函数指针指向-->信号函数
    void (gameSence:: *sig)(int) = &gameSence::MOVE;

    /////////////// 整个游戏核心代码 //////////////推箱子的实现
    connect(this,sig,[=](int m){
        //播放音效
        moveSound->play();
        this->incnt =0;
        //每次都找到人的位置
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(*(map[i][j])==2 || *(map[i][j])==6){
                    playerPosX = i;
                    playerPosY = j;
                    break;
                }
            }
        }
        //上
        if(m == Up){
            qDebug()<<"Up";
            //如果向上是空地或目的地
            if(*(map[playerPosX-1][playerPosY]) == 0 || *(map[playerPosX-1][playerPosY])==4){
                //更新地图
                *(map[playerPosX-1][playerPosY]) += 2;
                *(map[playerPosX][playerPosY]) -=2;

                //类似于地图重绘
                qDebug()<<"---"<<*(map[playerPosX][playerPosY]) ;
                dmap[playerPosX-1][playerPosY]->SetmyIcon(*(map[playerPosX-1][playerPosY]));
                dmap[playerPosX][playerPosY]->SetmyIcon(*(map[playerPosX][playerPosY]));
            }
            //如果向上是箱子
            else if(*(map[playerPosX-1][playerPosY]) == 3 || *(map[playerPosX-1][playerPosY])==7){
                if(*(map[playerPosX-2][playerPosY]) == 0 || *(map[playerPosX-2][playerPosY])==4){
                    *(map[playerPosX-2][playerPosY]) += 3;
                    *(map[playerPosX-1][playerPosY]) -= 1;
                    *(map[playerPosX][playerPosY]) -= 2;
                    dmap[playerPosX-2][playerPosY]->SetmyIcon(*(map[playerPosX-2][playerPosY]));
                    dmap[playerPosX-1][playerPosY]->SetmyIcon(*(map[playerPosX-1][playerPosY]));
                    dmap[playerPosX][playerPosY]->SetmyIcon(*(map[playerPosX][playerPosY]));
                }
            }

        }
        //下
        if(m == Down){
            qDebug()<<"Down";
            //如果向下是空地或目的地
            if(*(map[playerPosX+1][playerPosY]) == 0 || *(map[playerPosX+1][playerPosY])==4){
                *(map[playerPosX+1][playerPosY]) += 2;
                *(map[playerPosX][playerPosY]) -=2;
                qDebug()<<"---"<<*(map[playerPosX][playerPosY]) ;
                dmap[playerPosX+1][playerPosY]->SetmyIcon(*(map[playerPosX+1][playerPosY]));
                dmap[playerPosX][playerPosY]->SetmyIcon(*(map[playerPosX][playerPosY]));
            }
             //如果向下是箱子
            else if(*(map[playerPosX+1][playerPosY]) == 3 || *(map[playerPosX+1][playerPosY])==7){
                if(*(map[playerPosX+2][playerPosY]) == 0 || *(map[playerPosX+2][playerPosY])==4){
                    *(map[playerPosX+2][playerPosY]) += 3;
                    *(map[playerPosX+1][playerPosY]) -= 1;
                    *(map[playerPosX][playerPosY]) -= 2;
                    dmap[playerPosX+2][playerPosY]->SetmyIcon(*(map[playerPosX+2][playerPosY]));
                    dmap[playerPosX+1][playerPosY]->SetmyIcon(*(map[playerPosX+1][playerPosY]));
                    dmap[playerPosX][playerPosY]->SetmyIcon(*(map[playerPosX][playerPosY]));
                }
            }
        }
        //左
        if(m == Left){
            qDebug()<<"Left";
            //如果向左是空地或目的地
            if(*(map[playerPosX][playerPosY-1]) == 0 || *(map[playerPosX][playerPosY-1])==4){
                *(map[playerPosX][playerPosY-1]) += 2;
                *(map[playerPosX][playerPosY]) -=2;
                qDebug()<<"---"<<*(map[playerPosX][playerPosY]) ;
                dmap[playerPosX][playerPosY-1]->SetmyIcon(*(map[playerPosX][playerPosY-1]));
                dmap[playerPosX][playerPosY]->SetmyIcon(*(map[playerPosX][playerPosY]));
            }
             //如果向下是箱子
            else if(*(map[playerPosX][playerPosY-1]) == 3 || *(map[playerPosX][playerPosY-1])==7){
                if(*(map[playerPosX][playerPosY-2]) == 0 || *(map[playerPosX][playerPosY-2])==4){
                    *(map[playerPosX][playerPosY-2]) += 3;
                    *(map[playerPosX][playerPosY-1]) -= 1;
                    *(map[playerPosX][playerPosY]) -= 2;
                    dmap[playerPosX][playerPosY-2]->SetmyIcon(*(map[playerPosX][playerPosY-2]));
                    dmap[playerPosX][playerPosY-1]->SetmyIcon(*(map[playerPosX][playerPosY-1]));
                    dmap[playerPosX][playerPosY]->SetmyIcon(*(map[playerPosX][playerPosY]));
                }
            }
        }
        //右
        if(m == Right){
            qDebug()<<"Right";
            //如果向右是空地或目的地
            if(*(map[playerPosX][playerPosY+1]) == 0 || *(map[playerPosX][playerPosY+1])==4){
                *(map[playerPosX][playerPosY+1]) += 2;
                *(map[playerPosX][playerPosY]) -=2;
                qDebug()<<"---"<<*(map[playerPosX][playerPosY]) ;
                dmap[playerPosX][playerPosY+1]->SetmyIcon(*(map[playerPosX][playerPosY+1]));
                dmap[playerPosX][playerPosY]->SetmyIcon(*(map[playerPosX][playerPosY]));
            }
             //如果向下是箱子
            else if(*(map[playerPosX][playerPosY+1]) == 3 || *(map[playerPosX][playerPosY+1])==7){
                if(*(map[playerPosX][playerPosY+2]) == 0 || *(map[playerPosX][playerPosY+2])==4){
                    *(map[playerPosX][playerPosY+2]) += 3;
                    *(map[playerPosX][playerPosY+1]) -= 1;
                    *(map[playerPosX][playerPosY]) -= 2;
                    dmap[playerPosX][playerPosY+2]->SetmyIcon(*(map[playerPosX][playerPosY+2]));
                    dmap[playerPosX][playerPosY+1]->SetmyIcon(*(map[playerPosX][playerPosY+1]));
                    dmap[playerPosX][playerPosY]->SetmyIcon(*(map[playerPosX][playerPosY]));
                }
            }
        }
        //统计箱子推到目的地的个数
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(*(map[i][j]) == 7){
                    this->incnt++;
                }
            }
        }
        qDebug()<<"(4,4) ="<<*(map[4][4]);
        qDebug()<<"incnt: "<<this->incnt;
        //如果箱子个数和推到目的地的箱子个数相等，则发出游戏结束的信号
        if(this->incnt == this->boxcnt ){
            emit this->win();
            Win = true;
        }
    });

    QLabel *winLab = new QLabel;
    QPixmap p;
    p.load(":/res/winsence.png");
    winLab->setParent(this);
    winLab->setPixmap(p);
    winLab->move((this->width()-p.width())*0.5,-500);
    connect(this,&gameSence::win,[=](){
        //停止捕获键盘
        this->releaseKeyboard();
        QPropertyAnimation *ac =new QPropertyAnimation(winLab,"geometry");
        succeedSound->play();
        qDebug()<<"winwinwin";
        ac->setDuration(500);
        ac->setStartValue(QRect(winLab->x(),winLab->y(),winLab->width(),winLab->height()));
        ac->setEndValue(QRect(winLab->x(),winLab->y()+470,winLab->width(),winLab->height()));
        ac->setEasingCurve(QEasingCurve::OutBounce);
        ac->start();


    });
    //捕获重置信号
    connect(this,&gameSence::reset,[=](){
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                *(map[i][j]) = Data->mapdata[this->Level][i][j];
                dmap[i][j]->SetmyIcon(*(map[i][j]));
            }
        }
    });
}

void gameSence::paintEvent(QPaintEvent *)
{
    //加载背景图
    QPixmap pix;
    pix.load(":/res/background.png");
    //画家画背景图
    QPainter painter(this);
    painter.drawPixmap(0,0,pix.width(),pix.height(),pix);
    //加载title
    pix.load(":/res/title");
    //画家画title
    painter.drawPixmap(10,30,pix.width()*0.3,pix.height()*0.3,pix);
}

void gameSence::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
    case Qt::Key_Up:
        emit this->MOVE(Up);
        break;
    case Qt::Key_Down:
        emit this->MOVE(Down);
        break;
    case Qt::Key_Left:
        emit this->MOVE(Left);
        break;
    case Qt::Key_Right:
        emit this->MOVE(Right);
        break;
    case Qt::Key_0:
        if(Win == false)
            emit this->reset();
        break;
    }
    return QMainWindow::keyPressEvent(event);
}

void gameSence::mousePressEvent(QMouseEvent *event)
{
    if(Win){
        //按在了下一关区域
        if(event->x() >= 280 && event->x() <= 353 && event->y() >= 330 && event->y() <= 360){
            qDebug()<<"进入下一关";
            next = new gameSence(this->Level +1 );
            next->setGeometry(this->geometry());
            next->show();
            this->hide();
            connect(next,&gameSence::back,[=](){
                delete next;
                next = nullptr;
                emit this->back();
            });

        }
        //按在了返回区域
        if(event->x() >= 142 && event->x() <= 214 && event->y()>= 330 && event->y() <=360){
            emit this->back();
        }
    }
    return QMainWindow::mousePressEvent(event);
}

gameSence::~gameSence()
{
    if(next){
        delete next;
        next = nullptr;
    }
}




