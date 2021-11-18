#ifndef TIMEDTASK_H
#define TIMEDTASK_H

#include <QObject>

class TimedTask : public QObject
{
    Q_OBJECT
public:
    explicit TimedTask(QObject *parent = nullptr);

signals:

};

#endif // TIMEDTASK_H
