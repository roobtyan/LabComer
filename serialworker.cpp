#include "serialworker.h"
#include <QDebug>
#include <QThread>
#include <QMessageBox>
#include "QHelper.h"

SerialWorker::SerialWorker(QObject *parent)
    : QObject(parent)
{

}

SerialWorker::~SerialWorker()
{
    delete port;
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

void SerialWorker::openFlow(QString COM, QString command)
{
    if(openThreadPort(port, COM, QSerialPort::Baud2400, QSerialPort::Data7, QSerialPort::NoParity,
                 QSerialPort::OneStop, QSerialPort::NoFlowControl))
    {
        emit openPortSuccess();
        port -> write(command.toLocal8Bit());
    }
}

void SerialWorker::openPress(QString COM, QString command)
{
    // 波特率9600，数据位8位，无校验位，一位停止位
    if(openThreadPort(port, COM, QSerialPort::Baud9600, QSerialPort::Data8, QSerialPort::NoParity,
             QSerialPort::OneStop, QSerialPort::NoFlowControl))
    {
        emit openPortSuccess();
        port -> write(command.toLocal8Bit());
    }
}

void SerialWorker::openTemp(QString COM, QString command, int flag)
{
    // 将线程定义为温度标识
    tempFlag = flag;
    //具体数据还未确定
    if(openThreadPort(port, COM, QSerialPort::Baud9600, QSerialPort::Data8, QSerialPort::NoParity,
             QSerialPort::OneStop, QSerialPort::NoFlowControl))
    {
        emit openPortSuccess();
        port -> write(command.toLocal8Bit());
    }
}

void SerialWorker::initSerialPort()
{
    this->port = new QSerialPort();
    connect(port, &QSerialPort::readyRead,
            this, &SerialWorker::doDataReciveWork);        // 主线程通知子线程接收数据的信号
}

void SerialWorker::doDataSendWork(const QByteArray data)
{
//    qDebug() <<  "子线程槽函数发送数据：" << data << "线程ID：" << QThread::currentThreadId();
    port -> write(data);
}

void SerialWorker::doDataReciveWork()
{
    // 1.收到数据
    QByteArray buffer = port->readAll();
    // 2.进行数据处理
    resultStr.append(buffer);
    if(resultStr.contains("\r\n"))
    {
        // 判断是否为温度计线程
        if (tempFlag == 1)
        {
            // 根据温度计数据的返回格式，截取第7~10位置的数据
            QString tempRes = resultStr.mid(6, 4);
//            qDebug() << "截取的温度字符串是：" << tempRes;
            emit sendResultToTemp(tempRes);
            resultStr.clear();
        }
        else
        {
            // 区分流量数据及压力数据
            if (resultStr.contains("sccm"))
            {
                emit sendResultToGui(resultStr);
                resultStr.clear();
            }
            else
            {
                emit sendResultToPress(resultStr);
                resultStr.clear();
            }
        }
    }
}
