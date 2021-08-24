#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QRandomGenerator>
#include <QDebug>
#include <QDesktopWidget>

/**
 * Constructor of the class
 * ! This class connects the UI controller classes to the hardware's driver classes
 * * Connects all signals sendded by the driver classes to the UI classes and viceversa
 *
 * @param  {parent} undefined                        : 
 * @return {MainWindow::MainWindow(QWidgetparent)*}  : 
 */
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), 
                                          ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if(QApplication::desktop()->width() < 1000){
        this->setCursor(Qt::BlankCursor);
    }
    setWindowFlags(Qt::CustomizeWindowHint);
    this->move(0,0);

    main_screen = new MainScreen(this);
    main_screen->hide();
    QTimer::singleShot(5000, this, &MainWindow::initApp);

    connect(&thrInput, &ThrInput::updateOxygenLevel, this, &MainWindow::setOxygenValue);
    connect(&thrInput, &ThrInput::updateRealTimeClock, this, &MainWindow::setDateTime);
    connect(main_screen, &MainScreen::alarmOn, this, &MainWindow::alarmOn);
    connect(main_screen, &MainScreen::alarmOff, this, &MainWindow::alarmOff);
    connect(main_screen, &MainScreen::alarmType, this, &MainWindow::alarmType);

    connect(&thrInput, &ThrInput::batteryChargeLevel, main_screen, &MainScreen::setBatteryChargeLevel);
    connect(&thrInput, &ThrInput::batteryFull, main_screen, &MainScreen::onBatteryFull);

    qDebug()<< "Application has Started ok" 
            << "888"
            << "********************************";
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * MainWindow 
 * 
 * ! Initialization function
 * * Show the main screen and makes this class widget transparent
 */
void MainWindow::initApp(){
    this->setStyleSheet("");
    if(main_screen){
        main_screen->show();
    }
}

/**
 * MainWindow 
 * 
 * Sets the alarm priority type to emit the right sound
 * 
 * @param  {ThrAlarm::AlarmPriority} type : Type of the alarm (high or medium)
 */
void MainWindow::alarmType(ThrAlarm::AlarmPriority type) {
    this->thrAlarm.setAlarmType(type);
}

/**
 * MainWindow 
 * 
 * Actives the alarm to start emiting the sound
 */
void MainWindow::alarmOn() {
    this->thrAlarm.alarmOn();
}

/**
 * MainWindow 
 * 
 * Disable the alarm to stop emiting the sound
 */
void MainWindow::alarmOff() {
    this->thrAlarm.alarmOff();
}

/**
 * MainWindow 
 * 
 * Sets the oxygen value in the main screen class
 *
 * @param  {double} value : Value the display on the UI
 */
void MainWindow::setOxygenValue(double value){
    if(main_screen){
        main_screen->setOxygenValue(value);
    }
}

/**
 * MainWindow 
 * 
 * Sets the time to the RTC driver class
 *
 * @param  {QDateTime} dateTime : 
 */
void MainWindow::setDateTimeToThread(QDateTime dateTime) {
    qDebug()<<"setDateTimeToThread" + dateTime.toString();
    thrInput.setDateTime(dateTime);
}

/**
 * MainWindow 
 * 
 * Sends the date and time to the main screen class
 *
 * @param  {QDateTime} dateTime : Date and time to set
 */
void MainWindow::setDateTime(QDateTime dateTime){
    if(main_screen){
        main_screen->setDate(dateTime.date());
        main_screen->setTime(dateTime.time());
    }
}

/**
 * MainWindow 
 * 
 * * Testing purposes 
 * Sends a random oxygen value to the main screen class
 */
void MainWindow::setRandomValue(){
    double x = QRandomGenerator::global()->generateDouble() * 100;
    qDebug()<<"Random" << x;
    if(main_screen){
        main_screen->setOxygenValue(x);
    }
}
