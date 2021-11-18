#include "QHelper.h"
#include <iostream>
#include <bitset>
#include <QDebug>
#include <string>
#include <sstream>
#include <QDate>
#include <QtMath>

using namespace std;

char AssicToChar(int assicCode)
{
    return (char)assicCode;
}


int HexToAssic(QString str)
{
    // 加入验证
    if(str.size() == 0)
    {
        qDebug() << "In HexToString(), str is null" <<endl;
        return 0;
    }
    int assicValue = stoi(str.toStdString(),nullptr,16);
    return assicValue;
}

void delay(int ms)
{
    // 延时处理
    QElapsedTimer t;
    t.start();
    while (t.elapsed() < ms);
}

void removeEnter(QString *str)
{
    str -> replace("\n\r", "");
}

QString getDateTimeString()
{
    // 获取当前时间，设置文件名
    QDateTime nowTime = QDateTime::currentDateTime();
    QString now = nowTime.toString("yyyy-MM-dd hh:mm");
    QString timeString = "[" + now + "]";    //文件名称
    qDebug() << "生成Excel文件名称" << timeString;
    return timeString;
}

long double hexToDec(QString hexData)
{
    QByteArray hexArray = hexData.toUtf8();
    long double result = 0;
    int mi = 0;
    for (int i = hexArray.size()-1; i >= 0; i--) {
        if (hexArray[i] == 'A') {
            result += qPow(16, mi) * 10;
        } else if (hexArray[i] == 'B') {
            result += qPow(16, mi) * 11;
        } else if (hexArray[i] == 'C') {
            result += qPow(16, mi) * 12;
        } else if (hexArray[i] == 'D') {
            result += qPow(16, mi) * 13;
        } else if (hexArray[i] == 'E') {
            result += qPow(16, mi) * 14;
        } else if (hexArray[i] == 'F') {
            result += qPow(16, mi) * 15;
        } else {
            result += qPow(16, mi) * (hexArray[i] - 48);
        }
        mi++;
    }
    return result;
}

void removeSpace(QString *str) {
    str ->replace(" ", "");
}

unsigned char *qStringToUChar(QString str) {
    unsigned char *result = nullptr;
    string resStr = str.toStdString();
    if (str != "") {
        result = (unsigned char *)resStr.c_str();
    }
    qDebug() << *result;
    return result;
}

QString uCharToQString(unsigned char uchar)
{
    QString str(uchar);
    qDebug() << str;
    return str;
}

void commandResultGen(QString *strPtr, QString opCommand, int numSize, unsigned char lookTable[], unsigned short CRC)
{
    strPtr -> append(opCommand);
    for (int i = 0; i < numSize; i++)
    {
        QString qUnicode = QString("%1").arg(lookTable[i], 2, 16);
        strPtr -> append(qUnicode);
    }
    // CRC保存
    strPtr -> append(QString("%1").arg(CRC, 4, 16));
    strPtr -> append("09D7");
    // 转成大写并空位补0
    strPtr -> replace(" ", "0");
}

QString hexToFloat(QString str)
{
    int c = str.toInt(nullptr, 16);
    float d = *(float*)&c;
    QString radiation = QString("%1").arg(d);
    return radiation;
}
