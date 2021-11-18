#include "commandupdatetable1.h"
#include "ui_commandupdatetable1.h"

CommandUpdateTable1::CommandUpdateTable1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CommandUpdateTable1)
{
    ui->setupUi(this);
}

CommandUpdateTable1::~CommandUpdateTable1()
{
    delete ui;
}
