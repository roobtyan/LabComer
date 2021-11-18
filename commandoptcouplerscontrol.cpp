#include "commandoptcouplerscontrol.h"
#include "ui_commandoptcouplerscontrol.h"
#include "QMessageBox"
#include "QDebug"
#include "QHelper.h"

CommandOptCouplersControl::CommandOptCouplersControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CommandOptCouplersControl)
{
    ui->setupUi(this);
}

CommandOptCouplersControl::~CommandOptCouplersControl()
{
    delete ui;
}

QString CommandOptCouplersControl::commandOptCouplersControlValues(QString opto_coupler_num, QString opto_coupler_state)
{
    // 转换
    unsigned char opto_coupler_numed = opto_coupler_num.toUInt(); // 1~24,  99 for close Variable Thrust Mode(VTM), 100 for open VTM
    unsigned char opto_coupler_stateed = opto_coupler_state.toUInt();
    // 其他参数
    unsigned char head_HEMPJET1 = 0x21; // 指令类型
    unsigned char head_HEMPJET2 = 0xE2; // 指令帧头
    unsigned char head_HEMPJET3 = 0x25; // 指令帧头
    unsigned char head_HEMPJET4 = 0x10; // 指令帧头
    unsigned char head_HEMPJET5 = 0x02; // 指令帧头
    unsigned char opto_coupler_command[2] = {};
    opto_coupler_command[0] = opto_coupler_numed;
    opto_coupler_command[1] = opto_coupler_stateed;

    head_HEMPJET5 = 0x18;
    unsigned short CRC_opto = head_HEMPJET1 + head_HEMPJET2 + head_HEMPJET3 + head_HEMPJET4 + head_HEMPJET5;
    for (int i = 0; i < 2; i++)
    {
        CRC_opto += opto_coupler_command[i];
    }

    QString resultTemp;
    QString result;
    commandResultGen(&resultTemp, "EB90000721E2251018", 2, opto_coupler_command, CRC_opto);
    result = resultTemp.toUpper();
    return  result;
}

void CommandOptCouplersControl::on_pushButton_clicked()
{
    // 获取值
    QString opto_coupler_num = ui -> opto_coupler_num_textEdit -> toPlainText();
    QString opto_coupler_state = ui -> opto_coupler_state_textEdit -> toPlainText();
    // 校验
    if (opto_coupler_num == "" || opto_coupler_state == "") {
        QMessageBox::about(NULL, "ERROR", "Null value appears");
        return;
    }
    // 计算
    QString result = commandOptCouplersControlValues(opto_coupler_num, opto_coupler_state);
//    if ("EB90000721E2251018510001A109D7" == result) qDebug() << result;
    emit sendOptCouplersControlCommand(result);
    this -> close();
}
