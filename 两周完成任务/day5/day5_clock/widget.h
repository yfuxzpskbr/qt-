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

private:
    Ui::Widget *ui;

private:
    int sec_1;
    bool sec;
    int sec_2;
    bool sec2;
    int min_1;
    bool min;
    int min_2;
};

#endif // WIDGET_H
