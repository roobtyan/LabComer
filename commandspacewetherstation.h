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

private:
    Ui::CommandSpaceWetherStation *ui;
};

#endif // COMMANDSPACEWETHERSTATION_H
