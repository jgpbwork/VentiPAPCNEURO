#include "optiondatetime.h"
#include "ui_optiondatetime.h"

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

void OptionDateTime::on_l_date_time_back_clicked(){
    this->close();
    emit closing();
}
