#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include <QString>

class myPushButton : public QPushButton
{
    Q_OBJECT
public:
   myPushButton(QString ImagePath1,QString ImagePath2 = "");
   void bounce();
   void mousePressEvent(QMouseEvent *e);
   void mouseReleaseEvent(QMouseEvent *e);
signals:

public slots:
private:
   QString path1;
   QString path2;
};

#endif // MYPUSHBUTTON_H
