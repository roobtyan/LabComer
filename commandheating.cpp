#include "commandheating.h"
#include "ui_commandheating.h"

CommandHeating::CommandHeating(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CommandHeating)
{
    ui->setupUi(this);
}

CommandHeating::~CommandHeating()
{
    delete ui;
}
