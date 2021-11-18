#include "commandvalvescontrol.h"
#include "ui_commandvalvescontrol.h"

CommandValvesControl::CommandValvesControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CommandValvesControl)
{
    ui->setupUi(this);
}

CommandValvesControl::~CommandValvesControl()
{
    delete ui;
}
