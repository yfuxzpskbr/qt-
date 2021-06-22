#ifndef MAINSENCE_H
#define MAINSENCE_H

#include <QMainWindow>
#include "chooselevelsence.h"
namespace Ui {
class MainSence;
}

class MainSence : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainSence(QWidget *parent = 0);
    ~MainSence();

private:
    Ui::MainSence *ui;
    chooseLevelSence* chooseLevel = nullptr;
public:
    void paintEvent(QPaintEvent *);
};

#endif // MAINSENCE_H
