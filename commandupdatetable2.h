#ifndef COMMANDUPDATETABLE2_H
#define COMMANDUPDATETABLE2_H

#include <QWidget>

namespace Ui {
class CommandUpdateTable2;
}

class CommandUpdateTable2 : public QWidget
{
    Q_OBJECT

public:
    explicit CommandUpdateTable2(QWidget *parent = nullptr);
    ~CommandUpdateTable2();

    /**
     * @brief 更新查找表2指令
     * @param Table2Num
     * @param RiseTime
     * @param CloseTime
     * @param RiseVoltage
     * @param HoldVoltage
     * @param CloseVoltage
     * @param PressureSelector
     * @param VoltageSet
     * @return
     */
    QString updateTable2Values(QString Table2Num, QString RiseTime, QString CloseTime, QString RiseVoltage,
                               QString HoldVoltage, QString CloseVoltage, QString PressureSelector, QString VoltageSet);
signals:
    void sendUpdateTable2CommandToMainWindow(QString str);

private slots:
    void on_pushButton_clicked();

private:
    Ui::CommandUpdateTable2 *ui;
};

#endif // COMMANDUPDATETABLE2_H
