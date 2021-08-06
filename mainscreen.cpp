#include "mainscreen.h"
#include "ui_mainscreen.h"
#include <QDebug>
#include "globalfunctions.h"
#include "processesclass.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QPlainTextEdit>
#include <QGraphicsDropShadowEffect>

MainScreen::MainScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainScreen)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint);

    ui->l_error_text->hide();
    ui->l_lightning->hide();
    ui->l_battery_text->hide();

    main_menu = new MainMenu(this);
    main_menu->hide();
    shownMenu = false;

    connect(main_menu, &MainMenu::menu_clicked,
            this, &MainScreen::hideWidgetMenu);
    connect(ui->widget_menu_off, &MyWidgetAnimated::clicked,
            this, &MainScreen::showWidgetMenu);

    connect(main_menu, &MainMenu::alarmLimitSetted,
            this, &MainScreen::setAlarmLimits);

    ui->widget_o2_porcentile_mini->hide();

    QString answer_shutdown = ProcessesClass::
            executeProcess(this,"sudo python /home/pi/VentiApp/scripts/shutdownbuttons.py &",
                           ProcessesClass::LINUX, 1000, true);
    if(!GlobalFunctions::loadData()){
        QString mess = "Error"
                       "Calibracion no encontrada. Reintente calibracion";
        GlobalFunctions::setWarningMessage(this, mess);
    }

    QString answer = ProcessesClass::executeProcess(this, "sudo i2cdetect -y 1",
                                                    ProcessesClass::LINUX, 1000, true);

    if( (answer.contains("48") || answer.contains("49")) && 
        answer.contains("64") && 
        answer.contains("68")) {
        qDebug()<<"Debug answer"<<answer;
    }
    else{
        qDebug()<<"answer"<<answer;
        QString mess = "Reinicie el equipo. Si persiste "
                       "el error, contacte a soportetecnico@cneuro.cu";
        GlobalFunctions::setErrorMessage(this, mess);
    }
}

MainScreen::~MainScreen()
{
    delete ui;
}

void MainScreen::setAlarmLimits(){
    ui->l_min_value->setText(QString::number(GlobalFunctions::configured_min_limit));
    ui->l_max_value->setText(QString::number(GlobalFunctions::configured_max_limit));
}

void MainScreen::setDate(QDate date){
    QMap<QString, QString> mapMonth;
    QMap<QString, QString> mapDays;

    QString dateString = date.toString();

    mapMonth.insert("JAN", "ENE");
    mapMonth.insert("FEB", "FEB");
    mapMonth.insert("MAR", "MAR");
    mapMonth.insert("APR", "ABR");
    mapMonth.insert("MAY", "MAY");
    mapMonth.insert("JUN", "JUN");
    mapMonth.insert("JUL", "JUL");
    mapMonth.insert("AUG", "AGO");
    mapMonth.insert("SEP", "SEP");
    mapMonth.insert("OCT", "OCT");
    mapMonth.insert("NOV", "NOV");
    mapMonth.insert("DEC", "DIC");

    mapDays.insert("MON", "LUN");
    mapDays.insert("TUE", "MAR");
    mapDays.insert("WED", "MIE");
    mapDays.insert("THU", "JUE");
    mapDays.insert("FRI", "VIE");
    mapDays.insert("SAT", "SÁB");
    mapDays.insert("SUN", "DOM");

    for (int i = 0; i < mapDays.size(); i++) {
        QString key = mapDays.keys().at(i);
        if(dateString.contains(key, Qt::CaseInsensitive)) {
            dateString = dateString.toUpper().replace(key, mapDays.value(key));
        }
    }
    for (int i = 0; i < mapMonth.size(); i++) {
        QString key = mapMonth.keys().at(i);
        if(dateString.contains(key, Qt::CaseInsensitive)) {
            dateString = dateString.toUpper().replace(key, mapMonth.value(key));
        }
    }

    if(date.isValid()){
        ///set label_2
        ui->l_date->setText(dateString);
    }
}

void MainScreen::setTime(QTime time){
    if(time.isValid()){
        ///set label
        ui->l_time->setText(time.toString("hh:mm"));
    }
}

void MainScreen::emitAlarm(bool active){
    if(active) {
        emit alarmOn();
    }
    else {
        emit alarmOff();
    }
}

