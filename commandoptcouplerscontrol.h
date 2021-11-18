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

    QString commandOptCouplersControlValues(QString opto_coupler_num, QString opto_coupler_state);

signals:

    void sendOptCouplersControlCommand(QString result);

private slots:

    void on_pushButton_clicked();

private:
    Ui::CommandOptCouplersControl *ui;
};

#endif // COMMANDOPTCOUPLERSCONTROL_H
