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

private:
    Ui::CommandValvesControl *ui;
};

#endif // COMMANDVALVESCONTROL_H
