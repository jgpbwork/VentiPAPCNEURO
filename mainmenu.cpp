#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "optiondatetime.h"
#include "optioncalibration.h"
#include "optionalarmlimit.h"
#include "optiongeneral.h"


MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    connect(ui->widget_menu, &MyWidgetAnimated::clicked,
            this, &MainMenu::emitClicked);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::showMenu(){
    this->show();
    this->raise();
    animateWidgetDownToUp(this, 300);
}

void MainMenu::hideMenu(){
    animateHideWidgetUpToDown(this, 300);
}
void MainMenu::animateWidgetDownToUp(QWidget *widget, int anim_time){
    QRect endValue = widget->geometry();
    QRect startValue = QRect(endValue.x(),endValue.y() + endValue.height()
                             ,endValue.width(), endValue.height());


    QPropertyAnimation *animation = new QPropertyAnimation(widget, "geometry");
    animation->setDuration(anim_time);
    animation->setStartValue(startValue);
    animation->setEndValue(endValue);
    animation->start();
}
void MainMenu::animateHideWidgetUpToDown(QWidget *widget, int anim_time){

    QRect startValue = widget->geometry();
    QRect endValue = QRect(startValue.x(),startValue.y() + startValue.height()
                           ,startValue.width(), startValue.height());

    QPropertyAnimation *animation = new QPropertyAnimation(widget, "geometry");
    animation->setDuration(anim_time);
    animation->setStartValue(startValue);
    animation->setEndValue(endValue);
    QObject::connect(animation, &QPropertyAnimation::finished, widget, &QWidget::close);
    animation->start();
}

void MainMenu::emitClicked()
{
    emit menu_clicked();
}

void MainMenu::on_l_alarm_limit_clicked()
{
    OptionAlarmLimit *screen = new OptionAlarmLimit(this);
    screen->move(0, 345 - screen->height());
    screen->show();
    screen->raise();
    this->hideBackMenu();
    currentMenu = MENU_ALARM_LIMIT;
    connect(screen, SIGNAL(closing()), this, SLOT(showBackMenu()));
}

void MainMenu::on_l_date_time_clicked()
{
    OptionDateTime *screen = new OptionDateTime(this);
    screen->move(0, 345 - screen->height());
    screen->show();
    screen->raise();
    this->hideBackMenu();
    currentMenu = MENU_DATE_TIME;
    connect(screen, SIGNAL(closing()), this, SLOT(showBackMenu()));
}

void MainMenu::on_l_general_clicked()
{
    OptionGeneral *screen = new OptionGeneral(this);
    screen->move(0, 345 - screen->height());
    screen->show();
    screen->raise();
    this->hideBackMenu();
    currentMenu = MENU_GENERAL;
    connect(screen, SIGNAL(closing()), this, SLOT(showBackMenu()));
}

void MainMenu::on_l_calibration_clicked()
{
    OptionCalibration *screen = new OptionCalibration(this);
    screen->move(0, 345 - screen->height());
    screen->show();
    screen->raise();
    this->hideBackMenu();
    currentMenu = MENU_CALIBRATION;
    connect(screen, SIGNAL(closing()), this, SLOT(showBackMenu()));
}

void MainMenu::showBackMenu(){
    if(currentMenu == MENU_ALARM_LIMIT){
        emit alarmLimitSetted();
    }
    ui->widget_menu->setStyleSheet("background-image: url(:/icons/main_screen/widget_settings_on.png);");
}
void MainMenu::hideBackMenu(){
    ui->widget_menu->setStyleSheet("");
}
