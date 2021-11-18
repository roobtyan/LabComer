#include "thrustercontrol.h"
#include "ui_thrustercontrol.h"

ThrusterControl::ThrusterControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ThrusterControl)
{
    ui->setupUi(this);
}

ThrusterControl::~ThrusterControl()
{
    delete ui;
}
