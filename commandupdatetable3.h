#ifndef COMMANDUPDATETABLE3_H
#define COMMANDUPDATETABLE3_H

#include <QWidget>

namespace Ui {
class CommandUpdateTable3;
}

class CommandUpdateTable3 : public QWidget
{
    Q_OBJECT

public:
    explicit CommandUpdateTable3(QWidget *parent = nullptr);
    ~CommandUpdateTable3();

    /**
     * @brief 计算更新查找表3的指令
     * @param Table3Num
     * @param IgniteP1
     * @param IgniteP2
     * @param OperationalP1
     * @param OperationalP2
     * @param IgnitionVoltage
     * @param IgnitionCurrent
     * @return
     */
    QString updateTable3Values(QString Table3Num, QString IgniteP1, QString IgniteP2, QString OperationalP1,
                               QString OperationalP2, QString IgnitionVoltage, QString IgnitionCurrent);

signals:
    /**
     * @brief 信号：发送指令到主界面
     * @param str
     */
    void sendUpdateTable3CommandToMainWindow(QString str);

private slots:
    void on_pushButton_clicked();

private:
    Ui::CommandUpdateTable3 *ui;
};

#endif // COMMANDUPDATETABLE3_H
