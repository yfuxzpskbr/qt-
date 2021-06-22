#ifndef MYLABEL_H
#define MYLABEL_H
#include <QDebug>
#include <QLabel>

class myLabel : public QLabel
{
    Q_OBJECT
public:
    explicit myLabel(QWidget *parent = 0);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);

    virtual void mouseMoveEvent(QMouseEvent *ev);
    virtual void mousePressEvent(QMouseEvent *ev);
    virtual void mouseReleaseEvent(QMouseEvent *ev);
    bool event(QEvent *e);



signals:

public slots:
};

#endif // MYLABEL_H
