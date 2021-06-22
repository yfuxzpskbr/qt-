#include "item.h"
#include <QPixmap>

void Item::setPos(int x, int y)
{
    this->PosX = x;
    this->PosY = y;
    this->setFixedSize(50,50);
}

void Item::SetmyIcon(int n)
{

    switch (n) {
    case 0:
        this->setPixmap(QPixmap(":/res/blank.png"));
        break;
    case 1:
        this->setPixmap(QPixmap(":/res/wall.png"));
        break;
    case 2:
        this->setPixmap(QPixmap(":/res/player.png"));
        break;
    case 3:
        this->setPixmap(QPixmap(":/res/box.jpg"));
        break;
    case 4:
        this->setPixmap(QPixmap(":/res/star.png"));
        break;
    case 6:
        this->setPixmap(QPixmap(":/res/player.png"));
        break;
    case 7:
        this->setPixmap(QPixmap(":/res/boxindes.jpg"));
        break;
    default:
        break;
    }

}

int Item::getX()
{
    return PosX;
}

int Item::getY()
{
    return PosY;
}
