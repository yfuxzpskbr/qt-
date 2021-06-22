#ifndef PLAYGAME_H
#define PLAYGAME_H

#include <QMainWindow>
#include "mycoin.h"
class playGame : public QMainWindow
{
    Q_OBJECT
public:
    explicit playGame(QWidget *parent = 0);
    playGame(int level);
    void paintEvent(QPaintEvent *);
    myCoin *coinBtn[4][4];
signals:
    void chooseBack();
public slots:
private:
    int levelIndex;
    int gameArray[4][4];
    bool isSucceed;

};

#endif // PLAYGAME_H
