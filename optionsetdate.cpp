#include "optionsetdate.h"
#include "ui_optionsetdate.h"

OptionSetDate::OptionSetDate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OptionSetDate)
{
    ui->setupUi(this);
}

OptionSetDate::~OptionSetDate()
{
    delete ui;
}
