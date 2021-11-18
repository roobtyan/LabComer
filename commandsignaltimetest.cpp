#include "commandsignaltimetest.h"
#include "ui_commandsignaltimetest.h"

CommandSignalTimeTest::CommandSignalTimeTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CommandSignalTimeTest)
{
    ui->setupUi(this);
}

CommandSignalTimeTest::~CommandSignalTimeTest()
{
    delete ui;
}
