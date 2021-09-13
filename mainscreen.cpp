/**
 * Created by Ing. Luis Alejandro Reyes Morales on 8/12/2020.
 *
 * email: inglreyesm@gmail.com
 * github: https://github.com/lreyesm
 * linkedin: https://linkedin.com/in/luis-alejandro-reyes-morales-9b672012a
 *
 */

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

/**
 * MainScreen
 *
 * Constructor of the class 
 * This class is the main controller of the UI elements of application
 * Sets the initial state of the application's UI 
 * Connect signals of alarm sendded to main window class
 * Load the saved data of application (calibration and other configurations)
 * Checks for the correct state the I2C driver (RTC, Oxygen Sensor)
 *
 * @param  {parent} undefined                        : 
 * @return {MainScreen::MainScreen(QWidgetparent)*}  : 
 */
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
        QStringList not_contains;
        if (!(answer.contains("48") || answer.contains("49")))
        {
            not_contains << "48 o 49";
        }
        if (!(answer.contains("64")))
        {
            not_contains << "64";
        };
        if (!(answer.contains("68")))
        {
            not_contains << "68";
        };

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

/**
 * MainScreen :: showShutdownDialog
 * 
 * Shows a shutdown dialog when shutdown button is pressed
 *
 * @param  {void} undefined : Receives nothing
 */
void MainScreen::showShutdownDialog(void){
    QString mess = "       Apagando equipo ...";
    QWidget * w = GlobalFunctions::setWarningMessage(this, mess);
    QTimer::singleShot(5000, w, &QWidget::close);
}

/**
 * MainScreen 
 * 
 * This function is a slot listening to battery change signal on sensor thread
 * Sets the battery level on the UI after processing the value between (65535 - MIN_BATTERY_LEVEL)
 *
 * @param  {int} value : Value of battery level received between (65535 - MIN_BATTERY_LEVEL)
 */
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
            setBatteryPercentile(porcentile);
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
                setBatteryPercentile(porcentile);

                setRemainingTime(difference);
            }
            setBatteryConnectionState(difference);
        }
    }
}

/**
 * MainScreen 
 * 
 * Displays the current battery level value in porcentile 
 * Displays the right battery icon for the current battery level
 *
 * @param  {double} value : 
 */
void MainScreen::setBatteryPercentile(double value)
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

/**
 * MainScreen 
 * 
 * Checks if difference of lectures received from sensor is positive or negative
 * if positive sets the right icon in UI, it means it's charching and turns off the low battery alarm
 * and hides the display of the porcentile and remaining time
 * if negative it means is discharging and shows the display of the porcentile and remaining time
 *
 * @param  {double} value : Value of the difference of lectures received from sensor
 */
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
        if (!badRangeAlarmActive && !errorRangeAlarmActive)
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

/**
 * MainScreen 
 * 
 * Displays the remaining time in the UI with the difference of battery level readings
 * Sets the right alarm if needs to be active and the correct icons
 *
 * @param  {double} difference : Value of the difference of lectures received from sensor
 */
void MainScreen::setRemainingTime(double difference)
{
    double remainingTime = (((GlobalFunctions::lastBatteryLevel - MIN_BATTERY_LEVEL) / abs(difference)) * MAX_COUNT); //seg
    int hours = static_cast<int>(remainingTime / 3600);
    double minutes = (remainingTime - (hours * 3600)) / 60;
    if (lastRemainingTime > remainingTime || lastRemainingTime < 0)
    {
        lastRemainingTime = remainingTime;
        lastRemainingMinutes = minutes;
        lastRemainingHours = hours;
        QString remainingString = (((hours > 0) ? QString::number(hours) + "h" : "") + " " + ((minutes > 0) ? QString::number(minutes, 'f', 0) + "min" : "")).trimmed();
        setLBatteryText(remainingString);
    }
    if (lastRemainingHours <= 0)
    {
        int value = qRound(lastRemainingMinutes);
        if (value <= 10 && value > 5)
        {
            ui->l_battery_icon->setPixmap(QPixmap(":icons/general/battery_medium.png"));
            lowMediumBattery = true;
            emit alarmType(ThrAlarm::P_MEDIUM);
            emit alarmOn();
        }
        else if (value <= 5 && value != 0)
        {
            ui->l_battery_icon->setPixmap(QPixmap(":icons/general/battery_low.png"));
            lowBattery = true;
            emit alarmType(ThrAlarm::P_HIGH);
            emit alarmOn();
        }
        else if (value <= 0)
        {
            ui->l_battery_icon->setPixmap(QPixmap(":icons/general/battery_empty.png"));
            lowBattery = true;
            emit alarmType(ThrAlarm::P_HIGH);
            emit alarmOn();
        }
        else
        {
            lowMediumBattery = false;
            lowBattery = false;
            if (!badRangeAlarmActive && !errorRangeAlarmActive)
            {
                emit alarmOff();
            }
        }
    }
    else
    {
        lowMediumBattery = false;
        lowBattery = false;
        if (!badRangeAlarmActive && !errorRangeAlarmActive)
        {
            emit alarmOff();
        }
    }
}

/**
 * MainScreen 
 * 
 * Shows or hides the lightning icon depending on the current state
 *
 * @param  {bool} state : Current state to set
 */
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

/**
 * MainScreen 
 * 
 * Slot listening the battery full signal
 * if active sets the battery's alarm off and the correct icon
 */
