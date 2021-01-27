<<<<<<< HEAD
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
=======
#include "optionsettime.h"
#include "ui_optionsettime.h"
#include "globalfunctions.h"
#include <QDebug>
#include <QProcess>

OptionSetTime::OptionSetTime(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OptionSetTime)
{
    ui->setupUi(this);
    currentDateTime = GlobalFunctions::dateTime;

    int min = currentDateTime.time().minute();
    ui->l_minute_value->setText(min);

    int h = currentDateTime.time().hour();
    ui->l_hour_value->setText(h);
}

OptionSetTime::~OptionSetTime()
{
    delete ui;
}

void OptionSetTime::on_l_save_clicked()
{
    GlobalFunctions::setDateTimeInRaspi(this, currentDateTime);
}

void OptionSetTime::on_l_define_time_back_clicked()
{
    emit closing();
    this->close();
}

void OptionSetTime::on_pb_minutes_down_clicked()
{
    QTime time = currentDateTime.time().addSecs(-60);
    int min = currentDateTime.time().minute();
    ui->l_minute_value->setText(min);
    currentDateTime.setTime(time);
    qDebug()<<"on_pb_minutes_down_clicked" << time.toString()<<"****************************************";
}

void OptionSetTime::on_pb_minutes_up_clicked()
{
    QTime time = currentDateTime.time().addSecs(60);
    int min = currentDateTime.time().minute();
    ui->l_minute_value->setText(min);
    currentDateTime.setTime(time);
    qDebug()<<"on_pb_minutes_up_clicked" << time.toString()<<"****************************************";
}

void OptionSetTime::on_pb_hours_down_clicked()
{
    QTime time = currentDateTime.time().addSecs(-3600);
    int h = currentDateTime.time().hour();
    ui->l_hour_value->setText(h);
    currentDateTime.setTime(time);
    qDebug()<<"on_pb_hours_down_clicked" << time.toString()<<"****************************************";
}

void OptionSetTime::on_pb_hours_up_clicked()
{
    QTime time = currentDateTime.time().addSecs(3600);
    int h = currentDateTime.time().hour();
    ui->l_hour_value->setText(h);
    currentDateTime.setTime(time);
    qDebug()<<"on_pb_hours_up_clicked" << time.toString()<<"****************************************";
}
>>>>>>> 9090ceb909ef3c3f4473bedbfa53a0fa127bc4ed
