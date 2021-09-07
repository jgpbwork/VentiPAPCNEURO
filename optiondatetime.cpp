/**
* Created by Ing. Luis Alejandro Reyes Morales on 9/12/2020.
*
* email: inglreyesm@gmail.com
* github: https://github.com/lreyesm
* linkedin: https://linkedin.com/in/luis-alejandro-reyes-morales-9b672012a
*
*/

#include "optiondatetime.h"
#include "ui_optiondatetime.h"
#include "optionsettime.h"
#include "optionsetdate.h"

/**
 * OptionDateTime :: OptionDateTime
 * 
 * Class constructor
 *
 * @param  {QWidget*} parent : parent of the widget
 */
OptionDateTime::OptionDateTime(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OptionDateTime)
{
    ui->setupUi(this);
}

OptionDateTime::~OptionDateTime()
{
    delete ui;
}

/**
 * OptionDateTime :: on_l_date_time_back_clicked
 * 
 * Closes about widget and show the main menu widget
 */
void OptionDateTime::on_l_date_time_back_clicked(){
    this->close();
    emit closing();
}

/**
 * OptionDateTime :: on_l_define_date_clicked
 * 
 * Opens the date widget
 */
void OptionDateTime::on_l_define_date_clicked()
{
    OptionSetDate *screen = new OptionSetDate(this);
    screen->move(0, 0);
    screen->show();
    screen->raise();
    this->hideBackMenu();
    connect(screen, SIGNAL(closing()), this, SLOT(showBackMenu()));
}

/**
 * OptionDateTime :: on_l_define_time_clicked
 * 
 * Opens the time widget
 */
void OptionDateTime::on_l_define_time_clicked()
{
    OptionSetTime *screen = new OptionSetTime(this);
    screen->move(0, 0);
    screen->show();
    screen->raise();
    this->hideBackMenu();
    connect(screen, SIGNAL(closing()), this, SLOT(showBackMenu()));
}

/**
 * OptionDateTime :: setDate
 * 
 * * Not using this function
 *
 * @param  {QDateTime} currentDateTime : 
 */
void OptionDateTime::setDate(QDateTime currentDateTime)
{

}

/**
 * OptionDateTime :: on_l_12_hours_clicked
 * 
 * * Not using this function
 *
 * @param  {QDateTime} currentDateTime : 
 */
void OptionDateTime::on_l_12_hours_clicked()
{

}

/**
 * OptionDateTime :: on_l_24_hours_clicked
 * 
 * * Not using this function
 *
 * @param  {QDateTime} currentDateTime : 
 */
void OptionDateTime::on_l_24_hours_clicked()
{

}

/**
 * OptionDateTime :: showBackMenu
 * 
 * * Not using this function
 *
 * @param  {QDateTime} currentDateTime : 
 */
void OptionDateTime::showBackMenu(){
//    ui->widget_menu->setStyleSheet("background-image: url(:/icons/main_screen/widget_settings_on.png);");
}

/**
 * OptionDateTime :: hideBackMenu
 * 
 * * Not using this function
 *
 * @param  {QDateTime} currentDateTime : 
 */
void OptionDateTime::hideBackMenu(){
//    ui->widget_menu->setStyleSheet("");
}

