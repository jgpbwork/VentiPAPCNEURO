#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QWidget>
#include <QDateTime>
#include "mainmenu.h"

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

public slots:
    void setOxygenValue(double value);
    void setDate(QDate date);
    void setTime(QTime time);

    void setBlockedDisplayValue(bool b){ blockedDisplayValue = b; }
    bool getBlockedDisplayValue(){ return blockedDisplayValue; }

signals:
    void menu_clicked();
    void alarmOn();
    void alarmOff();

private slots:
    void emitMenuClicked();

    void hideWidgetMenu();
    void showWidgetMenu();
    void setAlarmLimits();
private:
    Ui::MainScreen *ui;
    MainMenu *main_menu = nullptr;
    bool shownMenu =false;
    bool blockedDisplayValue = false;
};

#endif // MAINSCREEN_H
