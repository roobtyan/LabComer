#ifndef COMMANDOPTCOUPLERSCONTROL_H
#define COMMANDOPTCOUPLERSCONTROL_H

#include <QWidget>

namespace Ui {
class CommandOptCouplersControl;
}

class CommandOptCouplersControl : public QWidget
{
    Q_OBJECT

public:
    explicit CommandOptCouplersControl(QWidget *parent = nullptr);
    ~CommandOptCouplersControl();

private:
    Ui::CommandOptCouplersControl *ui;
};

#endif // COMMANDOPTCOUPLERSCONTROL_H
