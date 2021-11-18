#include "commandupdatetable3.h"
#include "ui_commandupdatetable3.h"

CommandUpdateTable3::CommandUpdateTable3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CommandUpdateTable3)
{
    ui->setupUi(this);
}

CommandUpdateTable3::~CommandUpdateTable3()
{
    delete ui;
}