void MainScreen::setOxygenValue(double value)
{
    GlobalFunctions::lastSettedValue = value;
        setLBatteryText(QString::number(value, 'f', 6));

    if(blockedDisplayValue){
        return;
    }
    value = GlobalFunctions::getRealValue(value);

    value = static_cast<int>(value);

    if(value < MIX_OXY_ALLOWED || value > MAX_OXY_ALLOWED){
        
            //            ui->l_oxygen_value->setPixmap(QPixmap(":icons/general/alarm_icon.png"));
            ui->l_oxygen_value->setScaledContents(true);

            QString style = ui->l_oxygen_value->styleSheet();
            style += "color: rgb(239, 50, 50);";
            ui->l_oxygen_value->setStyleSheet(style);

            ui->l_error_text->show();
            ui->widget_min_value->hide();
            ui->widget_max_value->hide();
            ui->widget_o2_porcentile_mini->hide();
            ui->widget_o2_porcentile->hide();
            emit alarmOn();
            emit alarmType(ThrAlarm::P_HIGH);
            checkFontOfDisplay(value);

            ui->l_oxygen_value->setText(QString::number(value, 'f', 0));
        
        return;
    }
    else{
        ui->l_oxygen_value->setScaledContents(true);
        ui->l_error_text->hide();
        ui->widget_min_value->show();
        ui->widget_max_value->show();
        emit alarmOff();
        if(shownMenu) {
            ui->widget_o2_porcentile_mini->show();
        }
        else {
            ui->widget_o2_porcentile->show();
        }
        QString style = ui->l_oxygen_value->styleSheet();
        style.remove("color: rgb(239, 50, 50);");
        ui->l_oxygen_value->setStyleSheet(style);

    }
    ///TODO if Value is out or Range, start alarm process
    /// if Value is in Range, stop alarm process

    if(value < GlobalFunctions::configured_min_limit
            || value > GlobalFunctions::configured_max_limit){
        ///TODO emit signal Alarm On
        emit alarmOn();
        emit alarmType(ThrAlarm::P_MEDIUM);
        QString style = ui->l_oxygen_value->styleSheet();
        style += "color: rgb(239, 169, 3);";
        ui->l_oxygen_value->setStyleSheet(style);
    }
    else{
        ///TODO emit signal Alarm Off
        emit alarmOff();
        QString style = ui->l_oxygen_value->styleSheet();
        style.remove("color: rgb(239, 169, 3);");
        ui->l_oxygen_value->setStyleSheet(style);
    }

    checkFontOfDisplay(value);

    ui->l_oxygen_value->setText(QString::number(value, 'f', 0));
    GlobalFunctions::lastSettedValue = value;
    
}

void MainScreen::checkFontOfDisplay(double value){
    checkFontOfDisplay(QString::number(value, 'f', 0));
}
void MainScreen::checkFontOfDisplay(QString text){
    if(text.size() >= 3){
        QFont f = ui->l_oxygen_value->font();
        if(shownMenu){
            f.setPointSize(24);
        }
        else{
            f.setPointSize(118);
        }
        ui->l_oxygen_value->setFont(f);
    }
    else{
        QFont f = ui->l_oxygen_value->font();
        if(shownMenu){
            f.setPointSize(50);
        }
        else{
            f.setPointSize(180);
        }
        ui->l_oxygen_value->setFont(f);
    }
}

void MainScreen::setLBatteryText(QString text){
    ui->l_battery_text->setText(text);
    ui->l_battery_text->raise();
}
void MainScreen::setValueText(QString text){
    blockedDisplayValue = true;
    ui->l_oxygen_value->setText(text);
    ui->l_oxygen_value->raise();
}
void MainScreen::setOxygenImage(QString image)
{
    blockedDisplayValue = true;
    qDebug()<<"image"<< image;
    ui->l_oxygen_value->setPixmap(QPixmap(image));
    ui->widget_o2_porcentile_mini->hide();
    ui->l_oxygen_value->raise();
}

void MainScreen::emitMenuClicked()
{
    emit menu_clicked();
}
void MainScreen::showWidgetMenu(){
    if(main_menu != nullptr){

        shownMenu = true;

        main_menu->move(0,135);
        main_menu->showMenu();

        ui->l_oxygen_value->move(125, 70);
        ui->l_oxygen_value->setFixedSize(70, 70);
        checkFontOfDisplay(ui->l_oxygen_value->text());
        ui->widget_o2_porcentile_mini->show();
        ui->widget_max_value->hide();
        ui->widget_o2_porcentile->hide();
    }
}
void MainScreen::hideWidgetMenu(){
    if(main_menu != nullptr){
        main_menu->hideMenu();

        shownMenu = false;
        ui->l_oxygen_value->move(50, 130);
        ui->l_oxygen_value->setFixedSize(221, 221);
        checkFontOfDisplay(ui->l_oxygen_value->text());
        ui->widget_o2_porcentile_mini->hide();
        ui->widget_max_value->show();
        ui->widget_o2_porcentile->show();
    }
}
