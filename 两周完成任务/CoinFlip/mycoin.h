#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>
#include <QString>
#include <QTimer>

class myCoin : public QPushButton
{
    Q_OBJECT
public:
    explicit myCoin(QWidget *parent = 0);
    myCoin(QString adImage);
    void setPosX(int x);
    void setPosY(int y);
    void setflag(bool flag);
    void changeFlag();
    bool isRight_(int i,int j);
    int getPosX();
    int getPosY();
    void mousePressEvent(QMouseEvent *e);
    bool getFlag();
    void setIsSucceed(bool t);
signals:

public slots:
private:
    QString ImagePath;
    int posX; //x坐标
    int posY; //y坐标
    bool flag;  //1代表正面 0代表反面
    int start = 1;
    int end = 8;
    QTimer *timer1 = new QTimer(this);
    QTimer *timer2 = new QTimer(this);
    bool isAnimation = false;
    bool isSucceed = false;
};

#endif // MYCOIN_H
