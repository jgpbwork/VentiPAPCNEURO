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

void OptionSetTime::updateTimeInfo(){
    int min = currentDateTime.time().minute();
    ui->l_minute_value->setText(QString::number(min));

    int h = currentDateTime.time().hour();
    ui->l_hour_value->setText(QString::number(h));
}

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

void OptionSetTime::on_l_define_time_back_clicked()
{
    emit closing();
    this->close();
}

void OptionSetTime::on_pb_minutes_down_clicked()
{
    QTime time = currentDateTime.time().addSecs(-60);
    currentDateTime.setTime(time);
    updateTimeInfo();

    qDebug()<<"on_pb_minutes_down_clicked" << time.toString()<<"****************************************";
}

void OptionSetTime::on_pb_minutes_up_clicked()
{
    QTime time = currentDateTime.time().addSecs(60);
    currentDateTime.setTime(time);
    updateTimeInfo();

    qDebug()<<"on_pb_minutes_up_clicked" << time.toString()<<"****************************************";
}

void OptionSetTime::on_pb_hours_down_clicked()
{
    QTime time = currentDateTime.time().addSecs(-3600);
    currentDateTime.setTime(time);
    updateTimeInfo();

    qDebug()<<"on_pb_hours_down_clicked" << time.toString()<<"****************************************";
}

void OptionSetTime::on_pb_hours_up_clicked()
{
    QTime time = currentDateTime.time().addSecs(3600);
    currentDateTime.setTime(time);
    updateTimeInfo();

    qDebug()<<"on_pb_hours_up_clicked" << time.toString()<<"****************************************";
}
