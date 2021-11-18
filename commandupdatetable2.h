#ifndef COMMANDUPDATETABLE2_H
#define COMMANDUPDATETABLE2_H

#include <QWidget>

namespace Ui {
class CommandUpdateTable2;
}

class CommandUpdateTable2 : public QWidget
{
    Q_OBJECT

public:
    explicit CommandUpdateTable2(QWidget *parent = nullptr);
    ~CommandUpdateTable2();

private:
    Ui::CommandUpdateTable2 *ui;
};

#endif // COMMANDUPDATETABLE2_H
