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
