/**
* Created by Ing. Luis Alejandro Reyes Morales on 9/12/2020.
*
* email: inglreyesm@gmail.com
* github: https://github.com/lreyesm
* linkedin: https://linkedin.com/in/luis-alejandro-reyes-morales-9b672012a
*
*/

#include "optionsetdate.h"
#include "ui_optionsetdate.h"
#include "globalfunctions.h"
#include "mainwindow.h"

#include <QDebug>

/**
 * OptionSetDate :: OptionSetDate
 * 
 * Class constructor
 *
 * @param  {QWidget*} parent : parent of the widget
 */
OptionSetDate::OptionSetDate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OptionSetDate)
{
    ui->setupUi(this);

    fillJsonDate();

    currentDateTime = GlobalFunctions::dateTime;

    updateDateInfo();
}


OptionSetDate::~OptionSetDate()
{
    delete ui;
}

/**
 * OptionSetDate :: updateDateInfo
 * 
 * Get global current date of the computer and set it 
 * on this widget, displaying it on the UI 
 */
void OptionSetDate::updateDateInfo(){
    int d = currentDateTime.date().day();
    ui->l_day_value->setText(QString::number(d));

    int m = currentDateTime.date().month();
    QString m_display = mapMonth.key(m);
    ui->l_month_value->setText( m_display);

    int y = currentDateTime.date().year();
    ui->l_year_value->setText(QString::number(y));
}

/**
 * OptionSetDate :: fillJsonDate
 * 
 * Fill the json map of the month in spanish to display it on the UI
 */
void OptionSetDate::fillJsonDate(){
    mapMonth.insert("ENERO", 1);
    mapMonth.insert("FEBRERO" , 2);
    mapMonth.insert("MARZO", 3);
    mapMonth.insert("ABRIL", 4);
    mapMonth.insert("MAYO", 5);
    mapMonth.insert("JUNIO", 6);
    mapMonth.insert("JULIO", 7);
    mapMonth.insert("AGOSTO", 8);
    mapMonth.insert("SEPTIEMBRE", 9);
    mapMonth.insert("OCTUBRE", 10);
    mapMonth.insert("NOVIEMBRE", 11);
    mapMonth.insert("DICIEMBRE", 12);
}

/**
 * OptionSetDate :: on_pb_day_down_clicked
 * 
 * * Day decrease button 
 *
 * Decrease one day and set it on the UI
 */
void OptionSetDate::on_pb_day_down_clicked()
{
    QDate date = currentDateTime.date().addDays(-1);
    currentDateTime.setDate(date);
    updateDateInfo();
    qDebug()<<"on_pb_day_up_clicked" << date.toString()<<"****************************************";
}

/**
 * OptionSetDate :: on_pb_day_up_clicked
 * 
 * * Day increase button 
 *
 * Increase one day and set it on the UI
 */
void OptionSetDate::on_pb_day_up_clicked()
{
    QDate date = currentDateTime.date().addDays(1);
    currentDateTime.setDate(date);
    updateDateInfo();
    qDebug()<<"on_pb_day_up_clicked" << date.toString()<<"****************************************";
}

/**
 * OptionSetDate :: on_pb_month_down_clicked
 * 
 * * Month decrease button 
 *
 * Decrease one month and set it on the UI
 */
void OptionSetDate::on_pb_month_down_clicked()
{
    QDate date = currentDateTime.date().addMonths(-1);
    currentDateTime.setDate(date);
    updateDateInfo();
    qDebug()<<"on_pb_month_down_clicked" << date.toString()<<"****************************************";
}

/**
 * OptionSetDate :: on_pb_month_up_clicked
 * 
 * * Month increase button 
 *
 * Increase one month and set it on the UI
 */
void OptionSetDate::on_pb_month_up_clicked()
{
    QDate date = currentDateTime.date().addMonths(1);
    currentDateTime.setDate(date);
    updateDateInfo();
    qDebug()<<"on_pb_month_up_clicked" << date.toString()<<"****************************************";
}

/**
 * OptionSetDate :: on_pb_year_down_clicked
 * 
 * * Month increase button 
 *
 * Increase one month and set it on the UI
 */
void OptionSetDate::on_pb_year_down_clicked()
{
    QDate date = currentDateTime.date().addYears(-1);
    currentDateTime.setDate(date);
    updateDateInfo();
    qDebug()<<"on_pb_year_down_clicked" << date.toString()<<"****************************************";
}

/**
 * OptionSetDate :: on_pb_year_up_clicked
 * 
 * * Year increase button 
 *
 * Increase one year and set it on the UI
 */
void OptionSetDate::on_pb_year_up_clicked()
{
    QDate date = currentDateTime.date().addYears(1);
    currentDateTime.setDate(date);
    updateDateInfo();
    qDebug()<<"on_pb_year_up_clicked" << date.toString()<<"****************************************";
}

/**
 * OptionSetDate :: on_l_save_clicked
 * 
 * Saves the date setted, emit the date to all widgets
 * and close this widget
 */
void OptionSetDate::on_l_save_clicked()
{
    GlobalFunctions::setDateTimeInRaspi(this, currentDateTime);
    MainWindow *w = static_cast<MainWindow *>
            (this->parentWidget()->parentWidget()
             ->parentWidget()->parentWidget());
    if(w){
        w->setDateTimeToThread(currentDateTime);
    }
    on_l_define_date_back_clicked();
}

/**
 * OptionSetDate :: on_l_define_date_back_clicked:: on_l_define_date_back_clicked
 *
 * ? Slot of back button on date menu widget 
 *
 * Closes about widget and show the general options widget
 * LINK forms/optiongeneral.ui
 */
void OptionSetDate::on_l_define_date_back_clicked()
{
    emit closing();
    this->close();
}

