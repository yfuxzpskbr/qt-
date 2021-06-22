#ifndef PLAYER_H
#define PLAYER_H

#include <QLabel>

class Item : public QLabel
{
    Q_OBJECT
public:
    Item() = default;
    void setPos(int x,int y);
    void SetmyIcon(int n);
    int getX();
    int getY();

signals:

public slots:
private:
    int PosX;
    int PosY;
};

#endif // PLAYER_H
