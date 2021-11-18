#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QSerialPort>
#include <QSerialPortInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    /**
     * @brief 设置com线程
     */
    void setCom1Thread();
    void setCom2Thread();


    /* 接收返回数据 */
    void com1GetMessage(QString message);
    void com2GetMessage(QString message);

    /**
     * @brief 回调数据
     * @param string
     */
    void windowMessage(QString string, int comId);

    /**
     * @brief 获得可用的串口名
     * @return
     */
    QStringList getAvailablePortNameList() const
    {
        QStringList portName;
        foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
        {
            portName << info.portName();
        }
        return portName;
    }

    /**
     * @brief 设置主界面中的串口名称
     */
    void setSerialComNames();

    /**
     * @brief 填充指令窗口1
     * @param str
     */
    void command1Fill(QString str);

    /**
     * @brief 填充指令窗口2
     * @param str
     */
    void command2Fill(QString str);

signals:
    /**
     * @brief 打开串口1
     * @param com
     * @param buad
     * @param check
     */
    void openPortCom1(QString com, QString buad, QString check, int comId);

    /**
     * @brief 向串口1发送指令
     * @param command
     */
    void sendCommandCom1(QString command);

    /**
     * @brief 关闭串口
     * @param com
     */
    void closePortCom1(int comId);

    /**
     * @brief 打开串口2
     * @param com
     * @param buad
     * @param check
     */
    void openPortCom2(QString com, QString buad, QString check, int comId);

    /**
     * @brief 向串口2发送指令
     * @param command
     */
    void sendCommandCom2(QString command);

    /**
     * @brief 关闭串口2
     * @param com
     */
    void closePortCom2(int comId);

    /**
     * @brief 发送遥测指令，每秒1次
     * @param second
     */
    void sendTelemetering(bool flag);

private slots:

    void on_com1_send_pushButton_2_clicked();

    void on_com1_send_pushButton_clicked();

    void on_com2_send_pushButton_2_clicked();

    void on_com2_send_pushButton_clicked();

    void on_action_1_triggered();

    void on_com1_command1_pushButton_clicked();

    void on_com1_command2_pushButton__clicked();

    void on_com1_command3_pushButton_clicked();

    void on_com1_command4_pushButton_clicked();

    void on_com1_command5_pushButton_clicked();

    void on_com1_command6_pushButton_clicked();

    void on_com1_command7_pushButton_clicked();

    void on_com1_command8_pushButton_clicked();

    void on_com1_command9_pushButton_clicked();

    void on_com1_command10_pushButton_clicked();

    void on_com1_command11_pushButton_clicked();

    void on_com1_command12_pushButton_clicked();

    void on_com1_command13_pushButton_clicked();

    void on_com1_command1_pushButton_3_clicked();


    void on_radioButton_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    // 两个com线程
    QThread com1Thread;
    QThread com2Thread;
    QThread autoSendCommandThread;
};
#endif // MAINWINDOW_H
