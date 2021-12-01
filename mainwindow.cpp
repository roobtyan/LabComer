#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "serialworker.h"
#include "thrustercontrol.h"
#include "commandopenhet.h"
#include "commandupdatetable1.h"
#include "commandupdatetable2.h"
#include "commandupdatetable3.h"
#include "commandopenhempjet.h"
#include "commandhempjetadvanced.h"
#include "commandsignaltimetest.h"
#include "commandspacewetherstation.h"
#include "commandheating.h"
#include "commandoptcouplerscontrol.h"
#include "commandvalvescontrol.h"
#include "timedtask.h"
#include <QStandardItemModel>
#include <QMetaType>
#include <QTimer>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 调整表格自适应
    ui -> Remote_tableWidget -> horizontalHeader() -> setSectionResizeMode(QHeaderView::Stretch);
    // 注册自定义类型
    qRegisterMetaType<QList<RemoteCommand>>("QList<RemoteCommand>");
    setCom1Thread();
    setCom2Thread();
    setSerialComNames();
}

MainWindow::~MainWindow()
{
    com1Thread.quit();
    com1Thread.wait();
    com2Thread.quit();
    com2Thread.wait();
    autoSendCommandThread.quit();
    autoSendCommandThread.wait();
    delete ui;
}

/*多线程设置------------------------------------------------*/
void MainWindow::setCom1Thread()
{
    SerialWorker *serialWorkerCom1 = new SerialWorker();
    serialWorkerCom1 -> moveToThread(&com1Thread);
    connect(&com1Thread, &QThread::finished,
                serialWorkerCom1, &QObject::deleteLater);       // 线程结束，自动删除对象
    connect(&com1Thread, &QThread::started,
            serialWorkerCom1, &SerialWorker::initSerialPort);   // 当线程开启时，初始化串口
    connect(this, &MainWindow::openPortCom1,
            serialWorkerCom1, &SerialWorker::openPort);         // open串口
    connect(serialWorkerCom1, &SerialWorker::openPortSuccess,
            this, &MainWindow::windowMessage);                  // open串口状态
    connect(serialWorkerCom1, &SerialWorker::readyRead,
            this, &MainWindow::com1GetMessage);                 // 读取数据
    connect(serialWorkerCom1, &SerialWorker::readyReadTable,
            this, &MainWindow::com1GetTableInfo);               // 读取数据到表格中
    connect(this, &MainWindow::sendCommandCom1,
            serialWorkerCom1, &SerialWorker::doDataSendWork);   // 发送数据
    connect(this, &MainWindow::closePortCom1,
            serialWorkerCom1, &SerialWorker::closePort);        // close串口
    connect(serialWorkerCom1, &SerialWorker::closePortStatus,
            this, &MainWindow::windowMessage);                  // close串口状态

    // 自动发送的线程
    TimedTask *timedTask = new TimedTask();
    QTimer *timer = new QTimer(this);
    timedTask -> moveToThread(&autoSendCommandThread);
    connect(&autoSendCommandThread, &QThread::finished,
                timedTask, &QObject::deleteLater);              // 线程结束，自动删除对象
    connect(timer, &QTimer::timeout,
            timedTask, &TimedTask::autoSendTelCommandTask);     // 定时任务
    connect(this, &MainWindow::sendTelemetering,
            timedTask, &TimedTask::openAutoSendTelCommandTask); // 设置自动发送标志
    connect(timedTask, &TimedTask::sendCommand,
            serialWorkerCom1, &SerialWorker::doDataSendWork);   // 命令发送

    // 线程启动
    timer -> start(1000);
    com1Thread.start();
    autoSendCommandThread.start();
}

void MainWindow::setCom2Thread()
{
    SerialWorker *serialWorkerCom2 = new SerialWorker();
    serialWorkerCom2 -> moveToThread(&com2Thread);
    connect(&com1Thread, &QThread::finished,
                serialWorkerCom2, &QObject::deleteLater);       // 线程结束，自动删除对象
    connect(&com1Thread, &QThread::started,
            serialWorkerCom2, &SerialWorker::initSerialPort);   // 当线程开启时，初始化串口
    connect(this, &MainWindow::openPortCom2,
            serialWorkerCom2, &SerialWorker::openPort);         // open串口
    connect(serialWorkerCom2, &SerialWorker::openPortSuccess,
            this, &MainWindow::windowMessage);                  // open串口状态
    connect(serialWorkerCom2, &SerialWorker::readyRead,
            this, &MainWindow::com2GetMessage);                 // 读取数据
    connect(this, &MainWindow::sendCommandCom2,
            serialWorkerCom2, &SerialWorker::doDataSendWork);   // 发送数据
    connect(this, &MainWindow::closePortCom2,
            serialWorkerCom2, &SerialWorker::closePort);        // close串口
    connect(serialWorkerCom2, &SerialWorker::closePortStatus,
            this, &MainWindow::windowMessage);                  // close串口状态
    com2Thread.start();
}

