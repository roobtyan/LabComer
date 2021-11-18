#include "commandhempjetadvanced.h"
#include "ui_commandhempjetadvanced.h"
#include <QDebug>
#include <QMessageBox>
#include "QHelper.h"

CommandHempJetAdvanced::CommandHempJetAdvanced(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CommandHempJetAdvanced)
{
    ui->setupUi(this);
}

CommandHempJetAdvanced::~CommandHempJetAdvanced()
{
    delete ui;
}

QString CommandHempJetAdvanced::hempJetAdvancedValues(QString riseTime_HEMPJET, QString closeTime_HEMPJET,
                                                      QString riseVoltage_HEMPJET, QString holdVoltage_HEMPJET,
                                                      QString closeVoltage_HEMPJET, QString VoltageSet_ad_HEMPJET)
{
    QString resultTemp;
    QString result;
    // 格式转换
    unsigned short riseTime_HEMPJETed = riseTime_HEMPJET.toUShort();
    unsigned short closeTime_HEMPJETed = closeTime_HEMPJET.toUShort();
    unsigned short riseVoltage_HEMPJETed = riseVoltage_HEMPJET.toUShort();
    unsigned short holdVoltage_HEMPJETed = holdVoltage_HEMPJET.toUShort();
    unsigned short closeVoltage_HEMPJETed = closeVoltage_HEMPJET.toUShort();
    unsigned short VoltageSet_ad_HEMPJETed = VoltageSet_ad_HEMPJET.toUShort();
    // 计算CRC码
    unsigned char head_HEMPJET1 = 0x21; // 指令类型
    unsigned char head_HEMPJET2 = 0xE2; // 指令帧头
    unsigned char head_HEMPJET3 = 0x25; // 指令帧头
    unsigned char head_HEMPJET4 = 0x10; // 指令帧头
    unsigned char head_HEMPJET5 = 0x02; // 指令帧头
    unsigned char advanced_parameter_tabel[12] = {};
    advanced_parameter_tabel[0] = (unsigned char)(riseTime_HEMPJETed >> 8);
    advanced_parameter_tabel[1] = (unsigned char)(riseTime_HEMPJETed & 0x00FF);
    advanced_parameter_tabel[2] = (unsigned char)(closeTime_HEMPJETed >> 8);
    advanced_parameter_tabel[3] = (unsigned char)(closeTime_HEMPJETed & 0x00FF);
    advanced_parameter_tabel[4] = (unsigned char)(riseVoltage_HEMPJETed >> 8);
    advanced_parameter_tabel[5] = (unsigned char)(riseVoltage_HEMPJETed & 0x00FF);
    advanced_parameter_tabel[6] = (unsigned char)(holdVoltage_HEMPJETed >> 8);
    advanced_parameter_tabel[7] = (unsigned char)(holdVoltage_HEMPJETed & 0x00FF);
    advanced_parameter_tabel[8] = (unsigned char)(closeVoltage_HEMPJETed >> 8);
    advanced_parameter_tabel[9] = (unsigned char)(closeVoltage_HEMPJETed & 0x00FF);
    advanced_parameter_tabel[10] = (unsigned char)(VoltageSet_ad_HEMPJETed >> 8);
    advanced_parameter_tabel[11] = (unsigned char)(VoltageSet_ad_HEMPJETed & 0x00FF);
    // 计算CRC
    head_HEMPJET5 = 0x08;
    unsigned short CRC_advanced_table = head_HEMPJET1 + head_HEMPJET2 + head_HEMPJET3 + head_HEMPJET4 + head_HEMPJET5;
    for (int i = 0; i < 12; i++)
    {
        CRC_advanced_table += advanced_parameter_tabel[i];
    }

    commandResultGen(&resultTemp, "EB90001121E2251008", 12, advanced_parameter_tabel, CRC_advanced_table);
    result = resultTemp.toUpper();
    return result;
}

void CommandHempJetAdvanced::on_pushButton_clicked()
{
    // 获取值
    QString riseTime_HEMPJET = ui -> riseTime_HEMPJET_textEdit -> toPlainText();
    QString closeTime_HEMPJET = ui -> closeTime_HEMPJET_textEdit -> toPlainText();
    QString riseVoltage_HEMPJET = ui -> riseVoltage_HEMPJET_textEdit -> toPlainText();
    QString holdVoltage_HEMPJET = ui -> holdVoltage_HEMPJET_textEdit -> toPlainText();
    QString closeVoltage_HEMPJET = ui -> closeVoltage_HEMPJET_textEdit -> toPlainText();
    QString VoltageSet_ad_HEMPJET = ui -> VoltageSet_ad_HEMPJET_textEdit -> toPlainText();
    // 校验
    if (riseTime_HEMPJET == "" || closeTime_HEMPJET == "" || riseVoltage_HEMPJET == "" ||
            holdVoltage_HEMPJET == "" || closeVoltage_HEMPJET == "" || VoltageSet_ad_HEMPJET == "") {
        QMessageBox::about(NULL, "ERROR", "Null value appears");
        return;
    }
    QString result = hempJetAdvancedValues(riseTime_HEMPJET, closeTime_HEMPJET, riseVoltage_HEMPJET,
                                           holdVoltage_HEMPJET, closeVoltage_HEMPJET, VoltageSet_ad_HEMPJET);
    emit sendHempJetAdvancedCommand(result);
    this -> close();
}
