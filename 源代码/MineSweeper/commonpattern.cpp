/**
 * @note 一般模式类
 */

#include "CommonPattern.h"
#include "ui_CommonPattern.h"
const int WIN = 1;
const int LOSE = 0;

CommonPattern::CommonPattern(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CommonPattern)
{
    ui->setupUi(this);
    ///设置固定大小
    this->setFixedSize(640,685);

    ///设置图标1和标题
    this->setWindowIcon(QIcon(":/res/MineClearance.png"));
    this->setWindowTitle("一般模式");

    ///实现退出
    connect(ui->actionQuit,&QAction::triggered,this,&QMainWindow::close);

    ///添加两个标签和一个按钮,标签1用于计时，标签2用于统计剩余地雷，按钮用于返回
    QLabel *label1 = new QLabel(this);
    QLabel *label2 = new QLabel(this);
    MyPushButton *backBtn = new MyPushButton(":/res/backBtn.png");

    backBtn->setParent(this);///设置按钮父亲
    ///设置label初始内容
    label1->setText("时间：0s");
    label2->setText("剩余地雷：60");
    ///设置label样式
    label1->setStyleSheet("QLabel{color:red;}");
    label2->setStyleSheet("QLabel{color:red;}");
    ///移动到对应位置
    label1->move(30,20);
    label2->move(this->width()-label2->width(),20);
    backBtn->move(250,-2);

    ///实现返回
    connect(backBtn,&QPushButton::clicked,this,&CommonPattern::back);

    ///给地图赋初值-1，防止影响到地雷的生成
    memset(map,-1,sizeof(map));

//    clock_t start = clock();
    ///随机生成地雷
    creatMine();
    ///初始化地图
    initMap();
    ///打印数字地图
//    test();
    ///画地图
    drawMap();
//    clock_t end = clock();
//    qDebug()<<"创建地图用时："<<end-start<<"ms";

    ///启动定时器1和2,1用于计时，2用于更新剩余地雷
    timer1->start(1000);
    timer2->start();

    ///连接定时器1
    connect(timer1,&QTimer::timeout,[=](){
        sec++;
        updateLabel1(label1);
    });
    ///连接定时器2
    connect(timer2,&QTimer::timeout,[=](){
        updateLabel2(label2);
    });

    ///监听点击信号，鼠标事件发出
    connect(this,&CommonPattern::click,this,[=](){
        sweep(clickedBtn,clickedi,clickedj,true);
    });

    ///监听游戏结束信号
    connect(this,& CommonPattern::gameOver,[=](int Case){
        ///翻开没有点击的、插旗却不正确的，问号的所有格子
        for(int i=0;i<20;i++){
            for(int j=0;j<20;j++){
                if(vis[i][j]==0||vis[i][j]==2||(vis[i][j]==1&&map[i][j]!=8)){
                    setLabelIcon(mapLabel[i][j],map[i][j]);
                    vis[i][j]=-1;   ///自动翻开
                }
            }
        }
        ///新建一个游戏结束对话框
        GameOverDialog * Dlg = nullptr;
        ///如果输了，new 失败对话框
        if(Case==LOSE){
//            qDebug()<<"你输了，游戏结束";
//            qDebug()<<"isgameover"<<isgameover;
            Dlg = new GameOverDialog(Case,this);
        }
        ///如果赢了，new一个胜利对话框
        if(Case==WIN){
//            qDebug()<<"恭喜你，你赢了";
            ///新建一个游戏胜利对话框
            Dlg = new GameOverDialog(Case,this,sec);
        }
        ///弹出模态对话框
        Dlg->exec();
        ///定时器2停止
        timer2->stop();
        });
}

CommonPattern::~CommonPattern()
{
    delete ui;
}

/**
 * 画背景
 * @brief EasyPattern::paintEvent
 * @param QPaintEvent*  由于不需要使用参数，故不用指定变量名
 */
void CommonPattern::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/EasyBg.png");
    pix = pix.scaled(640,640);
    painter.drawPixmap(0,0,pix.width(),pix.height(),pix);
}

/**
 * 随机生成地雷，简单模式15个地雷
 * @brief EasyPattern::creatMine
 */
void CommonPattern::creatMine()
{
    qsrand((uint)time(0));
    while(mineNumber<60){
        int i = qrand()%20;
        int j = qrand()%20;
        if((checkMine(i,j)<=2) && (!iscontain(row,col,i,j))){
            row.append(i);
            col.append(j);
            map[i][j]=8;
            mineNumber++;
        }
    }
}

/**
 * 检测一个格子周围的地雷数量
 * @brief EasyPattern::checkMine
 * @param i 行标
 * @param j 列标
 * @return int 返回格子周围的地雷数量
 */
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

/**
 * 检测(m,n)位置是否已经是地雷
 * @brief EasyPattern::iscontain
 * @param p 地雷所在的行标集合
 * @param q 地雷所在的列标集合
 * @param m 当前位置行标
 * @param n 当前位置列标
 * @return bool 如果(m,n)处是地雷返回true
 */
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

/**
 * 初始化地图，填上不是地雷的格子里的数字
 * @brief EasyPattern::initMap
 */
void CommonPattern::initMap()
{
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            vis[i][j] = 0;
            if(map[i][j]==8){
                continue;
            }
            map[i][j] = checkMine(i,j);
        }
    }
}

