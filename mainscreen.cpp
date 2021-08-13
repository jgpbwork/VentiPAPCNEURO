#include "mainscreen.h"
#include "DrvGauge.h"
#include "ui_mainscreen.h"
#include <QDebug>
#include "globalfunctions.h"
#include "processesclass.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QPlainTextEdit>
#include <QGraphicsDropShadowEffect>

MainScreen::MainScreen(QWidget *parent) : QWidget(parent),
                                          ui(new Ui::MainScreen)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint);

    ui->l_error_text->hide();
    ui->l_lightning->hide();

    main_menu = new MainMenu(this);
    main_menu->hide();
    shownMenu = false;

    connect(main_menu, &MainMenu::menu_clicked,
            this, &MainScreen::hideWidgetMenu);
    connect(ui->widget_menu_off, &MyWidgetAnimated::clicked,
            this, &MainScreen::showWidgetMenu);

    connect(main_menu, &MainMenu::alarmLimitSetted,
            this, &MainScreen::setAlarmLimits);

    connect(this, &MainScreen::alarmOn,
            this, &MainScreen::turnOnBlinking);
    connect(this, &MainScreen::alarmOff,
            this, &MainScreen::turnOffBlinking);

    ui->widget_o2_porcentile_mini->hide();

    QString answer_shutdown = ProcessesClass::
        executeProcess(this, "sudo python /home/pi/VentiApp/scripts/shutdownbuttons.py &",
                       ProcessesClass::LINUX, 1000, true);
    if (!GlobalFunctions::loadData())
    {
        QString mess = "Error"
                       "Calibracion no encontrada. Reintente calibracion";
        GlobalFunctions::setWarningMessage(this, mess);
    }

    QString answer = ProcessesClass::executeProcess(this, "sudo i2cdetect -y 1",
                                                    ProcessesClass::LINUX, 1000, true);

    if ((answer.contains("48") || answer.contains("49")) &&
        answer.contains("64") &&
        answer.contains("68"))
    {
        qDebug() << "Debug answer" << answer;
    }
    else
    {
        qDebug() << "answer" << answer;
        QString mess = "Reinicie el equipo. Si persiste "
                       "el error, contacte a soportetecnico@cneuro.cu";
        GlobalFunctions::setErrorMessage(this, mess);
    }

    batteryMaximunDefaultConfiguration = GlobalFunctions::loadBatteryConfiguration() * 3.6 - 300;
    batteryChargeValue = batteryMaximunDefaultConfiguration;
}

MainScreen::~MainScreen()
{
    delete ui;
}

void MainScreen::setBatteryChargeLevel(int value)
{
    int maxBatteryLevel = std::numeric_limits<std::uint16_t>::max();
    if (value == maxBatteryLevel)
    {
        onBatteryFull();
    }
    else
    {
        if (GlobalFunctions::lastBatteryLevel == -1)
        {
            GlobalFunctions::lastBatteryLevel = value;
            double variation = static_cast<std::double_t>((value - MIN_BATTERY_LEVEL)) / static_cast<std::double_t>((maxBatteryLevel - MIN_BATTERY_LEVEL));
            double porcentile = 100.0f * variation;
            setBatteryPorcentile(porcentile);
            return;
        }

        int difference = value - GlobalFunctions::lastBatteryLevel; //? positive charging else disconnected

        if (difference != 0)
        {
            //            double processedValue = LTC2942::CHARGE_COULOMB_RATIO_M64 * difference;
            GlobalFunctions::lastBatteryLevel = value;
            if (difference < 0)
            {
                double variation = static_cast<std::double_t>((value - MIN_BATTERY_LEVEL)) / static_cast<std::double_t>((maxBatteryLevel - MIN_BATTERY_LEVEL));
                double porcentile = 100.0f * variation;
                setBatteryPorcentile(porcentile);

                setRemainingTime(difference);
            }
            setBatteryConnectionState(difference);
        }
    }
}

void MainScreen::setBatteryPorcentile(double value)
{
    if (value >= 0)
    { //processedValue is a value between 0 and 100
        int batteryValue = qRound(value / 25) * 25;
        ui->l_battery_icon->setPixmap(QPixmap(":icons/general/battery_" + QString::number(batteryValue) + ".png"));
        ui->l_battery_value->setText(QString::number(value, 'f', 0) + "%");
    }
    else
    {
        return;
    }
}

