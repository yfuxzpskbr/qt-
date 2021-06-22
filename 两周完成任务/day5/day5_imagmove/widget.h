#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *);

private:
    Ui::Widget *ui;
    int Posx=0;
};

#endif // WIDGET_H
