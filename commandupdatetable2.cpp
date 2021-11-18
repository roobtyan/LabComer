#include "commandupdatetable2.h"
#include "ui_commandupdatetable2.h"
#include <QMessageBox>
#include <QDebug>
#include <QHelper.h>

CommandUpdateTable2::CommandUpdateTable2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CommandUpdateTable2)
{
    ui->setupUi(this);
}

CommandUpdateTable2::~CommandUpdateTable2()
{
    delete ui;
}

QString CommandUpdateTable2::updateTable2Values(QString Table2Num, QString RiseTime, QString CloseTime,
                                                QString RiseVoltage, QString HoldVoltage, QString CloseVoltage,
                                                QString PressureSelector, QString VoltageSet)
{
    QString resultTemp;
    // 格式转换
    unsigned char Table2Numed = Table2Num.toUInt();
    unsigned short RiseTimeed = RiseTime.toUShort();
    unsigned short CloseTimeed = CloseTime.toUShort();
    unsigned short RiseVoltageed = RiseVoltage.toUShort();
    unsigned short HoldVoltageed = HoldVoltage.toUShort();
    unsigned short CloseVoltageed = CloseVoltage.toUShort();
    unsigned char PressureSelectored = PressureSelector.toUInt(); // 0-1
    unsigned short VoltageSeted = VoltageSet.toUShort();
    /* 从星务计算机发到控制卡指令生成脚本 */
    unsigned char head1 = 0x21; // 指令类型
    unsigned char head2 = 0xE2; // 指令帧头
    unsigned char head3 = 0x25; // 指令帧头
    unsigned char head4 = 0x00; // 指令值，根据不同指令要更换
//    unsigned char head5 = 0x02; // 指令值，根据不同指令要更换
    // 写十六进制表
    unsigned char lookupTable2[14] = {};
    lookupTable2[0] = Table2Numed;
    lookupTable2[1] = (unsigned char)(RiseTimeed >> 8);
    lookupTable2[2] = (unsigned char)(RiseTimeed & 0x00FF);
    lookupTable2[3] = (unsigned char)(CloseTimeed >> 8);
    lookupTable2[4] = (unsigned char)(CloseTimeed & 0x00FF);
    lookupTable2[5] = (unsigned char)(RiseVoltageed >> 8);
    lookupTable2[6] = (unsigned char)(RiseVoltageed & 0x00FF);
    lookupTable2[7] = (unsigned char)(HoldVoltageed >> 8);
    lookupTable2[8] = (unsigned char)(HoldVoltageed & 0x00FF);
    lookupTable2[9] = (unsigned char)(CloseVoltageed >> 8);
    lookupTable2[10] = (unsigned char)(CloseVoltageed & 0x00FF);
    lookupTable2[11] = PressureSelectored;
    lookupTable2[12] = (unsigned char)(VoltageSeted >> 8);
    lookupTable2[13] = (unsigned char)(VoltageSeted & 0x00FF);
    // 开始计算
    unsigned short CRC;
    CRC = head1 + head2 + head3 + head4 + 0x11;
    for (int i = 0; i < 14; i++)
    {
        CRC += lookupTable2[i];
    }
    commandResultGen(&resultTemp, "EB90001321E2250011", 14, lookupTable2, CRC);
    QString result = resultTemp.toUpper();
    return result;
}

void CommandUpdateTable2::on_pushButton_clicked()
{
    // 获取数据
    QString Table2Num = ui -> Table2Num_textEdit -> toPlainText();
    QString RiseTime = ui -> RiseTime_textEdit -> toPlainText();
    QString CloseTime = ui -> CloseTime_textEdit -> toPlainText();
    QString RiseVoltage = ui -> RiseVoltage_textEdit -> toPlainText();
    QString HoldVoltage = ui -> HoldVoltage_textEdit -> toPlainText();
    QString CloseVoltage = ui -> CloseVoltage_textEdit -> toPlainText();
    QString PressureSelector = ui -> PressureSelector_textEdit -> toPlainText();
    QString VoltageSet = ui -> VoltageSet_textEdit -> toPlainText();
    // 校验数据
    if (Table2Num == "" || RiseTime == "" || CloseTime == "" || RiseVoltage == "" || HoldVoltage == "" ||
            CloseVoltage == "" || PressureSelector == "" || VoltageSet == ""){
        QMessageBox::about(NULL, "ERROR", "Null value appears");
        return;
    }
    // 计算指令
    QString command = updateTable2Values(Table2Num, RiseTime, CloseTime, RiseVoltage,
                                         HoldVoltage, CloseVoltage, PressureSelector, VoltageSet);
    emit sendUpdateTable2CommandToMainWindow(command);
    this -> close();
}
