#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include <QString>
#include <QPropertyAnimation>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushButton(QWidget *parent = 0);
    MyPushButton(QString path);
    void bounce();  //跳动函数
signals:

public slots:
};

#endif // MYPUSHBUTTON_H
