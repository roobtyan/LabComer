#ifndef COMMANDUPDATETABLE1_H
#define COMMANDUPDATETABLE1_H

#include <QWidget>

namespace Ui {
class CommandUpdateTable1;
}

class CommandUpdateTable1 : public QWidget
{
    Q_OBJECT

public:
    explicit CommandUpdateTable1(QWidget *parent = nullptr);
    ~CommandUpdateTable1();

private:
    Ui::CommandUpdateTable1 *ui;
};

#endif // COMMANDUPDATETABLE1_H
