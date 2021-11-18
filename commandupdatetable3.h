#ifndef COMMANDUPDATETABLE3_H
#define COMMANDUPDATETABLE3_H

#include <QWidget>

namespace Ui {
class CommandUpdateTable3;
}

class CommandUpdateTable3 : public QWidget
{
    Q_OBJECT

public:
    explicit CommandUpdateTable3(QWidget *parent = nullptr);
    ~CommandUpdateTable3();

private:
    Ui::CommandUpdateTable3 *ui;
};

#endif // COMMANDUPDATETABLE3_H