void MainScreen::setBatteryConnectionState(double value)
{
    //process value here
    if (value >= 0)
    {
        setConnectionState(true);
        ui->l_battery_value->hide();
        ui->l_battery_text->hide();
        ui->l_battery_icon->setPixmap(QPixmap(":icons/general/battery_100.png"));
        lowBattery = false;
        lowMediumBattery = false;
        if (!badRangeAlarmActive && errorRangeAlarmActive)
        {
            emit alarmOff();
        }
    }
    else
    {
        setConnectionState(false);
        ui->l_battery_value->show();
        ui->l_battery_text->show();
    }
}

void MainScreen::setRemainingTime(double difference)
{
    double remainingTime = (((GlobalFunctions::lastBatteryLevel - MIN_BATTERY_LEVEL) / abs(difference)) * MAX_COUNT); //seg
    if (lastRemainingTime > remainingTime || lastRemainingTime < 0)
    {
        lastRemainingTime = remainingTime;
        int hours = static_cast<int>(remainingTime / 3600);
        double minutes = (remainingTime - (hours * 3600)) / 60;
        QString remainingString = (((hours > 0) ? QString::number(hours) + "h" : "") + " " + ((minutes > 0) ? QString::number(minutes, 'f', 0) + "min" : "")).trimmed();
        setLBatteryText(remainingString);
    }
    if (h <= 0)
    {
        int value = static_cast<int>(minutes);
        if (value <= 10 && value > 5)
        {
            ui->l_battery_icon->setPixmap(QPixmap(":icons/general/battery_medium.png"));
            lowMediumBattery = true;
            emit alarmType(ThrAlarm::P_MEDIUM);
            emit alarmOn();
        }
        else if (value <= 5)
        {
            ui->l_battery_icon->setPixmap(QPixmap(":icons/general/battery_low.png"));
            lowBattery = true;
            emit alarmType(ThrAlarm::P_HIGH);
            emit alarmOn();
        }
        else
        {
            lowMediumBattery = false;
            lowBattery = false;
            emit alarmOff();
        }
    }
}

void MainScreen::setConnectionState(bool state)
{
    if (state)
    {
        ui->l_lightning->show();
    }
    else
    {
        ui->l_lightning->hide();
    }
}

void MainScreen::onBatteryFull()
{
    ui->l_battery_icon->setPixmap(QPixmap(":icons/general/battery_100.png"));
    batteryFull = true;
}

void MainScreen::turnOnBlinking()
{
    setBlinkState(true);
}
void MainScreen::turnOffBlinking()
{
    setBlinkState(false);
}

void MainScreen::toggleLabelVisibility()
{
    if (ui->l_oxygen_value->isHidden())
    {
        timerBlink.stop();
        timerBlink.setInterval(BLINK_INTERVAL * 4);
        timerBlink.start();
        ui->l_oxygen_value->show();
    }
    else
    {
        timerBlink.stop();
        timerBlink.setInterval(BLINK_INTERVAL);
        timerBlink.start();
        ui->l_oxygen_value->hide();
    }
}

void MainScreen::setBlinkState(bool active)
{
    if (active)
    {
        timerBlink.setInterval(BLINK_INTERVAL);
        connect(&timerBlink, &QTimer::timeout, this, &MainScreen::toggleLabelVisibility);
        timerBlink.start();
    }
    else
    {
        timerBlink.stop();
        disconnect(&timerBlink, &QTimer::timeout, this, &MainScreen::toggleLabelVisibility);
        ui->l_oxygen_value->show();
    }
}

void MainScreen::setAlarmLimits()
{
    ui->l_min_value->setText(QString::number(GlobalFunctions::configured_min_limit));
    ui->l_max_value->setText(QString::number(GlobalFunctions::configured_max_limit));
}

void MainScreen::setDate(QDate date)
{
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

    for (int i = 0; i < mapDays.size(); i++)
    {
        QString key = mapDays.keys().at(i);
        if (dateString.contains(key, Qt::CaseInsensitive))
        {
            dateString = dateString.toUpper().replace(key, mapDays.value(key));
        }
    }
    for (int i = 0; i < mapMonth.size(); i++)
    {
        QString key = mapMonth.keys().at(i);
        if (dateString.contains(key, Qt::CaseInsensitive))
        {
            dateString = dateString.toUpper().replace(key, mapMonth.value(key));
        }
    }

    if (date.isValid())
    {
        ///set label_2
        ui->l_date->setText(dateString);
    }
}

void MainScreen::setTime(QTime time)
{
    if (time.isValid())
    {
        ///set label
        ui->l_time->setText(time.toString("hh:mm"));
    }
}

void MainScreen::emitAlarm(bool active)
{
    if (active)
    {
        emit alarmOn();
    }
    else
    {
        emit alarmOff();
    }
}