void MainScreen::onBatteryFull()
{
    ui->l_battery_icon->setPixmap(QPixmap(":icons/general/battery_100.png"));
    batteryFull = true;

    lowBattery = false;
    lowMediumBattery = false;

    if (!badRangeAlarmActive && !errorRangeAlarmActive)
    {
        emit alarmOff();
    }
}

/**
 * MainScreen 
 * 
 * Turns on the blinking of the UI (oxygen value label and battery icon)
 */
void MainScreen::turnOnBlinking()
{
    setBlinkState(true);
}

/**
 * MainScreen 
 * 
 * Turns off the blinking of the UI (oxygen value label and battery icon)
 */
void MainScreen::turnOffBlinking()
{
    setBlinkState(false);
}

/**
 * MainScreen 
 * 
 * This function is a slot listening the timer for blinking the UI 
 * Toggle the showing state of the UI (oxygen value label and battery icon)
 * Hide intervals are shorter than show intervals
 */
void MainScreen::toggleLabelVisibility()
{
    bool shortInterval = false;
    if (errorRangeAlarmActive || badRangeAlarmActive)
    {
        if (ui->l_oxygen_value->isHidden())
        {
            ui->l_oxygen_value->show();
        }
        else
        {
            shortInterval = true;
            ui->l_oxygen_value->hide();
        }
    }
    if (lowMediumBattery || lowBattery)
    {
        if (ui->l_battery_icon->isHidden())
        {
            ui->l_battery_icon->show();
        }
        else
        {
            shortInterval = true;
            ui->l_battery_icon->hide();
        }
    }
    if (shortInterval)
    {
        timerBlink.stop();
        timerBlink.setInterval(BLINK_INTERVAL);
        timerBlink.start();
    }
    else
    {
        timerBlink.stop();
        timerBlink.setInterval(BLINK_INTERVAL * 4);
        timerBlink.start();
    }
}

/**
 * MainScreen 
 * 
 * Sets the blinking state of the UI,
 * Start or stop the timer for blinking the UI
 *
 * @param  {bool} active : Current blinking state
 */
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
        ui->l_battery_icon->show();
    }
}

/**
 * MainScreen 
 * 
 * Sets the alarm limits configured in alarm widget on the UI
 */
void MainScreen::setAlarmLimits()
{
    ui->l_min_value->setText(QString::number(GlobalFunctions::configured_min_limit));
    ui->l_max_value->setText(QString::number(GlobalFunctions::configured_max_limit));
}

/**
 * MainScreen 
 *
 * Sets the date configured in date time widget on the UI 
 *
 * @param  {QDate} date : 
 */
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

/**
 * MainScreen 
 *
 * Sets the time configured in date time widget on the UI 
 *
 * @param  {QDate} date : 
 */
void MainScreen::setTime(QTime time)
{
    if (time.isValid())
    {
        ///set label
        ui->l_time->setText(time.toString("hh:mm"));
    }
}

/**
 * MainScreen 
 * 
 * Emit the alarm to the main window
 *
 * @param  {bool} active : Current state of the alarm 
 */
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

/**
 * MainScreen 
 * 
 * ! This is an imported function
 * Receives the current oxygen value sendded by the oxygen's sensor
 * Sets the oxygen value to a global variable used on other classes
 * Proccesses the oxygen receive value if a calibration exists
 * Starts or turns off the alarm of oxygen default and configured limits
 * Displays the processed oxygen value on the UI
 *
 * @param  {double} value : 
 */
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

/**
 * MainScreen 
 * 
 * Checks the size of the string to display and sets the right font size
 * to prevent the overflow of the label in the UI
 *
 * @param  {double} value : Oxygen value received to display
 */
void MainScreen::checkFontOfDisplay(double value)
{
    checkFontOfDisplay(QString::number(qRound(value)));
}


/**
 * MainScreen 
 * 
 * Checks the size of the string to display and sets the right font size
 * to prevent the overflow of the label in the UI
 *
 * @param  {double} value : Oxygen value received to display
 */
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

/**
 * MainScreen 
 * 
 * Displays the remaining time of the battery on the UI
 *
 * @param  {QString} text : Text of the remaining time value to display
 */
void MainScreen::setLBatteryText(QString text)
{
    ui->l_battery_text->setText(text);
    ui->l_battery_text->raise();
}

/**
 * MainScreen 
 * 
 * ! This function is slot listening the calibration class
 * Displays the oxygen value on the UI, change the controller
 * of the display to the calibration class
 *
 * @param  {QString} text : String value to display on the UI
 */
void MainScreen::setValueText(QString text)
{
    blockedDisplayValue = true; // ! this variable controls the displaying of the UI
    ui->l_oxygen_value->setText(text);
    ui->l_oxygen_value->raise();
}

/**
 * MainScreen 
 * 
 * ! This function is slot listening the calibration class
 * Displays an image on the UI, change the controller
 * of the display to the calibration class
 *
 * @param  {QString} text : String value to display on the UI
 */
void MainScreen::setOxygenImage(QString image)
{
    blockedDisplayValue = true; // ! this variable controls the displaying of the UI
    qDebug() << "image" << image;
    ui->l_oxygen_value->setPixmap(QPixmap(image));
    ui->widget_o2_porcentile_mini->hide();
    ui->l_oxygen_value->raise();
}

/**
 * MainScreen 
 * 
 * Emits a click event to the main screen class
 */
void MainScreen::emitMenuClicked()
{
    emit menu_clicked();
}

/**
 * MainScreen 
 * 
 * Shows the main menu and shortens the oxygen display value on the UI 
 */
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

/**
 * MainScreen 
 * 
 * Hides the main menu and expands the oxygen display value on the UI 
 */
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
