#ifndef COMMANDVALVESCONTROL_H
#define COMMANDVALVESCONTROL_H

#include <QWidget>

namespace Ui {
class CommandValvesControl;
}

class CommandValvesControl : public QWidget
{
    Q_OBJECT

public:
    explicit CommandValvesControl(QWidget *parent = nullptr);
    ~CommandValvesControl();

    /**
     * @brief 阀门控制指令
     * @param valve_num
     * @param valve_state
     * @param valve_P1
     * @param valve_P2
     * @return
     */
    QString valvesControlValues(QString valve_num, QString valve_state, QString valve_P1, QString valve_P2);

signals:
    void sendValvesControlCommand(QString str);

private slots:
    void on_pushButton_clicked();

private:
    Ui::CommandValvesControl *ui;
};

#endif // COMMANDVALVESCONTROL_H