void MainScreen::setOxygenValue(double value)
{
    GlobalFunctions::lastSettedValue = value;
    //        setLBatteryText(QString::number(value, 'f', 6));

    if (blockedDisplayValue)
    {
        return;
    }
    value = GlobalFunctions::getRealValue(value);
    value = static_cast<std::double_t>(qRound(value));

    if (value < MIX_OXY_ALLOWED || value > MAX_OXY_ALLOWED)
    {

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
        emit alarmType(ThrAlarm::P_HIGH);
        errorRangeAlarmActive = true;
        emit alarmOn();
        checkFontOfDisplay(value);

        ui->l_oxygen_value->setText(QString::number(qRound(value)));

        return;
    }
    else
    {
        ui->l_oxygen_value->setScaledContents(true);
        ui->l_error_text->hide();
        ui->widget_min_value->show();
        ui->widget_max_value->show();
        errorRangeAlarmActive = false;
        if (!lowBattery && !lowMediumBattery)
        {
            emit alarmOff();
        }
        if (shownMenu)
        {
            ui->widget_o2_porcentile_mini->show();
        }
        else
        {
            ui->widget_o2_porcentile->show();
        }
        QString style = ui->l_oxygen_value->styleSheet();
        style.remove("color: rgb(239, 50, 50);");
        ui->l_oxygen_value->setStyleSheet(style);
    }
    ///TODO if Value is out or Range, start alarm process
    /// if Value is in Range, stop alarm process

    if (value < GlobalFunctions::configured_min_limit || value > GlobalFunctions::configured_max_limit)
    {
        ///TODO emit signal Alarm On
        if (!lowBattery)
        {
            badRangeAlarmActive = true;
            emit alarmOn();
            emit alarmType(ThrAlarm::P_MEDIUM);
        }
        QString style = ui->l_oxygen_value->styleSheet();
        style += "color: rgb(239, 169, 3);";
        ui->l_oxygen_value->setStyleSheet(style);
    }
    else
    {
        badRangeAlarmActive = false;
        ///TODO emit signal Alarm Off
        if (!lowBattery && !lowMediumBattery)
        {
            emit alarmOff();
        }
        QString style = ui->l_oxygen_value->styleSheet();
        style.remove("color: rgb(239, 169, 3);");
        ui->l_oxygen_value->setStyleSheet(style);
    }
    checkFontOfDisplay(value);

    ui->l_oxygen_value->setText(QString::number(qRound(value)));
    GlobalFunctions::lastSettedValue = value;
}

void MainScreen::checkFontOfDisplay(double value)
{
    checkFontOfDisplay(QString::number(qRound(value)));
}
void MainScreen::checkFontOfDisplay(QString text)
{
    if (text.size() >= 3)
    {
        QFont f = ui->l_oxygen_value->font();
        if (shownMenu)
        {
            f.setPointSize(24);
        }
        else
        {
            f.setPointSize(118);
        }
        ui->l_oxygen_value->setFont(f);
    }
    else
    {
        QFont f = ui->l_oxygen_value->font();
        if (shownMenu)
        {
            f.setPointSize(50);
        }
        else
        {
            f.setPointSize(180);
        }
        ui->l_oxygen_value->setFont(f);
    }
}

void MainScreen::setLBatteryText(QString text)
{
    ui->l_battery_text->setText(text);
    ui->l_battery_text->raise();
}
void MainScreen::setValueText(QString text)
{
    blockedDisplayValue = true;
    ui->l_oxygen_value->setText(text);
    ui->l_oxygen_value->raise();
}
void MainScreen::setOxygenImage(QString image)
{
    blockedDisplayValue = true;
    qDebug() << "image" << image;
    ui->l_oxygen_value->setPixmap(QPixmap(image));
    ui->widget_o2_porcentile_mini->hide();
    ui->l_oxygen_value->raise();
}

void MainScreen::emitMenuClicked()
{
    emit menu_clicked();
}
void MainScreen::showWidgetMenu()
{
    if (main_menu != nullptr)
    {

        shownMenu = true;

        main_menu->move(0, 135);
        main_menu->showMenu();

        ui->l_oxygen_value->move(125, 70);
        ui->l_oxygen_value->setFixedSize(70, 70);
        checkFontOfDisplay(ui->l_oxygen_value->text());
        ui->widget_o2_porcentile_mini->show();
        ui->widget_max_value->hide();
        ui->widget_o2_porcentile->hide();
    }
}
void MainScreen::hideWidgetMenu()
{
    if (main_menu != nullptr)
    {
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
