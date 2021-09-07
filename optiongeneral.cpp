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

/**
 * OptionGeneral::OptionGeneral 
 * 
 * Class constructor
 *
 * @param  {QWidget*} parent : parent of the widget
 */
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

/**
 * OptionGeneral :: on_l_general_back_clicked
 * 
 * Closes general widget and show the main menu widget
 */
void OptionGeneral::on_l_general_back_clicked(){
    this->close();
    emit closing();
}

/**
 * OptionGeneral :: on_l_about_clicked
 * 
 * Opens the about widget
 */
void OptionGeneral::on_l_about_clicked(){
    AboutScreen *screen = new AboutScreen(this);
    screen->move(0, 0);
    screen->show();
    screen->raise();
}
