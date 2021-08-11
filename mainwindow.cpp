#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QRandomGenerator>
#include <QDebug>
#include <QDesktopWidget>

// TODO:
// ** General screnn **
// Disable de lenguage button and battery state
// Add about equipment screen

// Define alarm limit, min and mas
// Default Date and time July, 31 2021 15:00
// Disable am/pm button
//

// Define signals
// Turn off/on
// Alarm Type (high, medium)
//

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
            << "151" 
            << "********************************";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initApp(){
    this->setStyleSheet("");
    if(main_screen){
        main_screen->show();
    }
}

void MainWindow::alarmType(ThrAlarm::AlarmPriority type) {
    this->thrAlarm.setAlarmType(type);
}

void MainWindow::alarmOn() {
    this->thrAlarm.alarmOn();
}

void MainWindow::alarmOff() {
    this->thrAlarm.alarmOff();
}

void MainWindow::setOxygenValue(double value){
    if(main_screen){
        main_screen->setOxygenValue(value);
    }
}

void MainWindow::setDateTimeToThread(QDateTime dateTime) {
    qDebug()<<"setDateTimeToThread" + dateTime.toString();
    thrInput.setDateTime(dateTime);
}

void MainWindow::setDateTime(QDateTime dateTime){
    if(main_screen){
        main_screen->setDate(dateTime.date());
        main_screen->setTime(dateTime.time());
    }
}

void MainWindow::setRandomValue(){
    double x = QRandomGenerator::global()->generateDouble() * 100;
    qDebug()<<"Random" << x;
    if(main_screen){
        main_screen->setOxygenValue(x);
    }
}
