#ifndef GAMEOVERDIALOG_H
#define GAMEOVERDIALOG_H

#include <QDialog>
#include <QPaintEvent>
#include <QPixmap>
#include <QPainter>

namespace Ui {
class GameOverDialog;
}

class GameOverDialog : public QDialog
{
    Q_OBJECT

public:
    GameOverDialog(int Case, QWidget *parent = 0, int sec=0);//自定义构造函数
    ~GameOverDialog();
    void paintEvent(QPaintEvent *);//绘图事件

private:
    Ui::GameOverDialog *ui;
};

#endif // GAMEOVERDIALOG_H
