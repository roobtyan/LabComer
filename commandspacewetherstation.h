#ifndef COMMANDSPACEWETHERSTATION_H
#define COMMANDSPACEWETHERSTATION_H

#include <QWidget>

namespace Ui {
class CommandSpaceWetherStation;
}

class CommandSpaceWetherStation : public QWidget
{
    Q_OBJECT

public:
    explicit CommandSpaceWetherStation(QWidget *parent = nullptr);
    ~CommandSpaceWetherStation();

    QString spaceWetherStateValues(QString space_weather_state, QString space_weather_voltage);

signals:
    void sendSpaceWetherState(QString str);

private slots:
    void on_pushButton_clicked();

private:
    Ui::CommandSpaceWetherStation *ui;
};

#endif // COMMANDSPACEWETHERSTATION_H
