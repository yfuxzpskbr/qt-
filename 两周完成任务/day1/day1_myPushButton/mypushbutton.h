#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class myPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit myPushButton(QPushButton *parent = nullptr);
    ~myPushButton();
signals:

public slots:
};

#endif // MYPUSHBUTTON_H