/**
 * 测试map初始化是否成功，将其打印出来
 * @brief EasyPattern::test
 */
void CommonPattern::test()
{
    for(int i=0;i<20;i++){
        qDebug()<<map[i][0]<<map[i][1]<<map[i][2]<<map[i][3]<<map[i][4]
                <<map[i][5]<<map[i][6]<<map[i][7]<<map[i][8]<<map[i][9]
                <<map[i][10]<<map[i][11]<<map[i][12]<<map[i][13]<<map[i][14]
                <<map[i][15]<<map[i][16]<<map[i][17]<<map[i][18]<<map[i][19];
    }
}

/**
 * 画地图，用便签来装每个格子的元素
 * @brief EasyPattern::drawMap
 */
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

/**
 * 游戏最重要的一个函数，实现递归搜索扫雷
 * @brief EasyPattern::sweep
 * @param clickedBtn 点击的按键
 * @param i 点击的行标
 * @param j 点击的列标
 * @param click 是否是手动点击
 */
void CommonPattern::sweep(int clickedBtn, int i, int j, bool click)
{
//    qDebug()<<clickedBtn<<" "<<i<<" "<<j<<" "<<click<<" "<<map[i][j]<<" "<<vis[i][j];
    if(clickedBtn == Qt::LeftButton){
        //qDebug()<<"点击左键";
        if(map[i][j]==8&&click&&vis[i][j]==0){
//            qDebug()<<"你踩到雷了";
            setLabelIcon(mapLabel[i][j],8);
            vis[i][j] = -1;
            isgameover = true;
            timer1->stop();
            emit this->gameOver(0);
        }
        if((map[i][j]>=1&&map[i][j]<=5)&&vis[i][j]==0){
//            qDebug()<<"你踩到的数字是:"<<map[i][j];
            setLabelIcon(mapLabel[i][j],map[i][j]);
            vis[i][j] = -1;
        }
        if(map[i][j]==0&&vis[i][j]==0){
//            qDebug()<<"你踩到的数字是：0";
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
//        qDebug()<<"点击了右键";
        if(vis[i][j]==0){
//            qDebug()<<"变旗子";
            flagNumber++;
            setLabelIcon(mapLabel[i][j],9);
            vis[i][j]=1;
            if(iscontain(row,col,i,j)){
                mineNumber--;
//                qDebug()<<"剩余地雷："<<mineNumber;
//                qDebug()<<"旗子数量："<<flagNumber;
            }
        }
        else if(vis[i][j]==1){
//            qDebug()<<"变问号";
            setLabelIcon(mapLabel[i][j],7);
            vis[i][j]=2;
        }
        else if(vis[i][j]==2){
//            qDebug()<<"变背景";
            flagNumber--;
            setLabelIcon(mapLabel[i][j],-1);
            vis[i][j]=0;
            if(iscontain(row,col,i,j)){
                mineNumber++;
//                qDebug()<<"剩余地雷："<<mineNumber;
//                qDebug()<<"旗子数量："<<flagNumber;
            }
        }
    }
    this->isgameover = isGameOver();
}

/**
 * 处理鼠标点击事件，扫雷时候点击
 * @brief EasyPattern::mousePressEvent
 * @param event 鼠标事件的对象，里面包含鼠标点击的信息
 */
void CommonPattern::mousePressEvent(QMouseEvent *event)
{
    if(event->x()>=0 && event->x()<=640 && event->y()>=45 && event->y()<=685){
        if(!isgameover){
            clickedi = (event->y()-45)/32;
            clickedj = event->x()/32;
            clickedBtn = event->button();
//            qDebug()<<clickedi<<" "<<clickedj;
            if(clickedBtn == Qt::LeftButton){
//                qDebug()<<"点击左键";
                emit this->click();
            }
            if(clickedBtn == Qt::RightButton){
//                qDebug()<<"点击了右键";
                emit this->click();
            }
        }
    }
}

/**
 * 设置label图标
 * @brief EasyPattern::setLabelIcon
 * @param label 待设置的图标
 * @param pic 图标代码
 */
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
        case 6:
            pix.load(":/res/Number6.png");
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

/**
 * 判断vis是否全处于点开状态 或者 全是未点开的雷
 * @brief EasyPattern::isVisOver
 * @return 满足全是点开或者未点开的全是雷就返回true
 */
bool CommonPattern::isVisOver()
{
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            if(vis[i][j]==0&&map[i][j]!=8){
                return false;
            }
        }
    }
    return true;
}

/**
 * 判断游戏是否结束
 * @brief EasyPattern::isGameOver
 * @return 游戏结束返回true
 */
bool CommonPattern::isGameOver()
{
    if(isgameover)return true;
    if((mineNumber==0&&flagNumber==60) || isVisOver()){
        timer1->stop();
//        qDebug()<<"isgameover:"<<isgameover;
        emit this->gameOver(WIN);
        return true;
    }
    return false;
}

/**
 * 更新时间标签
 * @brief EasyPattern::updateLabel1
 * @param a 待更新标签
 */
void CommonPattern::updateLabel1(QLabel *a)
{
    a->setText(QString("时间：%1s").arg(sec));
}

/**
 * 更新剩余地雷标签
 * @brief EasyPattern::updateLabel1
 * @param b 待更新标签
 */
void CommonPattern::updateLabel2(QLabel *b)
{
    b->setText(QString("剩余地雷：%1").arg(mineNumber));
}
