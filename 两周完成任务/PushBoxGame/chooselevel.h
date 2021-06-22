#ifndef CHOOSELEVEL_H
#define CHOOSELEVEL_H

#include <QMainWindow>
#include "gamesence.h"

namespace Ui {
class chooseLevel;
}

class chooseLevel : public QMainWindow
{
    Q_OBJECT

public:
    explicit chooseLevel(QWidget *parent = 0);
    ~chooseLevel();
    void paintEvent(QPaintEvent *);
signals:
    void back();


private:
    Ui::chooseLevel *ui;
    gameSence *Game = nullptr;
};

#endif // CHOOSELEVEL_H
