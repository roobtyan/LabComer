#include "commandhempjetadvanced.h"
#include "ui_commandhempjetadvanced.h"

CommandHempJetAdvanced::CommandHempJetAdvanced(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CommandHempJetAdvanced)
{
    ui->setupUi(this);
}

CommandHempJetAdvanced::~CommandHempJetAdvanced()
{
    delete ui;
}
