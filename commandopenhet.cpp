#include "command_open_het.h"
#include "ui_command_open_het.h"

command_open_het::command_open_het(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::command_open_het)
{
    ui->setupUi(this);
}

command_open_het::~command_open_het()
{
    delete ui;
}