/*反馈函数区-----------------------------------------------------*/

/* 接收com的返回数据 */
void MainWindow::com1GetMessage(QString message) {
    ui -> com1_return_textBrowser -> append(message);
}

void MainWindow::com2GetMessage(QString message) {
    ui -> com2_return_textBrowser -> append(message);
}

void MainWindow::com1GetTableInfo(QList<RemoteCommand> remoteList) {
    foreach(RemoteCommand remote, remoteList) {
        int rowCount = ui -> Remote_tableWidget -> rowCount();
        ui -> Remote_tableWidget -> insertRow(rowCount);//增加一行
        ui -> Remote_tableWidget -> setItem(rowCount, 0, new QTableWidgetItem(remote.getRemoteNumber()));
        ui -> Remote_tableWidget -> setItem(rowCount, 1, new QTableWidgetItem(remote.getRemoteName()));
        ui -> Remote_tableWidget -> setItem(rowCount, 2, new QTableWidgetItem(remote.getRemoteValue()));
        ui -> Remote_tableWidget -> setItem(rowCount, 3, new QTableWidgetItem(remote.getRemoteSource()));
//        ui -> Remote_tableWidget ->scrollToBottom();
    }
}

/**
 * @brief 弹窗展示信息
 * @param string
 */
void MainWindow::windowMessage(QString string, int comId) {
    QString button1Text = ui -> com1_send_pushButton_2 -> text();
    QString button2Text = ui -> com2_send_pushButton_2 -> text();
    ui -> com_status_label -> clear();
    ui -> com_status_label -> setText(string);
    if (string.contains("success")) {
        // 如果open成功
        if (comId == 1 && button1Text == "open") {
            ui -> com1_send_pushButton_2 -> setText("close");
        } else if (comId == 2 && button2Text == "open") {
            ui -> com2_send_pushButton_2 -> setText("close");
        }
        // 如果close成功
        if (comId == 1 && button1Text == "close") {
            ui -> com1_send_pushButton_2 -> setText("open");
        } else if (comId == 2 && button2Text == "close") {
            ui -> com2_send_pushButton_2 -> setText("open");
        }
    }
}

/*其他函数区-----------------------------------------------------*/
void MainWindow::setSerialComNames() {
    QStringList comList = getAvailablePortNameList();
    ui -> com1_com_comboBox -> addItems(comList);
    ui -> com2_com_comboBox -> addItems(comList);
}

void MainWindow::command1Fill(QString str) {
    this -> ui -> com1_command_textEdit -> setText(str);
}

void MainWindow::command2Fill(QString str) {
    this -> ui -> com2_send_textEdit -> setText(str);
}

/*事件功能函数区-------------------------------------------------*/
void MainWindow::on_com1_send_pushButton_2_clicked() {
    QString com = ui ->com1_com_comboBox -> currentText();
    QString buttonText = ui -> com1_send_pushButton_2 -> text();
    if (buttonText == "open") {
        // 获取必要的数据
        QString check = ui -> com1_check_comboBox -> currentText();
        QString buad = ui -> com1_buad_comboBox -> currentText();
        // 设置标志位 1表示串口界面1
        // 发送到open串口的槽中
        emit openPortCom1(com, buad, check, 1);
    } else {
        emit closePortCom1(1);
    }

}

void MainWindow::on_com1_send_pushButton_clicked() {
    QString command = ui -> com1_command_textEdit ->toPlainText();
    if (command != "") {
        emit sendCommandCom1(command);
    }
}

void MainWindow::on_com2_send_pushButton_2_clicked() {
    QString com = ui ->com2_com_comboBox -> currentText();
    QString buttonText = ui -> com2_send_pushButton_2 -> text();
    if (buttonText == "open") {
        // 获取必要的数据
        QString check = ui -> com2_check_comboBox -> currentText();
        QString buad = ui -> com2_buad_comboBox -> currentText();
        // 设置标志位 1表示串口界面1
        // 发送到open串口的槽中
        emit openPortCom2(com, buad, check, 2);
    } else {
        emit closePortCom2(2);
    }
}

void MainWindow::on_com2_send_pushButton_clicked() {
    QString command = ui -> com2_send_textEdit ->toPlainText();
    if (command != "") {
        emit sendCommandCom2(command);
    }
}

void MainWindow::on_action_1_triggered() {
    ThrusterControl *thruster = new ThrusterControl();
    thruster->show();
}

/*命令窗口函数区------------------------------------------------------*/
void MainWindow::on_com1_command1_pushButton_clicked()
{
    // 类名忘记大写了，暂时先用着
    command_open_het *commandOpenHet = new command_open_het();
    // 绑定信号与槽函数
    connect(commandOpenHet, &command_open_het::sendOpenHetCommandToMainWindow,
            this, &MainWindow::command1Fill);
    commandOpenHet->setWindowTitle("Command:open het");
    commandOpenHet->show();
}

