#ifndef COMMANDHEMPJETADVANCED_H
#define COMMANDHEMPJETADVANCED_H

#include <QWidget>

namespace Ui {
class CommandHempJetAdvanced;
}

class CommandHempJetAdvanced : public QWidget
{
    Q_OBJECT

public:
    explicit CommandHempJetAdvanced(QWidget *parent = nullptr);
    ~CommandHempJetAdvanced();

private:
    Ui::CommandHempJetAdvanced *ui;
};

#endif // COMMANDHEMPJETADVANCED_H
