#include "gameoverdialog.h"
#include "ui_gameoverdialog.h"

GameOverDialog::GameOverDialog(int Case, QWidget *parent,int sec) :
    QDialog(parent),
    ui(new Ui::GameOverDialog)
{
    ui->setupUi(this);
    ///设置图标
    this->setWindowIcon(QIcon(":/res/MineClearance.png"));
    ///根据参数设置内容
    if(Case==0){
        this->setWindowTitle("游戏结束");
        ui->label->setText("你踩到雷了,游戏失败");

    }
    if(Case==1){
        this->setWindowTitle("游戏胜利");
        ui->label->setText(QString(
"恭喜你，雷区已清扫完毕\n\
    完成时间：%1s").arg(sec));
    }
    ui->label->setStyleSheet("QLabel{color:yellow;font-size:20px;}");
}

GameOverDialog::~GameOverDialog()
{
    delete ui;
}

/**
 * 画背景
 * @brief EasyPattern::paintEvent
 * @param QPaintEvent*  由于不需要使用参数，故不用指定变量名
 */
void GameOverDialog::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/LoseGame.png");
    painter.drawPixmap(0,0,pix.width(),pix.height(),pix);
}
