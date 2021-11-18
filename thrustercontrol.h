#ifndef THRUSTERCONTROL_H
#define THRUSTERCONTROL_H

#include <QWidget>

namespace Ui {
class ThrusterControl;
}

class ThrusterControl : public QWidget
{
    Q_OBJECT

public:
    explicit ThrusterControl(QWidget *parent = nullptr);
    ~ThrusterControl();

private:
    Ui::ThrusterControl *ui;
};

#endif // THRUSTERCONTROL_H
