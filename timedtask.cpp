#include "timedtask.h"
#include "QHelper.h"
#include "QDebug"
#include "QThread"

TimedTask::TimedTask(QObject *parent) : QObject(parent)
{

}

void TimedTask::autoSendTelCommandTask()
{
    if (flagAutoSend) {
        emit sendCommand("EB9000021100001109D7");
    }
}

void TimedTask::openAutoSendTelCommandTask(bool flag)
{
    flagAutoSend = flag;
}
