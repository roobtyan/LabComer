#ifndef COMMANDUPDATETABLE1_H
#define COMMANDUPDATETABLE1_H

#include <QWidget>

namespace Ui {
class CommandUpdateTable1;
}

class CommandUpdateTable1 : public QWidget
{
    Q_OBJECT

public:
    explicit CommandUpdateTable1(QWidget *parent = nullptr);
    ~CommandUpdateTable1();

    /**
     * @brief 更新查找表1的值
     */
    QString updateTable1Values(QString Table1Num, QString CurrentLimit, QString VoltageLimit, QString ControlledCurrent,
                            QString P1, QString P2, QString PressureSetting, QString MainDCDC, QString CathodeSelector,
                            QString FeedBranch, QString GasSelector, QString TimeDuration, QString usedTable2Num, QString usedTable3Num);

signals:
    /**
     * @brief 信号：发送命令到主界面
     */
    void sendUpdateTable1CommandToMainWindow(QString str);

private slots:
    void on_pushButton_clicked();

private:
    Ui::CommandUpdateTable1 *ui;
};

#endif // COMMANDUPDATETABLE1_H
