#include "CommonPattern.h"
#include "ui_CommonPattern.h"

CommonPattern::CommonPattern(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CommonPattern)
{
    ui->setupUi(this);
    //设置固定大小
    this->setFixedSize(640,685);

    //设置图标1和标题
    this->setWindowIcon(QIcon(":/res/MineClearance.png"));
    this->setWindowTitle("一般模式");

    //实现退出
    connect(ui->actionQuit,&QAction::triggered,this,&QMainWindow::close);

    //添加两个标签和一个按钮
    QLabel *label1 = new QLabel(this);
    QLabel *label2 = new QLabel(this);
    MyPushButton *backBtn = new MyPushButton(":/res/backBtn.png");
    backBtn->setParent(this);
    label1->setText("时间：0s");
    label1->setStyleSheet("QLabel{color:red;}");
    label2->setText("剩余地雷：60");
    label2->setStyleSheet("QLabel{color:red;}");
    label1->move(30,20);
    label2->move(this->width()-label2->width(),20);
    backBtn->move(250,-2);

    //实现返回
    connect(backBtn,&QPushButton::clicked,this,&CommonPattern::back);

    memset(map,-1,sizeof(map));
    creatMine();
    initMap();
    test();
    drawMap();

    timer1->start(1000);
    timer2->start();

    connect(timer1,&QTimer::timeout,[=](){
        sec++;
        updateLabel1(label1);
    });
    connect(timer2,&QTimer::timeout,[=](){
        updateLabel2(label2);
    });

    connect(this,&CommonPattern::click,this,[=](){
        sweep(clickedBtn,clickedi,clickedj,true);
    });

    connect(this,& CommonPattern::gameOver,[=](int Case){
        if(Case==0){
            qDebug()<<"你输了，游戏结束";
            for(int i=0;i<20;i++){
                for(int j=0;j<20;j++){
                    if(vis[i][j]==0){
                        setLabelIcon(mapLabel[i][j],map[i][j]);
                        vis[i][j]=-1;
                    }
                }
            }
            GameOverDialog * loseDlg = new GameOverDialog(Case,this);
            loseDlg->exec();
            timer2->stop();
        }
        if(Case==1){
            qDebug()<<"恭喜你，你赢了";
            for(int i=0;i<20;i++){
                for(int j=0;j<20;j++){
                    if(vis[i][j]==0){
                        setLabelIcon(mapLabel[i][j],map[i][j]);
                        vis[i][j]=-1;
                    }
                }
            }
            GameOverDialog * winDlg = new GameOverDialog(Case,this,sec);
            winDlg->exec();
            timer2->stop();
        }
        });
}

CommonPattern::~CommonPattern()
{
    delete ui;
}

void CommonPattern::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/EasyBg.png");
    pix = pix.scaled(640,640);
    painter.drawPixmap(0,0,pix.width(),pix.height(),pix);
}

void CommonPattern::creatMine()
{
    qsrand((uint)time(0));
    while(mineNumber<60){
        int i = qrand()%20;
        int j = qrand()%20;
        if(!iscontain(row,col,i,j) && checkMine(i,j)<=4){
            row.append(i);
            col.append(j);
            map[i][j]=8;
            mineNumber++;
        }
    }
}

int CommonPattern::checkMine(int i, int j)
{
    int cnt=0;
    if(i-1>=0){
        cnt = cnt + (map[i-1][j]==8?1:0);
        if(j-1>=0)cnt = cnt + (map[i-1][j-1]==8?1:0);
        if(j+1<20)cnt = cnt + (map[i-1][j+1]==8?1:0);
    }
    cnt = cnt + (map[i][j]==8?1:0);
    if(j-1>=0)cnt = cnt + (map[i][j-1]==8?1:0);
    if(j+1<20)cnt = cnt + (map[i][j+1]==8?1:0);
    if(i+1<20){
        cnt = cnt + (map[i+1][j]==8?1:0);
        if(j-1>=0)cnt = cnt + (map[i+1][j-1]==8?1:0);
        if(j+1<20)cnt = cnt + (map[i+1][j+1]==8?1:0);
    }
    return cnt;
}

bool CommonPattern::iscontain(QVector<int> p, QVector<int> q, int m, int n)
{
    for(int i=0;i<p.size();i++){
        if(p.at(i)==m){
            if(q.at(i)==n){
                return true;
            }
            else {
                continue;
            }
        }
    }
    return false;
}

void CommonPattern::initMap()
{
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            if(map[i][j]==8){
                continue;
            }
            map[i][j] = checkMine(i,j);
        }
    }
    memset(vis,0,sizeof(vis));
}

void CommonPattern::test()
{
    for(int i=0;i<20;i++){
        qDebug()<<map[i][0]<<map[i][1]<<map[i][2]<<map[i][3]<<map[i][4]
                <<map[i][5]<<map[i][6]<<map[i][7]<<map[i][8]<<map[i][9]
                <<map[i][10]<<map[i][11]<<map[i][12]<<map[i][13]<<map[i][14]
                <<map[i][15]<<map[i][16]<<map[i][17]<<map[i][18]<<map[i][19];
    }
}

void CommonPattern::drawMap()
{
    QLabel* label = nullptr;
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            label = new QLabel(this);
            label->setFixedSize(32,32);
            label->move(j*32,i*32+45);
            mapLabel[i][j] = label;
            setLabelIcon(mapLabel[i][j],-1);
        }
    }
}

