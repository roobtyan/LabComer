#include "commandspacewetherstation.h"
#include "ui_commandspacewetherstation.h"

CommandSpaceWetherStation::CommandSpaceWetherStation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CommandSpaceWetherStation)
{
    ui->setupUi(this);
}

CommandSpaceWetherStation::~CommandSpaceWetherStation()
{
    delete ui;
}
