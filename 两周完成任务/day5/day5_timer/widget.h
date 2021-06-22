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
    void timerEvent(QTimerEvent *event);

private slots:
    void on_btn_begin1_clicked();

    void on_btn_stop1_clicked();

    void on_btn_begin2_clicked();

    void on_btn_begin3_clicked();

    void on_btn_stop3_clicked();

    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    int id1;
    int id2;
};

#endif // WIDGET_H
