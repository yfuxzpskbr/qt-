#ifndef DIFFICULPATTERN_H
#define DIFFICULPATTERN_H

#include <QMainWindow>

namespace Ui {
class DifficulPattern;
}

class DifficulPattern : public QMainWindow
{
    Q_OBJECT

public:
    explicit DifficulPattern(QWidget *parent = 0);
    ~DifficulPattern();

private:
    Ui::DifficulPattern *ui;
};

#endif // DIFFICULPATTERN_H
