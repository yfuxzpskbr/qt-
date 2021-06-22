#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>
#include <QString>

class student : public QObject
{
    Q_OBJECT
public:
    explicit student(QObject *parent = 0);

signals:

public slots:
    void treat();
    void treat(QString food);

};

#endif // STUDENT_H
