#include "optionalarmlimit.h"
#include "ui_optionalarmlimit.h"
#include "globalfunctions.h"

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

void OptionAlarmLimit::on_l_save_clicked(){
    GlobalFunctions::configured_min_limit = min_limit;
    GlobalFunctions::configured_max_limit = max_limit;
    this->close();
    emit closing();
}

void OptionAlarmLimit::on_pb_min_limit_up_clicked()
{
    if(min_limit < max_limit){
        min_limit++;
        ui->l_min_value->setText(QString::number(min_limit));
    }
}

void OptionAlarmLimit::on_pb_min_limit_down_clicked()
{
    if(min_limit > MIN_ALARM_CONFIG){
        min_limit--;
        ui->l_min_value->setText(QString::number(min_limit));
    }
}

void OptionAlarmLimit::on_pb_max_limit_up_clicked()
{
    if(max_limit < MAX_ALARM_CONFIG){
        max_limit++;
        ui->l_max_value->setText(QString::number(max_limit));
    }
}

void OptionAlarmLimit::on_pb_max_limit_down_clicked()
{
    if(max_limit > min_limit){
        max_limit--;
        ui->l_max_value->setText(QString::number(max_limit));
    }
}
