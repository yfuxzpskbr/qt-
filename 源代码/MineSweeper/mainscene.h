#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include <QPainter>
#include <QPixmap>
#include <QDebug>
#include <QPropertyAnimation>
#include <QLabel>
#include <QTimer>
#include "mypushbutton.h"
#include "easypattern.h"
#include "commonpattern.h"
#include "difficultpattern.h"


namespace Ui {
class MainScene;
}

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainScene(QWidget *parent = 0);
    ~MainScene();
    void paintEvent(QPaintEvent*);     //绘图事件
    void loadTitle();   //加载标题
    EasyPattern *easy = nullptr;    //简单模式界面
    CommonPattern *common = nullptr;    //一般模式界面
    DifficultPattern *difficult = nullptr;  //困难模式界面
private:
    Ui::MainScene *ui;

};

#endif // MAINSCENE_H
