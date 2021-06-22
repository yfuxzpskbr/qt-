#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include <QString>

class myPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit myPushButton(QWidget *parent = 0);
    myPushButton(QString normalImage,QString pressedImage="");
    void bounce();
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
signals:

public slots:
private:
    QString normalImagePath;
    QString pressedImagePath;

};

#endif // MYPUSHBUTTON_H
