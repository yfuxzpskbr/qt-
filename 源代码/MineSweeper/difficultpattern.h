#ifndef DIFFICULTPATTERN_H
#define DIFFICULTPATTERN_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QPainter>
#include <QPixmap>
#include <QLabel>
#include <QDebug>
#include <cstdlib>
#include <QTimer>
#include <QDialog>
#include <ctime>
#include <QVector>
#include <QMouseEvent>
#include <cstring>
#include "mypushbutton.h"
#include "gameoverdialog.h"

namespace Ui {
class DifficultPattern;
}

class DifficultPattern : public QMainWindow
{
    Q_OBJECT

public:
    explicit DifficultPattern(QWidget *parent = 0);
    ~DifficultPattern();
    void paintEvent(QPaintEvent *); //覆写绘图事件
    void creatMine();//随机生成120个地雷
    int checkMine(int i, int j);//检查方格周围的地雷个数
    bool iscontain(QVector<int> p,QVector<int>q,int m,int n);//判断(m,n)处是否已经是地雷
    void initMap();//初始化地图，给不是地雷的格子填上数字
    void test();//输出数字版地图
    void drawMap();//画地图
    void sweep(int clickedBtn, int i, int j, bool click);///程序精髓，递归实现扫雷
    void mousePressEvent(QMouseEvent *event);//鼠标点击事件
    void setLabelIcon(QLabel* label,int pic);//给label设置图标
    bool isVisOver();//判断vis是否全被访问过
    bool isGameOver();//判断游戏是否结束
    void updateLabel1(QLabel* a);//更新时间label
    void updateLabel2(QLabel* b);//更新剩余地雷label
private:
    Ui::DifficultPattern *ui;
    int vis[20][40];//标记地图是否被访问  -1表示已经翻开，0表示未翻开，1表示插旗状态、2表示问号状态
    int map[20][40];//地图数组
    QVector<int> row;//存储地雷所在行
    QVector<int> col;//存储地雷所在列
    QLabel *mapLabel[20][40];//地图标签
    int mineNumber=0;//地雷个数困难模式120个
    int flagNumber=0;//旗子的数量
    int clickedi = -1;//鼠标点击的i位置
    int clickedj = -1;//鼠标点击的j位置
    int clickedBtn;//鼠标点击的按钮
    bool isgameover = false;//游戏结束标志
    int sec = 0;//游戏已运行时间
    QTimer *timer1 = new QTimer(this);//定时器1，时间自动计时
    QTimer *timer2 = new QTimer(this);//定时器2，更新剩余地雷
signals:
    void back();//返回信号
    void click();//点击信号
    void gameOver(int Case);//游戏结束信号、1代表游戏胜利、0代表游戏结束
};

#endif // DIFFICULTPATTERN_H
