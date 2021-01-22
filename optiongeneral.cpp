#include "optiongeneral.h"
#include "ui_optiongeneral.h"

OptionGeneral::OptionGeneral(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OptionGeneral)
{
    ui->setupUi(this);
}

OptionGeneral::~OptionGeneral()
{
    delete ui;
}

void OptionGeneral::on_l_general_back_clicked(){
    this->close();
    emit closing();
}
