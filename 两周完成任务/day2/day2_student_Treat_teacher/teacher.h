#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>
#include <QString>

class teacher : public QObject
{
    Q_OBJECT
public:
    explicit teacher(QObject *parent = 0);

signals:
    void hungry();
    void hungry(QString food);

public slots:

};

#endif // TEACHER_H
