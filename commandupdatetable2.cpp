#include "commandupdatetable2.h"
#include "ui_commandupdatetable2.h"

CommandUpdateTable2::CommandUpdateTable2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CommandUpdateTable2)
{
    ui->setupUi(this);
}

CommandUpdateTable2::~CommandUpdateTable2()
{
    delete ui;
}