void CommonPattern::sweep(int clickedBtn, int i, int j, bool click)
{
    qDebug()<<clickedBtn<<" "<<i<<" "<<j<<" "<<click<<" "<<map[i][j]<<" "<<vis[i][j];
    if(clickedBtn == Qt::LeftButton){
        //qDebug()<<"点击左键";
        if(map[i][j]==8&&click&&vis[i][j]!=-1){
            qDebug()<<"你踩到雷了";
            setLabelIcon(mapLabel[i][j],8);
            vis[i][j] = -1;
            isgameover = true;
            timer1->stop();
            emit this->gameOver(0);
        }
        if((map[i][j]>=1&&map[i][j]<=5)&&vis[i][j]!=-1){
            qDebug()<<"你踩到的数字是:"<<map[i][j];
            setLabelIcon(mapLabel[i][j],map[i][j]);
            vis[i][j] = -1;
        }
        if(map[i][j]==0&&vis[i][j]!=-1){
            qDebug()<<"你踩到的数字是：0";
            setLabelIcon(mapLabel[i][j],0);
            vis[i][j] = -1;
            //对0周围8个格子检测
            if(i-1>=0){
                if(map[i-1][j]!=8)sweep(Qt::LeftButton,i-1,j,false);
                if(j-1>=0&&map[i-1][j-1]!=8)sweep(Qt::LeftButton,i-1,j-1,false);
                if(j+1<10&&map[i-1][j+1]!=8)sweep(Qt::LeftButton,i-1,j+1,false);
            }
            if(j-1>=0&&map[i][j-1]!=8)sweep(Qt::LeftButton,i,j-1,false);
            if(j+1<10&&map[i][j+1]!=8)sweep(Qt::LeftButton,i,j+1,false);
            if(i+1<10){
                if(map[i+1][j]!=8)sweep(Qt::LeftButton,i+1,j,false);
                if(j-1>=0&&map[i+1][j-1]!=8)sweep(Qt::LeftButton,i+1,j-1,false);
                if(j+1<10&&map[i+1][j+1]!=8)sweep(Qt::LeftButton,i+1,j+1,false);
            }
        }
    }
    if(clickedBtn == Qt::RightButton){
        qDebug()<<"点击了右键";
        if(vis[i][j]==0){
            qDebug()<<"变旗子";
            flagNumber++;
            setLabelIcon(mapLabel[i][j],9);
            vis[i][j]=1;
            if(iscontain(row,col,i,j)){
                mineNumber--;
                qDebug()<<"剩余地雷："<<mineNumber;
                qDebug()<<"旗子数量："<<flagNumber;
            }
        }
        else if(vis[i][j]==1){
            qDebug()<<"变问号";
            setLabelIcon(mapLabel[i][j],7);
            vis[i][j]=2;
        }
        else{
            qDebug()<<"变背景";
            flagNumber--;
            setLabelIcon(mapLabel[i][j],-1);
            vis[i][j]=0;
            if(iscontain(row,col,i,j)){
                mineNumber++;
                qDebug()<<"剩余地雷："<<mineNumber;
                qDebug()<<"旗子数量："<<flagNumber;
            }
        }
    }
    this->isgameover = isGameOver();
}

void CommonPattern::mousePressEvent(QMouseEvent *event)
{
    if(event->x()>=0 && event->x()<=640 && event->y()>=45 && event->y()<=685){
        if(!isgameover){
            clickedi = (event->y()-45)/32;
            clickedj = event->x()/32;
            clickedBtn = event->button();
            qDebug()<<clickedi<<" "<<clickedj;
            if(clickedBtn == Qt::LeftButton){
                qDebug()<<"点击左键";
                emit this->click();
            }
            if(clickedBtn == Qt::RightButton){
                qDebug()<<"点击了右键";
                emit this->click();
            }
        }
    }
}

void CommonPattern::setLabelIcon(QLabel *label, int pic)
{
    QPixmap pix;
    switch(pic){
        case 0:
            pix.load(":/res/Number0.png");
            break;
        case 1:
            pix.load(":/res/Number1.png");
            break;
        case 2:
            pix.load(":/res/Number2.png");
            break;
        case 3:
            pix.load(":/res/Number3.png");
            break;
        case 4:
            pix.load(":/res/Number4.png");
            break;
        case 5:
            pix.load(":/res/Number5.png");
            break;
        case 8:
            pix.load(":/res/DeadMine.png");
            break;
        case 9:
            pix.load(":/res/Flag.png");
            break;
        case 7:
            pix.load(":/res/Question.png");
            break;
        default:
            pix.load(":/res/BlockBg.png");
    }
    label->setPixmap(pix);
}

bool CommonPattern::isVisOver()
{
    int cnt=0;
    int i_=0;
    int j_=0;
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            if(vis[i][j]==0){
                cnt++;
                if(cnt==2){
                    return false;
                }
                i_=i;
                j_=j;
            }
        }
    }
    if(cnt==1 && map[i_][j_]==8)return true;
    return true;
}

bool CommonPattern::isGameOver()
{
    if((isVisOver()||(mineNumber==0&&flagNumber==60)) && !isgameover){
        timer1->stop();
        emit this->gameOver(1);
        return true;
    }
    return false;
}

void CommonPattern::updateLabel1(QLabel *a)
{
    a->setText(QString("时间：%1s").arg(sec));
}

void CommonPattern::updateLabel2(QLabel *b)
{
    b->setText(QString("剩余地雷：%1").arg(mineNumber));
}
