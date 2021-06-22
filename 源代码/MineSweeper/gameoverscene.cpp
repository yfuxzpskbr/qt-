#include "gameoverscene.h"

GameOverScene::GameOverScene(int Case)
{
    QLabel * label = new QLabel(this);
    QPixmap pix;
    if(Case == 0){
        this->setFixedSize(pix.width(),pix.height());
        label->setText("对不起，你踩到雷了");
        label->setStyleSheet("QLabel{color:blue;font-size:30;}");
    }
}
