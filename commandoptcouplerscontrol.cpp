#include "commandoptcouplerscontrol.h"
#include "ui_commandoptcouplerscontrol.h"

CommandOptCouplersControl::CommandOptCouplersControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CommandOptCouplersControl)
{
    ui->setupUi(this);
}

CommandOptCouplersControl::~CommandOptCouplersControl()
{
    delete ui;
}
