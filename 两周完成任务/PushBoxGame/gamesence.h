#ifndef GAMESENCE_H
#define GAMESENCE_H

#include "dataconfig.h"
#include <QMainWindow>
#include <QKeyEvent>
#include <QLabel>


#include "item.h"

class gameSence : public QMainWindow
{
    Q_OBJECT
public:
    gameSence(int level);
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
    ~gameSence();
signals:
    void back();
    void reset();
    void MOVE(int m); //0上 1下 2左 3右  键盘按下信号
    void win();
public slots:
private:
    int Level;
    int *map[7][7];
    int playerPosX;
    int playerPosY;
    int I;
    int J;
    Item *dmap[7][7];
    int incnt;
    int boxcnt = 0;
    bool Win = false;
    dataconfig *Data = nullptr;
public:
    gameSence *next = nullptr;
};

#endif // GAMESENCE_H
