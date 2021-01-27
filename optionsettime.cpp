#include "optionsettime.h"
#include "ui_optionsettime.h"

OptionSetTime::OptionSetTime(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OptionSetTime)
{
    ui->setupUi(this);
}

OptionSetTime::~OptionSetTime()
{
    delete ui;
}

void OptionSetTime::on_l_save_clicked()
{

}

void OptionSetTime::on_l_define_time_back_clicked()
{

}

void OptionSetTime::on_pb_minutes_down_clicked()
{

}

void OptionSetTime::on_pb_minutes_up_clicked()
{

}

void OptionSetTime::on_pb_hours_down_clicked()
{

}

void OptionSetTime::on_pb_hours_up_clicked()
{

}
