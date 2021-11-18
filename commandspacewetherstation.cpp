#include "commandspacewetherstation.h"
#include "ui_commandspacewetherstation.h"
#include "QHelper.h"
#include <QDebug>
#include <QMessageBox>

CommandSpaceWetherStation::CommandSpaceWetherStation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CommandSpaceWetherStation)
{
    ui->setupUi(this);
}

CommandSpaceWetherStation::~CommandSpaceWetherStation()
{
    delete ui;
}

QString CommandSpaceWetherStation::spaceWetherStateValues(QString space_weather_state, QString space_weather_voltage)
{
    unsigned char space_weather_stateed = space_weather_state.toUInt();
    unsigned short space_weather_voltageed = space_weather_voltage.toUShort();
    unsigned char head_HEMPJET1 = 0x21; // 指令类型
    unsigned char head_HEMPJET2 = 0xE2; // 指令帧头
    unsigned char head_HEMPJET3 = 0x25; // 指令帧头
    unsigned char head_HEMPJET4 = 0x10; // 指令帧头
    unsigned char head_HEMPJET5 = 0x02; // 指令帧头
    unsigned char space_weather_command[3] = {};
    space_weather_command[0] = space_weather_stateed;
    space_weather_command[1] = (unsigned char)(space_weather_voltageed >> 8);
    space_weather_command[2] = (unsigned char)(space_weather_voltageed & 0x00FF);
    head_HEMPJET5 = 0x12;
    unsigned short CRC_space_weather = head_HEMPJET1 + head_HEMPJET2 + head_HEMPJET3 + head_HEMPJET4 + head_HEMPJET5;
    for (int i = 0; i < 3; i++)
    {
        CRC_space_weather += space_weather_command[i];
    }
    QString resultTemp;
    QString result;
    commandResultGen(&resultTemp, "EB90000821E2251012", 3, space_weather_command, CRC_space_weather);
    result = resultTemp.toUpper();
    return result;
}

void CommandSpaceWetherStation::on_pushButton_clicked()
{
    // 获取数据
    QString space_weather_state = ui -> space_weather_state_textEdit -> toPlainText();
    QString space_weather_voltage = ui -> space_weather_voltage_textEdit -> toPlainText();
    // 校验
    if (space_weather_state == "" || space_weather_voltage == "") {
        QMessageBox::about(NULL, "ERROR", "Null value appears");
        return;
    }
    // 计算命令
    QString result = spaceWetherStateValues(space_weather_state, space_weather_voltage);
    emit sendSpaceWetherState(result);
    this -> close();
}
