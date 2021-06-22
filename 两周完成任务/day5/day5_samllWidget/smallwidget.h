#ifndef SMALLWIDGET_H
#define SMALLWIDGET_H

#include <QWidget>

namespace Ui {
class smallwidget;
}

class smallwidget : public QWidget
{
    Q_OBJECT

public:
    explicit smallwidget(QWidget *parent = 0);
    ~smallwidget();
    void setValue(int value);
    int getValue();

private:
    Ui::smallwidget *ui;
};

#endif // SMALLWIDGET_H
