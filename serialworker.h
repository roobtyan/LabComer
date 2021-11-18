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
    void closePort(int comId)
    {
        port->clear();
        port->close();
        QString result;
        result.append("close COM");
        result.append(comId);
        result.append(" success!");
        emit closePortStatus(result, comId);
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
    QString readyRead(QString data);

    /**
     * @brief 发送数据到GUI
     * @param result
     */
    void sendResultToGui(QString result);

    /**
     * @brief 打开串口成功或失败
     */
    void openPortSuccess(QString message, int comId);

    /**
     * @brief closePortStatus
     * @param message
     * @param comId
     */
    void closePortStatus(QString message, int comId);

public slots:

    /**
     * @brief openPort
     * @param com
     * @param buad
     * @param check
     * @param comId 用于判断使用的是哪个串口模块 1/2……
     */
    void openPort(QString com, QString buad, QString check, int comId);

    /**
     * @brief 多线程数据发送
     * @param data
     */
    void doDataSendWork(QString command);
    /**
     * @brief 多线程数据接收
     */
    void doDataReciveWork();

private:

    QSerialPort *port;
};

#endif // SERIALWORKER_H
