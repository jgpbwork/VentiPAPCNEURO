/**
* Created by Ing. Luis Alejandro Reyes Morales on 9/12/2020.
*
* email: inglreyesm@gmail.com
* github: https://github.com/lreyesm
* linkedin: https://linkedin.com/in/luis-alejandro-reyes-morales-9b672012a
*
*/

#include "optionsettime.h"
#include "ui_optionsettime.h"
#include "globalfunctions.h"
#include <QDebug>
#include <QProcess>
#include "mainwindow.h"

/**
 * OptionSetTime :: OptionSetTime
 * 
 * @param  {QWidget*} parent : 
 */
OptionSetTime::OptionSetTime(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OptionSetTime)
{
    ui->setupUi(this);
    currentDateTime = GlobalFunctions::dateTime;

    updateTimeInfo();
}

OptionSetTime::~OptionSetTime()
{
    delete ui;
}

/**
 * OptionSetTime :: updateTimeInfo
 * 
 * Get global current time of the computer and set it 
 * on this widget, displaying it on the UI 
 */
void OptionSetTime::updateTimeInfo(){
    int min = currentDateTime.time().minute();
    ui->l_minute_value->setText(QString::number(min));

    int h = currentDateTime.time().hour();
    ui->l_hour_value->setText(QString::number(h));
}

/**
 * OptionSetTime :: on_l_save_clicked
 * 
 * Saves the time setted, emit the time to all widgets
 * and close this widget
 */
void OptionSetTime::on_l_save_clicked()
{
    GlobalFunctions::setDateTimeInRaspi(this, currentDateTime);
    MainWindow *w = static_cast<MainWindow *>
            (this->parentWidget()->parentWidget()
             ->parentWidget()->parentWidget());
    if(w){
        w->setDateTimeToThread(currentDateTime);
    }
    emit dateSetted(currentDateTime);
    on_l_define_time_back_clicked();
}

/**
 * OptionSetTime :: on_l_define_time_back_clicked:: on_l_define_time_back_clicked
 *
 * ? Slot of back button on time menu widget 
 *
 * Closes about widget and show the general options widget
 * LINK forms/optiongeneral.ui
 */
void OptionSetTime::on_l_define_time_back_clicked()
{
    emit closing();
    this->close();
}

/**
 * OptionSetTime :: on_pb_minutes_down_clicked
 * 
 * * Minute decrease button 
 *
 * Decrease one minute and set it on the UI
 */
void OptionSetTime::on_pb_minutes_down_clicked()
{
    QTime time = currentDateTime.time().addSecs(-60);
    currentDateTime.setTime(time);
    updateTimeInfo();
    qDebug()<<"on_pb_minutes_down_clicked" << time.toString()<<"****************************************";
}


/**
 * OptionSetTime :: on_pb_minutes_up_clicked
 * 
 * * Minute increase button 
 *
 * Increase one minute and set it on the UI
 */
void OptionSetTime::on_pb_minutes_up_clicked()
{
    QTime time = currentDateTime.time().addSecs(60);
    currentDateTime.setTime(time);
    updateTimeInfo();
    qDebug()<<"on_pb_minutes_up_clicked" << time.toString()<<"****************************************";
}

/**
 * OptionSetTime :: on_pb_hours_down_clicked
 * 
 * * Hour decrease button 
 *
 * Decrease one hour and set it on the UI
 */
void OptionSetTime::on_pb_hours_down_clicked()
{
    QTime time = currentDateTime.time().addSecs(-3600);
    currentDateTime.setTime(time);
    updateTimeInfo();
    qDebug()<<"on_pb_hours_down_clicked" << time.toString()<<"****************************************";
}


/**
 * OptionSetTime :: on_pb_hours_up_clicked
 * 
 * * Hour increase button 
 *
 * Increase one hour and set it on the UI
 */
void OptionSetTime::on_pb_hours_up_clicked()
{
    QTime time = currentDateTime.time().addSecs(3600);
    currentDateTime.setTime(time);
    updateTimeInfo();
    qDebug()<<"on_pb_hours_up_clicked" << time.toString()<<"****************************************";
}
