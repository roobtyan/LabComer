#ifndef TIMEDTASK_H
#define TIMEDTASK_H

#include <QObject>

class TimedTask : public QObject
{
    Q_OBJECT
public:
    explicit TimedTask(QObject *parent = nullptr);

    // 间隔1S发送
    void autoSendTelCommandTask();

    /**
     * @brief 设置是否自动发送的标志位
     * @param flag
     */
    void openAutoSendTelCommandTask(bool flag);

signals:
    /**
     * @brief 发送命令的信号，与Serial绑定
     * @param command
     */
    void sendCommand(QString command);

private:
    bool flagAutoSend = 0;
};

#endif // TIMEDTASK_H
