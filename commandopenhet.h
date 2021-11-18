#ifndef COMMAND_OPEN_HET_H
#define COMMAND_OPEN_HET_H

#include <QWidget>

namespace Ui {
class command_open_het;
}

class command_open_het : public QWidget
{
    Q_OBJECT

public:
    explicit command_open_het(QWidget *parent = nullptr);
    ~command_open_het();

private slots:

    void on_pushButton_clicked();

    /**
     * @brief 传递开机指令参数
     * @param Table1Num
     * @param CurrentLimit
     * @param VoltageLimit
     * @param ControlledCurrent
     * @param P1
     * @param P2
     * @param PressureSetting
     * @param MainDCDC
     * @param CathodeSelector
     * @param FeedBranch
     * @param GasSelector
     * @param TimeDuration
     * @param usedTable2Num
     * @param usedTable3Num
     */
    QString openHetValues(QString Table1Num, QString CurrentLimit, QString VoltageLimit, QString ControlledCurrent,
                       QString P1, QString P2, QString PressureSetting, QString MainDCDC, QString CathodeSelector,
                       QString FeedBranch, QString GasSelector, QString TimeDuration, QString usedTable2Num, QString usedTable3Num);
signals:

    void sendOpenHetCommandToMainWindow(QString command);

private:
    Ui::command_open_het *ui;
};

#endif // COMMAND_OPEN_HET_H
