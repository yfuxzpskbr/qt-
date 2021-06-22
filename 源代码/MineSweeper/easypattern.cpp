/**
 * @note 简单模式类
 */

#include "easypattern.h"
#include "ui_easypattern.h"
const int WIN = 1;
const int LOSE = 0;

EasyPattern::EasyPattern(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EasyPattern)
{
    ui->setupUi(this);
    ///设置固定大小
    this->setFixedSize(320,365);

    ///设置图标和标题
    this->setWindowIcon(QIcon(":/res/MineClearance.png"));
    this->setWindowTitle("简单模式");

    ///实现退出
    connect(ui->actionQuit,&QAction::triggered,this,&QMainWindow::close);

    ///添加两个标签和一个按钮
    QLabel *label1 = new QLabel(this);  ///标签1用于统计游戏时间
    QLabel *label2 = new QLabel(this);  ///标签2用于统计剩余地雷
    ///按钮用于返回
    MyPushButton *backBtn = new MyPushButton(":/res/backBtn.png");
    backBtn->setParent(this);   ///设置按钮父亲
    ///设置初始内容
    label1->setText("时间：0s");
    label2->setText("剩余地雷：15");
    ///设置样式表
    label1->setStyleSheet("QLabel{color:red;}");
    label2->setStyleSheet("QLabel{color:red;}");
    ///移动到对应位置
    label1->move(30,20);
    label2->move(this->width()-label2->width(),20);
    backBtn->move(80,-2);

    ///实现返回
    connect(backBtn,&QPushButton::clicked,this,&EasyPattern::back);

    ///给地图赋初值-1，防止影响到地雷的生成
    memset(map,-1,sizeof(map));

//    clock_t start=clock();
    ///随机生成雷
    creatMine();
    ///初始化地图
    initMap();
//    test();
    ///画地图
    drawMap();
//    clock_t end = clock();
//    qDebug()<<"创建地图用时："<<end-start<<"ms";

    ///启动两个定时器，定时器1用于计时，定时器2用于更新剩余地雷
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

    ///监听点击信号，由鼠标点击事件发出
    connect(this,&EasyPattern::click,this,[=](){
        sweep(clickedBtn,clickedi,clickedj,true);
    });

    ///监听游戏结束信号，参数WIN(1)表示游戏胜利、LOSE(0)表示游戏失败
    connect(this,&EasyPattern::gameOver,[=](int Case){
        ///翻开没有点击的、插旗却不正确的，问号的所有格子
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
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

EasyPattern::~EasyPattern()
{
    delete ui;
}

/**
 * 画背景
 * @brief EasyPattern::paintEvent
 * @param QPaintEvent*  由于不需要使用参数，故不用指定变量名
 */
void EasyPattern::paintEvent(QPaintEvent *)
{
    QPainter painter(this);///新建画家对象
    QPixmap pix;///新建图片对象
    pix.load(":/res/EasyBg.png");///加载图片
    painter.drawPixmap(0,0,pix.width(),pix.height(),pix);///画家画背景
}

/**
 * 检测一个格子周围的地雷数量
 * @brief EasyPattern::checkMine
 * @param i 行标
 * @param j 列标
 * @return int 返回格子周围的地雷数量
 */
int EasyPattern::checkMine(int i,int j)
{
    int cnt=0;///周围地雷初始化为0
    ///所有的if语句都是边界检测，如果周围有地雷就+1
    if(i-1>=0){
        cnt = cnt + (map[i-1][j]==8?1:0);
        if(j-1>=0)cnt = cnt + (map[i-1][j-1]==8?1:0);
        if(j+1<10)cnt = cnt + (map[i-1][j+1]==8?1:0);
    }
    cnt = cnt + (map[i][j]==8?1:0);
    if(j-1>=0)cnt = cnt + (map[i][j-1]==8?1:0);
    if(j+1<10)cnt = cnt + (map[i][j+1]==8?1:0);
    if(i+1<10){
        cnt = cnt + (map[i+1][j]==8?1:0);
        if(j-1>=0)cnt = cnt + (map[i+1][j-1]==8?1:0);
        if(j+1<10)cnt = cnt + (map[i+1][j+1]==8?1:0);
    }
    ///返回周围地雷
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
bool EasyPattern::iscontain(QVector<int> p, QVector<int> q, int m, int n)
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
void EasyPattern::initMap()
{
//    qDebug()<<"开始";
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            vis[i][j] = 0;  ///刚开始的格子没有被翻开，故初始化为0
//            qDebug()<<vis[i][j];
            if(map[i][j]==8){///不用检测地雷周围的地雷
                continue;
            }
            ///填不是地雷格子的数字
            map[i][j] = checkMine(i,j);
        }
    }
//    qDebug()<<"结束";
}

/**
 * 测试map初始化是否成功，将其打印出来
 * @brief EasyPattern::test
 */
void EasyPattern::test()
{
    for(int i=0;i<10;i++){
        qDebug()<<map[i][0]<<map[i][1]<<map[i][2]<<map[i][3]<<map[i][4]
                <<map[i][5]<<map[i][6]<<map[i][7]<<map[i][8]<<map[i][9];
    }
}

/**
 * 画地图，用便签来装每个格子的元素
 * @brief EasyPattern::drawMap
 */
void EasyPattern::drawMap()
{
    QLabel* label = nullptr;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            label = new QLabel(this);///新建label指针
            label->setFixedSize(32,32);///设置固定大小
            label->move(j*32,i*32+45);///移动到指定位置
            mapLabel[i][j] = label;///将其保存起来，方便维护
            setLabelIcon(mapLabel[i][j],-1);///设置图标，即设置格子的图案
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
void EasyPattern::sweep(int clickedBtn,int i,int j,bool click)
{
//    qDebug()<<clickedBtn<<" "<<i<<" "<<j<<" "<<click<<" "<<map[i][j]<<" "<<vis[i][j];
    ///如果左键单击
    if(clickedBtn == Qt::LeftButton){
//        qDebug()<<"点击左键";
        ///点开是地雷，并且是手动点击，并且该位置处于未点开状态
        if(map[i][j]==8&&click&&vis[i][j]==0){
//            qDebug()<<"你踩到雷了";
            ///点开的格子设置为雷
            setLabelIcon(mapLabel[i][j],8);
            vis[i][j] = -1;///设置vis为已点开
            isgameover = true;///游戏结束标志置true
            timer1->stop();///定时器1(统计游戏时间)停止
//            qDebug()<<"isgameover:"<<isgameover;
            emit this->gameOver(LOSE);///触发游戏失败信号
        }
        ///如果点开是不为0的数字，并且该位置处于未点开状态
        if((map[i][j]>=1&&map[i][j]<=5)&&vis[i][j]==0){
//            qDebug()<<"你踩到的数字是:"<<map[i][j];
            setLabelIcon(mapLabel[i][j],map[i][j]);///将点开的格子设为该数字
            vis[i][j] = -1;///设置vis为已点开
        }
        ///如果点开是数字0，则递归点开周围的格子，知道不是数字0停止，，并且该位置处于未点开状态
        if(map[i][j]==0&&vis[i][j]==0){
//            qDebug()<<"你踩到的数字是：0";
            setLabelIcon(mapLabel[i][j],0);///将点开的格子设置为数字0
            vis[i][j] = -1;///vis标记为已点开
            ///对0周围8个格子检测
            ///if边界检测
            ///如果周围的格子不是地雷，就递归点开周围格子，这时click参数应为false，因为不是手动点击
            ///是程序递归点开的
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
    ///如果单击右键，在旗子，问号，和未点开之间来回切换
    if(clickedBtn == Qt::RightButton){
//        qDebug()<<"点击了右键";
        ///如果是未点开状态，就变为旗子
        if(vis[i][j]==0){
//            qDebug()<<"变旗子";
            flagNumber++;///旗子数量+1
            setLabelIcon(mapLabel[i][j],9);///设置当前块为旗子
            vis[i][j]=1;///vis标记为旗子
            if(iscontain(row,col,i,j)){///如果i,j位置确实是地雷，地雷数量-1
                mineNumber--;
//                qDebug()<<"剩余地雷："<<mineNumber;
//                qDebug()<<"旗子数量："<<flagNumber;
            }
        }
        ///如果是旗子状态，则变为问号
        else if(vis[i][j]==1){
//            qDebug()<<"变问号";
            setLabelIcon(mapLabel[i][j],7); ///设置为问号
            vis[i][j]=2;///vis标记为问号
        }
        ///如果是问号，则变为未点开
        else if(vis[i][j]==2){
//            qDebug()<<"变背景";
            flagNumber--;///旗子-1
            setLabelIcon(mapLabel[i][j],-1);///设置为未点开状态
            vis[i][j]=0;///vis标记为未点开
            if(iscontain(row,col,i,j)){///如果i,j是地雷，地雷数量+1
                mineNumber++;
//                qDebug()<<"剩余地雷："<<mineNumber;
//                qDebug()<<"旗子数量："<<flagNumber;
            }
        }
    }
    ///每次扫雷(点击)后都判断是不是游戏结束
    this->isgameover = isGameOver();
}

/**
 * 处理鼠标点击事件，扫雷时候点击
 * @brief EasyPattern::mousePressEvent
 * @param event 鼠标事件的对象，里面包含鼠标点击的信息
 */
void EasyPattern::mousePressEvent(QMouseEvent *event)
{
    ///如果点在了格子上
    if(event->x()>=0 && event->x()<=320 && event->y()>=45 && event->y()<=365){
        ///如果游戏没有结束
        if(!isgameover){
            ///记录下点击的行标和列标，还有点击的按键
            clickedi = (event->y()-45)/32;
            clickedj = event->x()/32;
            clickedBtn = event->button();
//            qDebug()<<clickedi<<" "<<clickedj;
            ///触发点击信号
            emit this->click();
        }
    }
}

/**
 * 随机生成地雷，简单模式15个地雷
 * @brief EasyPattern::creatMine
 */
void EasyPattern::creatMine()
{
    qsrand((uint)time(0));///随机播种
    while(mineNumber<15){///如果地雷少于15个，即循环生成地雷
        int i = qrand()%10;///[0,9]之间随机获取行标
        int j = qrand()%10;///[0,9]之间随机获取列标
//        qDebug()<<"周围的雷："<<checkMine(i,j);
        ///如果地雷周围的地雷少于等于2个，并且i,j处不在已生成地雷集合里
        ///为什么地雷周围的个数要少于2了，因为如果小于3、4或更高的话，可能导致一个格子
        ///周围的地雷大于6，而这个游戏设定就是，格子周围地雷不能超过6
        if((checkMine(i,j)<=2) && (!iscontain(row,col,i,j))){
            row.append(i);///将行标i加入地雷行标集合
            col.append(j);///将列标j加入地雷列标集合
            map[i][j]=8;///此时地图更新为8(地雷MINE)
            mineNumber++;///地雷个数+1
        }
    }
}

/**
 * 设置label图标
 * @brief EasyPattern::setLabelIcon
 * @param label 待设置的图标
 * @param pic 图标代码
 */
void EasyPattern::setLabelIcon(QLabel* label,int pic){
    QPixmap pix;///新建一个图片对象
    ///根据pic的值加载不同的图片
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
    ///给label设置图片
    label->setPixmap(pix);
}

/**
 * 判断vis是否全处于点开状态 或者 全是未点开的雷
 * @brief EasyPattern::isVisOver
 * @return 满足全是点开或者未点开的全是雷就返回true
 */
bool EasyPattern::isVisOver()
{
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
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
bool EasyPattern::isGameOver()
{
    ///如果游戏已经结束，就直接返回true
    if(isgameover)return true;
    ///满足下面条件游戏胜利，返回true
    if((mineNumber==0&&flagNumber==15) || isVisOver()){
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
void EasyPattern::updateLabel1(QLabel *a)
{
    a->setText(QString("时间：%1s").arg(sec));
}

/**
 * 更新剩余地雷标签
 * @brief EasyPattern::updateLabel1
 * @param b 待更新标签
 */
void EasyPattern::updateLabel2(QLabel *b)
{
    b->setText(QString("剩余地雷：%1").arg(mineNumber));
}