void MainWindow::on_com1_command2_pushButton__clicked()
{
    CommandUpdateTable1 *updateTable1 = new CommandUpdateTable1();
    connect(updateTable1, &CommandUpdateTable1::sendUpdateTable1CommandToMainWindow,
            this, &MainWindow::command1Fill);
    updateTable1 -> setWindowTitle("Command: update lookup table1");
    updateTable1 -> show();
}

void MainWindow::on_com1_command3_pushButton_clicked()
{
    CommandUpdateTable2 *updateTable2 = new CommandUpdateTable2();
    connect(updateTable2, &CommandUpdateTable2::sendUpdateTable2CommandToMainWindow,
            this, &MainWindow::command1Fill);
    updateTable2 -> setWindowTitle("Command: update lookup table2");
    updateTable2 -> show();
}

void MainWindow::on_com1_command4_pushButton_clicked()
{
    CommandUpdateTable3 *updateTable3 = new CommandUpdateTable3();
    connect(updateTable3, &CommandUpdateTable3::sendUpdateTable3CommandToMainWindow,
            this, &MainWindow::command1Fill);
    updateTable3 -> setWindowTitle("Command: update lookup table3");
    updateTable3 -> show();
}

void MainWindow::on_com1_command5_pushButton_clicked()
{
    CommandOpenHempjet *openHempJet = new CommandOpenHempjet();
    connect(openHempJet, &CommandOpenHempjet::sendOpenHempJetCommandToMainWindow,
            this, &MainWindow::command1Fill);
    openHempJet -> setWindowTitle("Command: openHempJet");
    openHempJet -> show();
}

void MainWindow::on_com1_command6_pushButton_clicked()
{
    // 关闭HempJet指令，为固定内容
    QString closeCommand = "EB90000521E2251004013C09D7";
    command1Fill(closeCommand);
}

void MainWindow::on_com1_command7_pushButton_clicked()
{
    CommandHempJetAdvanced *hempJetAdvanced = new CommandHempJetAdvanced();
    connect(hempJetAdvanced, &CommandHempJetAdvanced::sendHempJetAdvancedCommand,
            this, &MainWindow::command1Fill);
    hempJetAdvanced -> setWindowTitle("Command: HempJetAdvancedCommand");
    hempJetAdvanced ->show();
}

void MainWindow::on_com1_command8_pushButton_clicked()
{
    CommandSignalTimeTest *signalTime = new CommandSignalTimeTest();
    connect(signalTime, &CommandSignalTimeTest::sendsignalTimeTestCommand,
            this, &MainWindow::command1Fill);
    signalTime -> setWindowTitle("Command: signal time test");
    signalTime -> show();
}

void MainWindow::on_com1_command9_pushButton_clicked()
{
    CommandSpaceWetherStation *spaceWetherStation = new CommandSpaceWetherStation;
    connect(spaceWetherStation, &CommandSpaceWetherStation::sendSpaceWetherState,
            this, &MainWindow::command1Fill);
    spaceWetherStation -> setWindowTitle("Command: space wether station");
    spaceWetherStation -> show();
}

void MainWindow::on_com1_command10_pushButton_clicked()
{
    CommandHeating *heating = new CommandHeating();
    connect(heating, &CommandHeating::sendHeatingCommandToMainWindow,
            this, &MainWindow::command1Fill);
    heating -> setWindowTitle("Command: heating");
    heating -> show();
}

void MainWindow::on_com1_command11_pushButton_clicked()
{
    CommandOptCouplersControl *optCouplers = new CommandOptCouplersControl();
    connect(optCouplers, &CommandOptCouplersControl::sendOptCouplersControlCommand,
            this, &MainWindow::command1Fill);
    optCouplers -> setWindowTitle("Command: Opt Couplers Control");
    optCouplers -> show();
}

void MainWindow::on_com1_command12_pushButton_clicked()
{
    CommandValvesControl *valvesControl = new CommandValvesControl();
    connect(valvesControl, &CommandValvesControl::sendValvesControlCommand,
            this, &MainWindow::command1Fill);
    valvesControl -> setWindowTitle("Command: Valves control");
    valvesControl -> show();
}

void MainWindow::on_com1_command13_pushButton_clicked()
{
    // 关闭推力器指令，固定
    QString result = "EB90000521E2250004012C09D7";
    command1Fill(result);
}

void MainWindow::on_com1_command1_pushButton_3_clicked()
{
    // 手动发送遥测指令
    QString result = "EB9000021100001109D7";
    command1Fill(result);
}


void MainWindow::on_radioButton_toggled(bool checked)
{
    // 当触发并选中时开启自动发送遥测信号模式
    if (checked) {
        // 每秒发送1次遥测信号, 不能在主窗口发送，需要去进程中
        emit sendTelemetering(1);
    } else {
        emit sendTelemetering(0);
    }
}
