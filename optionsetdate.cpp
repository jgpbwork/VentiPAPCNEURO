<<<<<<< HEAD
#include "optionsetdate.h"
#include "ui_optionsetdate.h"

OptionSetDate::OptionSetDate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OptionSetDate)
{
    ui->setupUi(this);
}

OptionSetDate::~OptionSetDate()
{
    delete ui;
}
=======
#include "optionsetdate.h"
#include "ui_optionsetdate.h"
#include "globalfunctions.h"

#include <QDebug>

OptionSetDate::OptionSetDate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OptionSetDate)
{
    ui->setupUi(this);

    fillJsonDate();

    currentDateTime = GlobalFunctions::dateTime;


    int d = currentDateTime.date().day();
    ui->l_day_value->setText(d);

    int m = currentDateTime.date().month();
    QString m_display = mapMonth.key(m);
    ui->l_month_value->setText(m_display+1);

    int y = currentDateTime.date().year();
    ui->l_year_value->setText(y);
}

OptionSetDate::~OptionSetDate()
{
    delete ui;
}

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

void OptionSetDate::on_pb_day_down_clicked()
{
    QDate date = currentDateTime.date().addDays(-1);
    int d = currentDateTime.date().day();
    ui->l_day_value->setText(d);
    currentDateTime.setDate(date);
    qDebug()<<"on_pb_day_up_clicked" << date.toString()<<"****************************************";
}


void OptionSetDate::on_pb_day_up_clicked()
{
    QDate date = currentDateTime.date().addDays(1);
    int d = currentDateTime.date().day();
    ui->l_day_value->setText(d);
    currentDateTime.setDate(date);
    qDebug()<<"on_pb_day_up_clicked" << date.toString()<<"****************************************";
}


void OptionSetDate::on_pb_month_down_clicked()
{
    QDate date = currentDateTime.date().addMonths(-1);
    int m = currentDateTime.date().month();
    QString m_display = mapMonth.key(m);
    ui->l_month_value->setText(m_display+1);
    currentDateTime.setDate(date);
    qDebug()<<"on_pb_month_down_clicked" << date.toString()<<"****************************************";
}


void OptionSetDate::on_pb_month_up_clicked()
{
    QDate date = currentDateTime.date().addMonths(1);
    int m = currentDateTime.date().month();
    QString m_display = mapMonth.key(m);
    ui->l_month_value->setText(m_display+1);
    currentDateTime.setDate(date);
    qDebug()<<"on_pb_month_up_clicked" << date.toString()<<"****************************************";
}


void OptionSetDate::on_pb_year_down_clicked()
{
    QDate date = currentDateTime.date().addYears(-1);
    int y = currentDateTime.date().year();
    ui->l_year_value->setText(y);
    currentDateTime.setDate(date);
    qDebug()<<"on_pb_year_down_clicked" << date.toString()<<"****************************************";
}


void OptionSetDate::on_pb_year_up_clicked()
{
    QDate date = currentDateTime.date().addYears(1);
    int y = currentDateTime.date().year();
    ui->l_year_value->setText(y);
    currentDateTime.setDate(date);
    qDebug()<<"on_pb_year_up_clicked" << date.toString()<<"****************************************";
}

void OptionSetDate::on_l_save_clicked()
{
    GlobalFunctions::setDateTimeInRaspi(this, currentDateTime);
}

void OptionSetDate::on_l_define_date_back_clicked()
{
    emit closing();
    this->close();
}
>>>>>>> 9090ceb909ef3c3f4473bedbfa53a0fa127bc4ed
