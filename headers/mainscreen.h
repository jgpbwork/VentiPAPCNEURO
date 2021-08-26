/**
 * Created by Ing. Luis Alejandro Reyes Morales on 8/12/2020.
 *
 * email: inglreyesm@gmail.com
 * github: https://github.com/lreyesm
 * linkedin: https://linkedin.com/in/luis-alejandro-reyes-morales-9b672012a
 *
 */


#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QWidget>
#include <QDateTime>
#include "mainmenu.h"
#include "ThrAlarm.h"
#include "ThrInput.h"
#include <QTimer>

#define MIX_OXY_ALLOWED 17
#define MAX_OXY_ALLOWED 105
#define BLINK_INTERVAL 500 //ms
namespace Ui
{
    class MainScreen;
}

class MainScreen : public QWidget
{
    Q_OBJECT

public:
    explicit MainScreen(QWidget *parent = nullptr);
    ~MainScreen();

    void setOxygenImage(QString image);
    void setValueText(QString text);
    void setLBatteryText(QString text);
    void emitAlarm(bool);

    void setRemainingTime(double);
public slots:
    void checkFontOfDisplay(double value);
    void checkFontOfDisplay(QString text);
    void setOxygenValue(double value);
    void setDate(QDate date);
    void setTime(QTime time);

    void setBlockedDisplayValue(bool b) { blockedDisplayValue = b; }
    bool getBlockedDisplayValue() { return blockedDisplayValue; }

    void setBatteryChargeLevel(int value);
    void setBatteryConnectionState(double value);
    void setConnectionState(bool state);
    void onBatteryFull();
    void setBatteryPercentile(double);
    void showShutdownDialog(void)

signals:
    void menu_clicked();
    void alarmOn();
    void alarmOff();
    void alarmType(ThrAlarm::AlarmPriority);

private slots:
    void emitMenuClicked();

    void hideWidgetMenu();
    void showWidgetMenu();
    void setAlarmLimits();

    void turnOnBlinking();
    void turnOffBlinking();
    void toggleLabelVisibility();
    void setBlinkState(bool);

private:
    Ui::MainScreen *ui;
    MainMenu *main_menu = nullptr;
    bool shownMenu = false;

     // ! this variable controls the displaying of the UI
     // ? if false is control by the main screen else by the calibration screen
    bool blockedDisplayValue = false;
    
    QTimer timerBlink;
    double processBatteryMeasurementValue(double);
    bool batteryFull = false;
    double batteryMaximunDefaultConfiguration = 6500;
    double batteryChargeValue = 0;
    bool lowBattery = false;
    bool lowMediumBattery = false;
    bool badRangeAlarmActive = false;
    bool errorRangeAlarmActive = false;
    double lastRemainingTime = -1;
    double lastRemainingHours = -1000;
    double lastRemainingMinutes = -1000;
};

#endif // MAINSCREEN_H
