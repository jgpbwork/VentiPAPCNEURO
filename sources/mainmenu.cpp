/**
 * Created by Ing. Luis Alejandro Reyes Morales on 8/12/2020.
 *
 * email: inglreyesm@gmail.com
 * github: github.com/lreyesm
 * linkedin: linkedin.com/in/luis-alejandro-reyes-morales-9b672012a
 *
 */

#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "optiondatetime.h"
#include "optioncalibration.h"
#include "optionalarmlimit.h"
#include "optiongeneral.h"

/**
 * MainMenu::MainMenu 
 * 
 * Class constructor
 * Connect the signal of main menu widget 
 * and propagates event to mainscreen widget
 *
 * @param  {QWidget*} parent : 
 */
MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
     // ANCHOR [id=click_event_anchor]
    connect(ui->widget_menu, &MyWidgetAnimated::clicked, this, &MainMenu::emitClicked); 
}

MainMenu::~MainMenu()
{
    delete ui;
}

/**
 * MainMenu :: showMenu
 * 
 * Shows the menu with an animation if global animation is enable
 */
void MainMenu::showMenu(){
    this->show();
    this->raise();
    animateWidgetDownToUp(this, 300);
}

/**
 * MainMenu :: hideMenu
 *
 * Hides the menu with an animation if global animation is enable 
 */
void MainMenu::hideMenu(){
    animateHideWidgetUpToDown(this, 300);
}

/**
 * MainMenu 
 * 
 * Animates widget from down to up
 * 
 * @param  {QWidget*} widget : Widget to animate
 * @param  {int} anim_time   : Animation time interval (duration) 
 */
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

/**
 * MainMenu 
 * 
 * Animates widget from up to down
 * 
 * @param  {QWidget*} widget : Widget to animate
 * @param  {int} anim_time   : Animation time interval (duration) 
 */
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

/**
 * MainMenu 
 *
 * Emits click event to MainScreen class
 *
 * LINK #click_event_anchor
 */
void MainMenu::emitClicked()
{
    emit menu_clicked();
}

/**
 * MainMenu :: on_l_alarm_limit_clicked
 * 
 * ? Slot of alarm limit button on main menu widget 
 *
 * Shows the alarm options widget and hides main menu widget 
* LINK forms/optionalarmlimit.ui
 */
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


/**
 * MainMenu :: on_l_date_time_clicked
 * 
 * ? Slot of date time button on main menu widget 
 *
 * Shows the date time options widget and hides main menu widget
  * LINK forms/optiondatetime.ui 
 */
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


/**
 * MainMenu :: on_l_general_clicked
 * 
 * ? Slot of general button on main menu widget 
 *
 * Shows the general options widget and hides main menu widget 
* LINK forms/optiongeneral.ui
 */
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


/**
 * MainMenu :: on_l_calibration_clicked
 * 
 * ? Slot of calibration button on main menu widget 
 *
 * Shows the calibration options widget and hides main menu widget 
 * LINK forms/optioncalibration.ui
 */
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

/**
 * MainMenu :: showBackMenu
 * 
 * Shows the background of main menu widget by adding its stylesheet
 * (adds the png background image of main menu)
 */
void MainMenu::showBackMenu(){
    if(currentMenu == MENU_ALARM_LIMIT){
        emit alarmLimitSetted();
    }
    ui->widget_menu->setStyleSheet("background-image: url(:/icons/main_screen/widget_settings_on.png);");
}

/**
 * MainMenu :: hideBackMenu
 * 
 * Hides the background of the main menu widget by removing its stylesheet
 * making it transparent (removes the png background image of main menu)
 */
void MainMenu::hideBackMenu(){
    ui->widget_menu->setStyleSheet("");
}
