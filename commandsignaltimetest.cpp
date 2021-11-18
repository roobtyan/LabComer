#include "commandsignaltimetest.h"
#include "ui_commandsignaltimetest.h"
#include <QMessageBox>

CommandSignalTimeTest::CommandSignalTimeTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CommandSignalTimeTest)
{
    ui->setupUi(this);
}

CommandSignalTimeTest::~CommandSignalTimeTest()
{
    delete ui;
}

void CommandSignalTimeTest::on_pushButton_clicked()
{
    // 获取值
    QString activation_state = ui -> activation_state_textEdit -> toPlainText();
    // 判定
    if (activation_state == "") {
        QMessageBox::about(NULL, "ERROR", "Null value appears");
        return;
    }
    // 计算
    QString result = signalTimeTestValues(activation_state);
    // 传送
    emit sendsignalTimeTestCommand(result);
    this -> close();
}

QString CommandSignalTimeTest::signalTimeTestValues(QString str)
{
    int activation_state = str.toInt();
    if (activation_state == 0) {
        return "EB90000621E225101000014809D7";
    } else {
        return "EB90000621E225101001014909D7";
    }
}
