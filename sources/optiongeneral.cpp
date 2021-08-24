/**
* Created by Ing. Luis Alejandro Reyes Morales on 9/12/2020.
*
* email: inglreyesm@gmail.com
* github: https://github.com/lreyesm
* linkedin: https://linkedin.com/in/luis-alejandro-reyes-morales-9b672012a
*
*/

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
    screen->move(0, 0);
    screen->show();
    screen->raise();
}
