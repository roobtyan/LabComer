#ifndef QHELPER_H
#define QHELPER_H

#include <iostream>
#include <QString>
#include <QElapsedTimer>
#include <QSerialPort>
#include <QSerialPortInfo>

using namespace std;

/**
 * @brief Assic转字符
 * @param string
 * @return String
 */
char AssicToChar(int assicCode);

/**
 * @brief 十六进制转Assic
 * @param str
 * @return
 */
int HexToAssic(QString str);

/**
 * @brief 设置延迟时间
 * @param ms
 */
void delay(int ms);

/**
 * @brief 去除字符串中的回车换行
 * @param str
 * @return
 */
void removeEnter(QString *str);

/**
 * @brief 去掉字符串中的空格
 * @param str
 */
void removeSpace(QString *str);

/**
 * @brief 获取当前时间,并表示为字符串
 * @return
 */
QString getDateTimeString();

/**
 * @brief 十六进制数转十进制
 * @param hexData
 * @return
 */
long double hexToDec(QString hexData);

/**
 * @brief QString类型转UChar
 * @param str
 * @return
 */
unsigned char * qStringToUChar(QString str);

/**
 * @brief 十六进制转float
 * @param str
 * @return
 */
QString hexToFloat(QString str);

/**
 * @brief unsigned char 转 QString
 * @param uchar
 * @return
 */
QString uCharToQString(unsigned char uchar);

/**
 * @brief 指令拼装，格式：指令头+数据+CRC+指令结尾
 * @param strPtr
 * @param numSize
 * @param lookTable
 * @param CRC
 */
void commandResultGen(QString *strPtr, QString opCommand, int numSize, unsigned char lookTable[], unsigned short CRC);


#endif // QHELPER_H
