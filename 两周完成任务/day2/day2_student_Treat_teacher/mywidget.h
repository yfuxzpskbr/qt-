#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include "teacher.h"
#include "student.h"

class myWidget : public QWidget
{
    Q_OBJECT

public:
    myWidget(QWidget *parent = 0);
    ~myWidget();
    student *stu;
    teacher *tea;
    void classOver();
};

#endif // MYWIDGET_H
