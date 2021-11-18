#include "commandheating.h"
#include "ui_commandheating.h"
#include "QMessageBox"
#include "QDebug"
#include "QHelper.h"

CommandHeating::CommandHeating(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CommandHeating)
{
    ui->setupUi(this);
}

CommandHeating::~CommandHeating()
{
    delete ui;
}

QString CommandHeating::haetingValues(QString heating_state, QString heating_zone1_temp,
                                      QString heating_zone2_temp, QString heating_voltage_set)
{
    // 转换
    unsigned char heating_stateed = heating_state.toUInt();
    unsigned short heating_zone1_temped = heating_zone1_temp.toUShort(); // ℃ begin heat tank threshold temperature
    unsigned short heating_zone2_temped = heating_zone2_temp.toUShort(); // ℃ begin heat valve threshold temperature
    unsigned short heating_voltage_seted = heating_voltage_set.toUShort();
    // 其他参数
    unsigned char head_HEMPJET1 = 0x21; // 指令类型
    unsigned char head_HEMPJET2 = 0xE2; // 指令帧头
    unsigned char head_HEMPJET3 = 0x25; // 指令帧头
    unsigned char head_HEMPJET4 = 0x10; // 指令帧头
    unsigned char head_HEMPJET5 = 0x02; // 指令帧头
    unsigned char heating_command[7] = {};

    heating_command[0] = heating_stateed;
    heating_command[1] = (unsigned char)(heating_zone1_temped >> 8);
    heating_command[2] = (unsigned char)(heating_zone1_temped & 0x00FF);
    heating_command[3] = (unsigned char)(heating_zone2_temped >> 8);
    heating_command[4] = (unsigned char)(heating_zone2_temped & 0x00FF);
    heating_command[5] = (unsigned char)(heating_voltage_seted >> 8);
    heating_command[6] = (unsigned char)(heating_voltage_seted & 0x00FF);

    head_HEMPJET5 = 0x14;
    unsigned short CRC_heating = head_HEMPJET1 + head_HEMPJET2 + head_HEMPJET3 + head_HEMPJET4 + head_HEMPJET5;
    for (int i = 0; i < 7; i++)
    {
        CRC_heating += heating_command[i];
    }

    // 结果
    QString resultTemp;
    QString result;
    commandResultGen(&resultTemp, "EB90000C21E2251014", 7, heating_command, CRC_heating);
    result = resultTemp.toUpper();
    return result;
}

void CommandHeating::on_pushButton_clicked()
{
    // 获取参数
    QString heating_state = ui -> heating_state_textEdit -> toPlainText();
    QString heating_zone1_temp = ui -> heating_zone1_temp_textEdit -> toPlainText();
    QString heating_zone2_temp = ui -> heating_zone2_temp_textEdit -> toPlainText();
    QString heating_voltage_set = ui -> heating_voltage_set_textEdit -> toPlainText();
    // 校验
    if (heating_voltage_set == "" || heating_voltage_set == "" || heating_voltage_set == "" || heating_voltage_set == "") {
        QMessageBox::about(NULL, "ERROR", "Null value appears");
        return;
    }
    // 计算命令
    QString result = haetingValues(heating_state, heating_zone1_temp, heating_zone2_temp, heating_voltage_set);
//    if ("EB90000C21E225101401001400149C40025109D7" == result) qDebug() << result;
    emit sendHeatingCommandToMainWindow(result);
    this -> close();
}
