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

private:
    Ui::CommandHeating *ui;
};

#endif // COMMANDHEATING_H
