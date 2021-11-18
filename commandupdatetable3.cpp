#include "commandupdatetable3.h"
#include "ui_commandupdatetable3.h"
#include "QMessageBox"
#include "QHelper.h"
#include "QDebug"

CommandUpdateTable3::CommandUpdateTable3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CommandUpdateTable3)
{
    ui->setupUi(this);
}

CommandUpdateTable3::~CommandUpdateTable3()
{
    delete ui;
}

QString CommandUpdateTable3::updateTable3Values(QString Table3Num, QString IgniteP1, QString IgniteP2,
                                                QString OperationalP1, QString OperationalP2,
                                                QString IgnitionVoltage, QString IgnitionCurrent)
{
    QString resultTemp;
    // 先进行数据转换
    unsigned char Table3Numed = Table3Num.toUInt();
    unsigned short IgniteP1ed = IgniteP1.toUShort();
    unsigned short IgniteP2ed = IgniteP2.toUShort();
    unsigned short OperationalP1ed = OperationalP1.toUShort();
    unsigned short OperationalP2ed = OperationalP2.toUShort();		// frequency
    unsigned short IgnitionVoltageed = IgnitionVoltage.toUShort();  // Main DCDC high volatage
    unsigned short IgnitionCurrented = IgnitionCurrent.toUShort();
    qDebug() << IgnitionCurrented;
    // 指令头
    unsigned char head1 = 0x21; // 指令类型
    unsigned char head2 = 0xE2; // 指令帧头
    unsigned char head3 = 0x25; // 指令帧头
    unsigned char head4 = 0x00; // 指令值，根据不同指令要更换
//    unsigned char head5 = 0x02; // 指令值，根据不同指令要更换
    // 十六进制数组
    unsigned char lookupTable3[13] = {};
    lookupTable3[0] = Table3Numed;
    lookupTable3[1] = (unsigned char)(IgniteP1ed >> 8);
    lookupTable3[2] = (unsigned char)(IgniteP1ed & 0x00FF);
    lookupTable3[3] = (unsigned char)(IgniteP2ed >> 8);
    lookupTable3[4] = (unsigned char)(IgniteP2ed & 0x00FF);
    lookupTable3[5] = (unsigned char)(OperationalP1ed >> 8);
    lookupTable3[6] = (unsigned char)(OperationalP1ed & 0x00FF);
    lookupTable3[7] = (unsigned char)(OperationalP2ed >> 8);
    lookupTable3[8] = (unsigned char)(OperationalP2ed & 0x00FF);
    lookupTable3[9] = (unsigned char)(IgnitionVoltageed >> 8);
    lookupTable3[10] = (unsigned char)(IgnitionVoltageed & 0x00FF);
    lookupTable3[11] = (unsigned char)(IgnitionCurrented >> 8);
    lookupTable3[12] = (unsigned char)(IgnitionCurrented & 0x00FF);
    // 计算校验码
    unsigned short CRC;
    CRC = head1 + head2 + head3 + head4 + 0x12;
    for (int i = 0; i < 13; i++)
    {
        CRC += lookupTable3[i];
    }
    commandResultGen(&resultTemp, "EB90001221E2250012", 13, lookupTable3, CRC);
    QString result = resultTemp.toUpper();
    return result;
}

void CommandUpdateTable3::on_pushButton_clicked()
{
    // 先获取值
    QString Table3Num = ui -> Table3Num_textEdit -> toPlainText();
    QString IgniteP1 = ui -> IgniteP1_textEdit -> toPlainText();
    QString IgniteP2 = ui -> IgniteP2_textEdit -> toPlainText();
    QString OperationalP1 = ui -> OperationalP1_textEdit -> toPlainText();
    QString OperationalP2 = ui -> OperationalP2_textEdit -> toPlainText();
    QString IgnitionVoltage = ui -> IgnitionVoltage_textEdit -> toPlainText();
    QString IgnitionCurrent = ui -> IgnitionCurrent_textEdit -> toPlainText();
    // 校验值
    if (Table3Num == "" || IgniteP1 == "" || IgniteP2 == "" || OperationalP1 == "" || OperationalP2 == ""
            || IgnitionVoltage == "" || IgnitionCurrent == "") {
        QMessageBox::about(NULL, "ERROR", "Null value appears");
        return;
    }
    QString result = updateTable3Values(Table3Num, IgniteP1, IgniteP2, OperationalP1,
                                        OperationalP2, IgnitionVoltage, IgnitionCurrent);
    emit sendUpdateTable3CommandToMainWindow(result);
    this -> close();
}
