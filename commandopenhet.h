#ifndef COMMAND_OPEN_HET_H
#define COMMAND_OPEN_HET_H

#include <QWidget>

namespace Ui {
class command_open_het;
}

class command_open_het : public QWidget
{
    Q_OBJECT

public:
    explicit command_open_het(QWidget *parent = nullptr);
    ~command_open_het();

private:
    Ui::command_open_het *ui;
};

#endif // COMMAND_OPEN_HET_H
