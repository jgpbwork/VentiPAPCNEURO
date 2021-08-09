#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QWidget>
#include <QDateTime>
#include "mainmenu.h"
#include "ThrAlarm.h"
#include <QTimer>

#define MIX_OXY_ALLOWED 17
#define MAX_OXY_ALLOWED 105

namespace Ui {
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

public slots:
    void checkFontOfDisplay(double value);
    void checkFontOfDisplay(QString text);
    void setOxygenValue(double value);
    void setDate(QDate date);
    void setTime(QTime time);

    void setBlockedDisplayValue(bool b){ blockedDisplayValue = b; }
    bool getBlockedDisplayValue(){ return blockedDisplayValue; }

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
    bool shownMenu =false;
    bool blockedDisplayValue = false;
    QTimer timerBlink;
};

#endif // MAINSCREEN_H
