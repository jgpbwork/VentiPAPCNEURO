#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QRandomGenerator>
#include <QDebug>
#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if(QApplication::desktop()->width() < 1000){
        this->setCursor(Qt::BlankCursor);
    }
    setWindowFlags(Qt::CustomizeWindowHint);
    this->move(0,0);

    main_screen = new MainScreen(this);
    main_screen->hide();
    QTimer::singleShot(2000, this, &MainWindow::initApp);

    connect(&timer, &QTimer::timeout, this, &MainWindow::setRandomValue);
    timer.setInterval(1000);
    ///TODO Set timer to Turn On and Off Screen every 5 sec. !!!10 Sec off --> 5 Sec on
    /// Set On/Off Time setting adjustable from menu.
//    timer.start();

    connect(&thrInput, &ThrInput::updateOxygenLevel, this, &MainWindow::setOxygenValue);
    connect(&thrInput, &ThrInput::updateRealTimeClock, this, &MainWindow::setDateTime);
    connect(main_screen, &MainScreen::alarmOn, this, &MainWindow::alarmOn);
    connect(main_screen, &MainScreen::alarmOff, this, &MainWindow::alarmOff);

//    connect(this, &MainWindow::alarmOn, &thrAlarm, &ThrAlarm::alarmOn);
//    connect(this, &MainWindow::alarmOff, &thrAlarm, &ThrAlarm::alarmOff);

//    qDebug()<<"Application changes ok" << "66" <<"********************************";
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
    setOxygenValue(20);
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
