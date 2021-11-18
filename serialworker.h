#ifndef SERIALWORKER_H
#define SERIALWORKER_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>

class SerialWorker : public QObject
{
    Q_OBJECT
public:
    explicit SerialWorker(QObject *parent = nullptr);
    ~SerialWorker();

    QSerialPort *port;
    // 全局变量
    QString resultStr;      // 用于接收最终的返回值
    bool tempFlag = 0;      // 判断是否为温度计线程

    /**
     * @brief 打开串口
     * @param port
     * @param portName
     * @param baudRate
     * @param dataBits
     * @param parity
     * @param stopBits
     * @param flowControl
     * @return
     */
    bool openThreadPort(QSerialPort *port, QString portName, qint32 baudRate,
                               QSerialPort::DataBits dataBits, QSerialPort::Parity parity,
                               QSerialPort::StopBits stopBits, QSerialPort::FlowControl flowControl);
    /**
     * @brief 初始化执行
     */
    void initSerialPort();

    /**
     * @brief 关闭串口
     */
    void closePort()
    {
        port->clear();
        port->close();
    }

    /**
     * @brief 获得可用的串口名
     * @return
     */
    QStringList getAvailablePortNameList() const
    {
        QStringList portName;
        foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
        {
            portName << info.portName();
        }
        return portName;
    }

signals:

    /**
     * @brief 当数据准备好就读取返回数据
     * @param data
     */
    QString readyRead(QByteArray data);

    /**
     * @brief 传送数据到流量计界面
     * @param result
     */
    void sendResultToGui(QString result);

    /**
     * @brief 发送数据到压力计界面
     * @param result
     */
    void sendResultToPress(QString result);

    /**
     * @brief 发送数据到温度计界面
     * @param result
     */
    void sendResultToTemp(QString result);

    /**
     * @brief 打开串口成功
     */
    void openPortSuccess();

public slots:

    void openFlow(QString COM, QString command);

    void openPress(QString COM, QString command);

    void openTemp(QString COM, QString command, int tempFlag);

    /**
     * @brief 多线程数据发送
     * @param data
     */
    void doDataSendWork(const QByteArray data);
    /**
     * @brief 多线程数据接收
     */
    void doDataReciveWork();

private:
};

#endif // SERIALWORKER_H
