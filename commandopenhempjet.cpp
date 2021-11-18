#include "commandopenhempjet.h"
#include "ui_commandopenhempjet.h"

CommandOpenHempjet::CommandOpenHempjet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CommandOpenHempjet)
{
    ui->setupUi(this);
}

CommandOpenHempjet::~CommandOpenHempjet()
{
    delete ui;
}
