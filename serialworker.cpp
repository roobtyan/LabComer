#include "serialworker.h"
#include <QDebug>
#include <QThread>
#include <QMessageBox>
#include "QHelper.h"
#include "dataprocess.h"
#include <remotecommand.h>
#include <QDateTime>

/**
 * 多线程串口开发流程：
 * 1. 定义Thread并将serial对象移动到进程中
 * 2. connect函数绑定初始化方法
 * 3. 启动线程
 */

SerialWorker::SerialWorker(QObject *parent)
    : QObject(parent)
{

}

SerialWorker::~SerialWorker()
{
    delete port;
}

void SerialWorker::initSerialPort()
{
    this->port = new QSerialPort();
    connect(port, &QSerialPort::readyRead,
            this, &SerialWorker::doDataReciveWork);        // 主线程通知子线程接收数据的信号
}

bool SerialWorker::openThreadPort(QSerialPort *port, QString portName, qint32 baudRate,
                           QSerialPort::DataBits dataBits, QSerialPort::Parity parity,
                           QSerialPort::StopBits stopBits, QSerialPort::FlowControl flowControl)
{
    port->setPortName(portName);
    port->setBaudRate(baudRate);
    port->setDataBits(dataBits);
    port->setParity(parity);
    port->setStopBits(stopBits);
    port->setFlowControl(flowControl);

    if (port->open(QIODevice::ReadWrite))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void SerialWorker::openPort(QString com, QString buad, QString check, int comId)
{
    qint32 baudRate = buad.toInt();    // 定义波特率
    QSerialPort::Parity comParity = QSerialPort::NoParity;  // 定义校验位，默认无校验
    // 通过条件判断来选择校验位
    if (check == "NONE") {
        comParity = QSerialPort::NoParity;
    } else if (check == "ODD") {
        comParity = QSerialPort::OddParity;
    } else if (check == "EVEN") {
        comParity = QSerialPort::EvenParity;
    }

    // 开启串口
    if(openThreadPort(port, com, baudRate, QSerialPort::Data8, comParity,
                 QSerialPort::OneStop, QSerialPort::NoFlowControl)) {
        emit openPortSuccess("open " + com + "[" + buad + "]" + " success!", comId); // 打开成功返回
    } else {
        emit openPortSuccess("open " + com + "fail", comId);    // 打开失败返回
    }
}

void SerialWorker::doDataSendWork(QString command)
{
    QByteArray qb = QByteArray::fromHex (command.toLatin1().data());
    port -> write(qb);
}

void SerialWorker::doDataReciveWork()
{
    // 1.收到数据
    QByteArray buffer = port->readAll();
    QString bufStr = buffer.toHex().toUpper();
    // 2.进行数据处理
    // 包含EB90即为遥测指令读取的数据，需要经过特殊处理,发送到数据表
    if (bufStr.contains("EB90")) {
        DataProcess *dataProcess = new DataProcess();
        QList<RemoteCommand> remoteList = dataProcess -> mainControlDataProcess(bufStr);
        emit readyReadTable(remoteList);
    } else {
        QString result = bufStr + "\n";
        emit readyRead(result);
    }
}
