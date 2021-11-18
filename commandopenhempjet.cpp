#include "commandopenhempjet.h"
#include "ui_commandopenhempjet.h"
#include "QHelper.h"
#include <QMessageBox>
#include <QDebug>

CommandOpenHempjet::CommandOpenHempjet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CommandOpenHempjet)
{
    ui->setupUi(this);
}

CommandOpenHempjet::~CommandOpenHempjet()
{
    delete ui;
}

QString CommandOpenHempjet::openHempJet(QString VoltageSet_HEMPJET, QString P1_HEMPJET, QString P2_HEMPJET,
                                        QString Pressure_HEMPJET, QString TimeDuration_HEMPJET)
{
    // 转换
    unsigned short VoltageSet_HEMPJETed = VoltageSet_HEMPJET.toUShort();
    unsigned short P1_HEMPJETed = P1_HEMPJET.toUShort();
    unsigned char P2_HEMPJETed = P2_HEMPJET.toUInt();
    unsigned short Pressure_HEMPJETed = Pressure_HEMPJET.toUShort();
    unsigned long TimeDuration_HEMPJETed = TimeDuration_HEMPJET.toULong();
    // 指令
    unsigned char head_HEMPJET1 = 0x21; // 指令类型
    unsigned char head_HEMPJET2 = 0xE2; // 指令帧头
    unsigned char head_HEMPJET3 = 0x25; // 指令帧头
    unsigned char head_HEMPJET4 = 0x10; // 指令帧头
    unsigned char head_HEMPJET5 = 0x02; // 指令帧头
    unsigned char open_HMEPJET[11] = {};
    // 十六进制数组
    open_HMEPJET[0] = (unsigned char)(VoltageSet_HEMPJETed >> 8);
    open_HMEPJET[1] = (unsigned char)(VoltageSet_HEMPJETed & 0x00FF);
    open_HMEPJET[2] = (unsigned char)(P1_HEMPJETed >> 8);
    open_HMEPJET[3] = (unsigned char)(P1_HEMPJETed & 0x00FF);
    open_HMEPJET[4] = P2_HEMPJETed;
    open_HMEPJET[5] = (unsigned char)(Pressure_HEMPJETed >> 8);
    open_HMEPJET[6] = (unsigned char)(Pressure_HEMPJETed & 0x00FF);
    open_HMEPJET[7] = (unsigned char)(TimeDuration_HEMPJETed >> 24);
    open_HMEPJET[8] = (unsigned char)((TimeDuration_HEMPJETed & 0x00FF0000) >> 16);
    open_HMEPJET[9] = (unsigned char)((TimeDuration_HEMPJETed & 0x0000FF00) >> 8);
    open_HMEPJET[10] = (unsigned char)(TimeDuration_HEMPJETed & 0x000000FF);
    // 生成CRC
    unsigned short CRC_HEMPJET_OPEN = head_HEMPJET1 + head_HEMPJET2 + head_HEMPJET3 + head_HEMPJET4 + head_HEMPJET5;
    for (int i = 0; i < 11; i++)
    {
        CRC_HEMPJET_OPEN += open_HMEPJET[i];
    }
    QString resultTemp;
    commandResultGen(&resultTemp, "EB90001021E2251002", 11, open_HMEPJET, CRC_HEMPJET_OPEN);
    QString result = resultTemp.toUpper();
    return result;
}

void CommandOpenHempjet::on_pushButton_clicked()
{
    // 获取数据
    QString VoltageSet_HEMPJET = ui -> VoltageSet_HEMPJET_textEdit -> toPlainText();
    QString P1_HEMPJET = ui -> P1_HEMPJET_textEdit -> toPlainText();
    QString P2_HEMPJET = ui -> P2_HEMPJET_textEdit -> toPlainText();
    QString Pressure_HEMPJET = ui -> Pressure_HEMPJET_textEdit -> toPlainText();
    QString TimeDuration_HEMPJET = ui -> TimeDuration_HEMPJET_textEdit -> toPlainText();
    // 校验数据
    if (VoltageSet_HEMPJET == "" || P1_HEMPJET == "" || P2_HEMPJET == ""
            || Pressure_HEMPJET == "" || TimeDuration_HEMPJET == "") {
        QMessageBox::about(NULL, "ERROR", "Null value appears");
        return;
    }
    // 调用
    QString result = openHempJet(VoltageSet_HEMPJET, P1_HEMPJET, P2_HEMPJET,
                                 Pressure_HEMPJET, TimeDuration_HEMPJET);
    emit sendOpenHempJetCommandToMainWindow(result);
    this -> close();
}
