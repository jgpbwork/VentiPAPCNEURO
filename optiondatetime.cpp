<<<<<<< HEAD
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
=======
#include "optiondatetime.h"
#include "ui_optiondatetime.h"
#include "optionsettime.h"
#include "optionsetdate.h"

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

void OptionDateTime::on_l_define_date_clicked()
{
    OptionSetDate *screen = new OptionSetDate(this);
    screen->move(0, 345 - screen->height());
    screen->show();
    screen->raise();
    this->hideBackMenu();
    connect(screen, SIGNAL(closing()), this, SLOT(showBackMenu()));
}

void OptionDateTime::on_l_define_time_clicked()
{
    OptionSetTime *screen = new OptionSetTime(this);
    screen->move(0, 345 - screen->height());
    screen->show();
    screen->raise();
    this->hideBackMenu();
    connect(screen, SIGNAL(closing()), this, SLOT(showBackMenu()));
}

void OptionDateTime::on_l_12_hours_clicked()
{

}

void OptionDateTime::on_l_24_hours_clicked()
{

}

void OptionDateTime::showBackMenu(){
//    ui->widget_menu->setStyleSheet("background-image: url(:/icons/main_screen/widget_settings_on.png);");
}
void OptionDateTime::hideBackMenu(){
//    ui->widget_menu->setStyleSheet("");
}

>>>>>>> 9090ceb909ef3c3f4473bedbfa53a0fa127bc4ed
