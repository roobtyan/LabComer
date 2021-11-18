#ifndef COMMANDHEATING_H
#define COMMANDHEATING_H

#include <QWidget>

namespace Ui {
class CommandHeating;
}

class CommandHeating : public QWidget
{
    Q_OBJECT

public:
    explicit CommandHeating(QWidget *parent = nullptr);
    ~CommandHeating();

    /**
     * @brief 计算
     * @param heating_state
     * @param heating_zone1_temp
     * @param heating_zone2_temp
     * @param heating_voltage_set
     * @return
     */
    QString haetingValues(QString heating_state, QString heating_zone1_temp, QString heating_zone2_temp, QString heating_voltage_set);

signals:

    void sendHeatingCommandToMainWindow(QString str);

private slots:
    void on_pushButton_clicked();

private:
    Ui::CommandHeating *ui;
};

#endif // COMMANDHEATING_H
