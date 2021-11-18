#ifndef COMMANDOPENHEMPJET_H
#define COMMANDOPENHEMPJET_H

#include <QWidget>

namespace Ui {
class CommandOpenHempjet;
}

class CommandOpenHempjet : public QWidget
{
    Q_OBJECT

public:
    explicit CommandOpenHempjet(QWidget *parent = nullptr);
    ~CommandOpenHempjet();

private:
    Ui::CommandOpenHempjet *ui;
};

#endif // COMMANDOPENHEMPJET_H
