/**
* Created by Ing. Luis Alejandro Reyes Morales on 9/12/2020.
*
* email: inglreyesm@gmail.com
* github: https://github.com/lreyesm
* linkedin: https://linkedin.com/in/luis-alejandro-reyes-morales-9b672012a
*
*/

#include "optionalarmlimit.h"
#include "ui_optionalarmlimit.h"
#include "globalfunctions.h"
#include <QSaveFile>
#include <QTextStream>

/**
 * OptionAlarmLimit :: OptionAlarmLimit
 * 
 * Sets the configured range values and displays them on the UI
 *
 * @param  {QWidget*} parent : Parent of this widget
 */
OptionAlarmLimit::OptionAlarmLimit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OptionAlarmLimit)
{
    ui->setupUi(this);
    min_limit = GlobalFunctions::configured_min_limit;
    max_limit = GlobalFunctions::configured_max_limit;
    ui->l_min_value->setText(QString::number(min_limit));
    ui->l_max_value->setText(QString::number(max_limit));
}

OptionAlarmLimit::~OptionAlarmLimit()
{
    delete ui;
}

/**
 * OptionAlarmLimit :: on_l_save_clicked
 * 
 * Saves the values configured and closes the widget
 */
void OptionAlarmLimit::on_l_save_clicked(){
    GlobalFunctions::configured_min_limit = min_limit;
    GlobalFunctions::configured_max_limit = max_limit;
    QSaveFile file("/home/pi/alarm_limits");
    QTextStream out(&file);
    if(file.open(QIODevice::WriteOnly))
    {
        out << min_limit << "\n" << max_limit;
        file.commit();
    }
    else
    {
        GlobalFunctions::setWarningMessage(this, "No se pudo salvar la configuracion. Contacte con el personal de Asistencia Tecnica.");
    }

    this->close();
    emit closing();
}

/**
 * OptionAlarmLimit :: on_pb_min_limit_up_clicked
 *
 * * Down limit button increase
 * Slot listening the pb_min_limit button, if value is already at
 * the down limit of the range configure does nothing else increment it 
 */
void OptionAlarmLimit::on_pb_min_limit_up_clicked()
{
    if(min_limit < max_limit){
        min_limit++;
        ui->l_min_value->setText(QString::number(min_limit));
    }
}

/**
 * OptionAlarmLimit :: on_pb_min_limit_down_clicked
 *
 * * Down limit button decrease
 * Slot listening the pb_min_limit button, if value is already at
 * the down limit of the range configure does nothing else decrement it 
 */
void OptionAlarmLimit::on_pb_min_limit_down_clicked()
{
    if(min_limit > MIN_ALARM_CONFIG){
        min_limit--;
        ui->l_min_value->setText(QString::number(min_limit));
    }
}

/**
 * OptionAlarmLimit :: on_pb_max_limit_up_clicked
 *
 * * Up limit button increase
 * Slot listening the pb_min_limit button, if value is already at
 * the up limit of the range configure does nothing else increment it 
 */
void OptionAlarmLimit::on_pb_max_limit_up_clicked()
{
    if(max_limit < MAX_ALARM_CONFIG){
        max_limit++;
        ui->l_max_value->setText(QString::number(max_limit));
    }
}

/**
 * OptionAlarmLimit :: on_pb_max_limit_down_clicked
 * 
 * * Up limit button increase
 * Slot listening the pb_min_limit button, if value is already at
 * the up limit of the range configure does nothing else decrement it 
 */
void OptionAlarmLimit::on_pb_max_limit_down_clicked()
{
    if(max_limit > min_limit){
        max_limit--;
        ui->l_max_value->setText(QString::number(max_limit));
    }
}
