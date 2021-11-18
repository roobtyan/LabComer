#include "commandvalvescontrol.h"
#include "ui_commandvalvescontrol.h"
#include "QMessageBox"
#include "QDebug"
#include "QHelper.h"

CommandValvesControl::CommandValvesControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CommandValvesControl)
{
    ui->setupUi(this);
}

CommandValvesControl::~CommandValvesControl()
{
    delete ui;
}

QString CommandValvesControl::valvesControlValues(QString valve_num, QString valve_state, QString valve_P1, QString valve_P2)
{
    // 转换
    unsigned char valve_numed = valve_num.toUInt();
    unsigned char valve_stateed = valve_state.toUInt();
    unsigned short valve_P1ed = valve_P1.toUShort();
    unsigned char valve_P2ed = valve_P2.toUShort(); // frequency
    // 参数
    unsigned char head_HEMPJET1 = 0x21; // 指令类型
    unsigned char head_HEMPJET2 = 0xE2; // 指令帧头
    unsigned char head_HEMPJET3 = 0x25; // 指令帧头
    unsigned char head_HEMPJET4 = 0x10; // 指令帧头
    unsigned char head_HEMPJET5 = 0x02; // 指令帧头
    unsigned char valve_manual_ctrl_command[5] = {};
    valve_manual_ctrl_command[0] = valve_numed;
    valve_manual_ctrl_command[1] = valve_stateed;
    valve_manual_ctrl_command[2] = (unsigned char)(valve_P1ed >> 8);
    valve_manual_ctrl_command[3] = (valve_P1ed & 0x00FF);
    valve_manual_ctrl_command[4] = valve_P2ed;

    head_HEMPJET5 = 0x20;
    unsigned short CRC_valve = head_HEMPJET1 + head_HEMPJET2 + head_HEMPJET3 + head_HEMPJET4 + head_HEMPJET5;
    for (int i = 0; i < 5; i++)
    {
        CRC_valve += valve_manual_ctrl_command[i];
    }

    QString resultTemp;
    QString result;
    commandResultGen(&resultTemp, "EB90000A21E2251020", 5, valve_manual_ctrl_command, CRC_valve);
    result = resultTemp.toUpper();
    return result;
}

void CommandValvesControl::on_pushButton_clicked()
{
    // 获取参数
    QString valve_num = ui -> valve_num_textEdit -> toPlainText();
    QString valve_state = ui -> valve_state_textEdit -> toPlainText();
    QString valve_P1 = ui -> valve_P1_textEdit -> toPlainText();
    QString valve_P2 = ui -> valve_P2_textEdit -> toPlainText();
    // 校验
    if (valve_num == "" || valve_state == "" || valve_P1 == "" || valve_P2 == "") {
        QMessageBox::about(NULL, "ERROR", "Null value appears");
        return;
    }
    // 计算
    QString result = valvesControlValues(valve_num, valve_state, valve_P1, valve_P2);
        if ("EB90000A21E225102001011F400701C009D7" == result) qDebug() << result;
    emit sendValvesControlCommand(result);
    this -> close();
}
