#include "commandopenhet.h"
#include "ui_commandopenhet.h"
#include "QHelper.h"
#include <QMessageBox>
#include <QDebug>
#include <QChar>

command_open_het::command_open_het(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::command_open_het)
{
    ui->setupUi(this);
    this->setMaximumSize(640, 480);
    this->setMinimumSize(640,40);
}

command_open_het::~command_open_het()
{
    delete ui;
}

void command_open_het::on_pushButton_clicked()
{
    // 获取开机指令相关参数
    QString Table1Num = this->ui->openHet_Table1Num_textEdit->toPlainText();
    QString CurrentLimit = this->ui->openHet_CurrentLimit_textEdit->toPlainText();
    QString VoltageLimit = this->ui->openHet_VoltageLimit_textEdit->toPlainText();
    QString ControlledCurrent = this->ui->openHet_ControlledCurrent_textEdit->toPlainText();
    QString P1 = this->ui->openHet_P1_textEdit->toPlainText();
    QString P2 = this->ui->openHet_P2_textEdit->toPlainText();
    QString PressureSetting = this->ui->openHet_PressureSetting_textEdit->toPlainText();
    QString MainDCDC = this->ui->openHet_MainDCDC_textEdit->toPlainText();
    QString CathodeSelector = this->ui->openHet_CathodeSelector_textEdit->toPlainText();
    QString FeedBranch = this->ui->openHet_FeedBranch_textEdit->toPlainText();
    QString GasSelector = this->ui->openHet_GasSelector_textEdit->toPlainText();
    QString TimeDuration = this->ui->openHet_TimeDuration_textEdit->toPlainText();
    QString usedTable2Num = this->ui->openHet_usedTable2Num_textEdit->toPlainText();
    QString usedTable3Num = this->ui->openHet_usedTable3Num_textEdit->toPlainText();
    // 空值判断
    if (Table1Num == "" || CurrentLimit == "" || VoltageLimit == "" || ControlledCurrent == "" || P1 == "" || P2 == ""
            || PressureSetting == "" || MainDCDC == "" || CathodeSelector == "" || FeedBranch == "" || GasSelector == ""
            || TimeDuration == "" || usedTable2Num == "" || usedTable3Num == "") {
        QMessageBox::about(NULL, "ERROR", "Null value appears");
        return;
    }
    // 校验通过，发送到计算命令
    QString result = openHetValues(Table1Num, CurrentLimit, VoltageLimit, ControlledCurrent, P1, P2, PressureSetting, MainDCDC, CathodeSelector,
                  FeedBranch, GasSelector, TimeDuration, usedTable2Num, usedTable3Num);
    // 发送到槽函数
    emit sendOpenHetCommandToMainWindow(result);
    this -> close();
}

QString command_open_het::openHetValues(QString Table1Num, QString CurrentLimit, QString VoltageLimit, QString ControlledCurrent, QString P1, QString P2, QString PressureSetting, QString MainDCDC, QString CathodeSelector, QString FeedBranch, QString GasSelector, QString TimeDuration, QString usedTable2Num, QString usedTable3Num)
{
    QString resultTemp;
    // 先进行类型转换
    unsigned char Table1Numed = Table1Num.toUInt();
    unsigned short CurrentLimited = CurrentLimit.toUShort();
    unsigned short VoltageLimited = VoltageLimit.toUShort();
    unsigned short ControlledCurrented = ControlledCurrent.toUShort();
    unsigned short P1ed = P1.toUShort();
    unsigned char P2ed = P2.toUInt();
    unsigned short PressureSettinged = PressureSetting.toUShort();
    unsigned char MainDCDCed = MainDCDC.toUInt();
    unsigned char CathodeSelectored = CathodeSelector.toUInt();
    unsigned char FeedBranched = FeedBranch.toUInt();
    unsigned char GasSelectored = GasSelector.toUInt();
    unsigned long TimeDurationed = TimeDuration.toULong();
    unsigned char usedTable2Numed = usedTable2Num.toUInt();
    unsigned char usedTable3Numed = usedTable3Num.toUInt();

    /* 从星务计算机发到控制卡指令生成脚本 */
    unsigned char head1 = 0x21; // 指令类型
    unsigned char head2 = 0xE2; // 指令帧头
    unsigned char head3 = 0x25; // 指令帧头
    unsigned char head4 = 0x00; // 指令值，根据不同指令要更换
    unsigned char head5 = 0x02; // 指令值，根据不同指令要更换
    unsigned char lookupTable1[22] = {0x00, 0x17, 0x70, 0x0F, 0xA0, 0x4E, 0x20, 0x09, 0xC4, 0x37, 0x07, 0xD0, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00};

    //设置参数转16进制单字节数据
    lookupTable1[0] = Table1Numed;
    lookupTable1[1] = (unsigned char)(CurrentLimited >> 8);
    lookupTable1[2] = (unsigned char)(CurrentLimited & 0x00FF);
    lookupTable1[3] = (unsigned char)(VoltageLimited >> 8);
    lookupTable1[4] = (unsigned char)(VoltageLimited & 0x00FF);
    lookupTable1[5] = (unsigned char)(ControlledCurrented >> 8);
    lookupTable1[6] = (unsigned char)(ControlledCurrented & 0x00FF);
    lookupTable1[7] = (unsigned char)(P1ed >> 8);
    lookupTable1[8] = (unsigned char)(P1ed & 0x00FF);
    lookupTable1[9] = P2ed;
    lookupTable1[10] = (unsigned char)(PressureSettinged >> 8);
    lookupTable1[11] = (unsigned char)(PressureSettinged & 0x00FF);
    lookupTable1[12] = MainDCDCed;
    lookupTable1[13] = CathodeSelectored;
    lookupTable1[14] = FeedBranched;
    lookupTable1[15] = GasSelectored;
    lookupTable1[16] = (unsigned char)(TimeDurationed >> 24);
    lookupTable1[17] = (unsigned char)((TimeDurationed & 0x00FF0000) >> 16);
    lookupTable1[18] = (unsigned char)((TimeDurationed & 0x0000FF00) >> 8);
    lookupTable1[19] = (unsigned char)(TimeDurationed & 0x000000FF);
    lookupTable1[20] = usedTable2Numed;
    lookupTable1[21] = usedTable3Numed;

    // 计算2字节校验码
    unsigned short CRC = head1 + head2 + head3 + head4 + head5;
    for (int i = 0; i < 22; i++)
    {
        CRC += lookupTable1[i];
    }
    // 最终生成的OBC命令
//    resultTemp.append("EB90001B21E2250002");
//    for (int i = 0; i < 22; i++)
//    {
//        QString qUnicode = QString("%1").arg(lookupTable1[i], 2, 16);
//        resultTemp.append(qUnicode);
//    }
//    // CRC保存
//    resultTemp.append(QString("%1").arg(CRC, 4, 16));
//    resultTemp.append("09D7");
//    // 转成大写并空位补0
//    resultTemp.replace(" ", "0");
    commandResultGen(&resultTemp, "EB90001B21E2250002", 22, lookupTable1, CRC);
    QString result = resultTemp.toUpper();
    if ("EB90001B21E2250002139999AFC859991F400707D0010101000002BF200013070C09D7" == result) qDebug() << "1OK";
    return result;
}
