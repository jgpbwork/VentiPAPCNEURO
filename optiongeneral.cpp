#include "optiongeneral.h"
#include "ui_optiongeneral.h"

#include "aboutscreen.h"

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

void OptionGeneral::on_l_about_clicked(){
    AboutScreen *screen = new AboutScreen(this);
    screen->move(0, 345 - screen->height());
    screen->show();
    screen->raise();
}
