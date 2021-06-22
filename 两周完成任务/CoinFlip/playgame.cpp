#include "playgame.h"
#include "mypushbutton.h"
#include "mycoin.h"
#include "dataconfig.h"
#include <QDebug>
#include <QString>
#include <QPixmap>
#include <QPainter>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QTimer>
#include <QLabel>
#include <QPropertyAnimation>
#include <QSound>


playGame::playGame(QWidget *parent) : QMainWindow(parent)
{

}

playGame::playGame(int level)
{
    levelIndex = level;

    ////////初始化游戏场景//////////
    setFixedSize(390,590);
    setWindowTitle(QString("小王翻金币-第%1关").arg(level));
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    QMenuBar *bar = menuBar();
    setMenuBar(bar);

    //实现退出菜单项
    QMenu *START = bar->addMenu("开始");
    QAction *exit = START->addAction("退出");
    connect(exit,&QAction::triggered,[=](){
        close();
    });

    //加载返回按钮音效
    QSound *backsound = new QSound(":/res/BackButtonSound.wav",this);
    //加载翻金币音效
    QSound *FlipCoinSound = new QSound(":/res/ConFlipSound.wav",this);
    //加载胜利的音效
    QSound *succeedsound = new QSound(":/res/LevelWinSound.wav",this);

    //返回按钮
    myPushButton *btn_back = new myPushButton(":/res/BackButton.png",
                                              ":/res/BackButtonSelected.png");
    btn_back->setParent(this);
    btn_back->move(this->width()-btn_back->width(),this->height()-btn_back->height());
    connect(btn_back,&QPushButton::clicked,[=](){
        //播放返回按钮的音效
        backsound->play();
        //延时返回
        QTimer::singleShot(200,this,[=](){
            emit this->chooseBack();
        });
    });

    //关卡标签
    QLabel *lab = new QLabel(this);
    lab->setFont(QFont("Comic Sans MS",30));
    lab->setText(QString("Level %1").arg(level));
    lab->setGeometry(30,this->height()-70,150,50);

    //胜利图片的加载
    QPixmap winpix(":/res/LevelCompletedDialogBg.png");
    QLabel * winlab = new QLabel(this);
    winlab->setPixmap(winpix);
    winlab->setFixedSize(winpix.width(),winpix.height());
    winlab->move((this->width() - winpix.width())*0.5 , -winpix.height());

    //////////  画硬币背景 /////////////
    dataConfig gameMap;


    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            //画装金币的盒子
            QPixmap pix(":/res/BoardNode.png");
            QLabel *label = new QLabel(this);
            label->setGeometry(0,0,pix.width(),pix.height());
            label->setPixmap(pix);
            label->move(100 + j*pix.width(),220 +i*pix.height());
            //加载金币地图
            gameArray[i][j] = gameMap.mData[this->levelIndex][i][j];
            //画金币
            QString CoinPath;
            if(gameArray[i][j] == 1){
                CoinPath = ":/res/Coin0001.png";
            }
            else{
                CoinPath = ":/res/Coin0008.png";
            }
            myCoin *coin = new myCoin(CoinPath);
            coin->setParent(this);
            coin->move(102 + j*pix.width(),224 +i*pix.height());
            coin->setPosX(i);
            coin->setPosY(j);
            coin->setflag(gameArray[i][j]);
            coinBtn[i][j] = coin;
            //翻金币
            connect(coin,&QPushButton::clicked,[=](){
//                qDebug()<<"自身"<<coin->getFlag();
                //播放翻金币音效
                FlipCoinSound->play();
                coin->changeFlag();
//                qDebug()<<"自身"<<coin->getFlag();
                this->gameArray[i][j] = this->gameArray[i][j] == 0 ? 1 : 0;
                //翻转周围金币
                QTimer::singleShot(200,this,[=](){
                    //翻上侧金币
                    if(coin->getPosX()-1>=0){
//                        qDebug()<<"上面"<<coinBtn[coin->getPosX()-1][coin->getPosY()]->getFlag();
                        coinBtn[coin->getPosX()-1][coin->getPosY()]->changeFlag();
//                        qDebug()<<"上面"<<coinBtn[coin->getPosX()-1][coin->getPosY()]->getFlag();
                        //this->gameArray[coin->getPosX()-1][coin->getPosY()] = this->gameArray[coin->getPosX()-1][coin->getPosY()] == 0 ? 1 : 0;
                    }
                    //下
                    if(coin->getPosX() + 1 <= 3){
//                        qDebug()<<"下面"<<coinBtn[coin->getPosX()+1][coin->getPosY()]->getFlag();
                        coinBtn[coin->getPosX()+1][coin->getPosY()]->changeFlag();
//                        qDebug()<<"下面"<<coinBtn[coin->getPosX()+1][coin->getPosY()]->getFlag();
                        this->gameArray[coin->getPosX()+1][coin->getPosY()] = this->gameArray[coin->getPosX()+1][coin->getPosY()] == 0 ? 1 : 0;
                    }
                    //左
                     if(coin->getPosY() -1 >=0 ){
//                         qDebug()<<"左面"<<coinBtn[coin->getPosX()][coin->getPosY()-1]->getFlag();
                         coinBtn[coin->getPosX()][coin->getPosY()-1]->changeFlag();
//                         qDebug()<<"左面"<<coinBtn[coin->getPosX()][coin->getPosY()-1]->getFlag();
                     }
                     //右
                     if(coin->getPosY() + 1 < 4 ){
//                         qDebug()<<"右面"<<coinBtn[coin->getPosX()][coin->getPosY()+1]->getFlag();
                         coinBtn[coin->getPosX()][coin->getPosY()+1]->changeFlag();
                        // qDebug()<<"右面"<<coinBtn[coin->getPosX()][coin->getPosY()+1]->getFlag();
                     }

                     this->isSucceed =true;
                    for(int i=0;i<4;i++){
                        for(int j=0;j<4;j++){
                            if(coinBtn[i][j]->getFlag() == false){
                                isSucceed = false;
                                break;
                            }
                        }
                    }
                    if(isSucceed)
                    {
                        //qDebug()<<"你终于赢了";
                        //播放胜利音效
                        succeedsound->play();
                        for(int i=0;i<4;i++){
                            for(int j=0;j<4;j++){
                                coinBtn[i][j]->setIsSucceed(true);
                            }
                        }

                        //弹出胜利图片
                        QPropertyAnimation *win = new QPropertyAnimation(winlab,"geometry");
                        //设置时间间隔
                        win->setDuration(1000);
                        //设置起始位置
                        win->setStartValue(QRect((this->width() - winlab->width())*0.5 , -winlab->height(),winlab->width(),winlab->height()));
                        //设置末位置
                        win->setEndValue(QRect((this->width() - winlab->width())*0.5 , 128,winlab->width(),winlab->height()));
                        //设置曲线
                        win->setEasingCurve(QEasingCurve::OutBounce);
                        win->start();




                    }
                });
            });
        }
    }

}

void playGame::paintEvent(QPaintEvent *)
{
    //加载图片
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    //画家画背景
    QPainter painter(this);
    painter.drawPixmap(0,0,390,590,pix);

    //画title图
    pix.load(":/res/Title.png");
    painter.drawPixmap(this->width()*0.5-pix.width()*0.5,30,pix);
}
