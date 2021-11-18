#ifndef COMMANDSIGNALTIMETEST_H
#define COMMANDSIGNALTIMETEST_H

#include <QWidget>

namespace Ui {
class CommandSignalTimeTest;
}

class CommandSignalTimeTest : public QWidget
{
    Q_OBJECT

public:
    explicit CommandSignalTimeTest(QWidget *parent = nullptr);
    ~CommandSignalTimeTest();

private:
    Ui::CommandSignalTimeTest *ui;
};

#endif // COMMANDSIGNALTIMETEST_H
