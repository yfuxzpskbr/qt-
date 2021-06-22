#ifndef CHOOSELEVELSENCE_H
#define CHOOSELEVELSENCE_H

#include <QMainWindow>
#include "playgame.h"

class chooseLevelSence : public QMainWindow
{
    Q_OBJECT
public:
    explicit chooseLevelSence(QWidget *parent = 0);

signals:
    //写一个信号，告诉主场景点击了返回
    void chooseBack();
public slots:
public:
    void paintEvent(QPaintEvent *);
private:
    playGame * Game = nullptr;
};

#endif // CHOOSELEVELSENCE_H
