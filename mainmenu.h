/**
 * Created by Ing. Luis Alejandro Reyes Morales on 8/12/2020.
 *
 * email: inglreyesm@gmail.com
 * github: https://github.com/lreyesm
 * linkedin: https://linkedin.com/in/luis-alejandro-reyes-morales-9b672012a
 *
 */

#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>

namespace Ui {
class MainMenu;
}

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

    enum{MENU_ALARM_LIMIT = 1, MENU_CALIBRATION, MENU_DATE_TIME, MENU_GENERAL};
signals:
    void menu_clicked();
    void alarmLimitSetted();

public slots:
    void emitClicked();

    void showMenu();
    void animateWidgetDownToUp(QWidget *widget, int anim_time);
    void animateHideWidgetUpToDown(QWidget *widget, int anim_time);
    void hideMenu();
private slots:
    void on_l_date_time_clicked();    
    void on_l_alarm_limit_clicked();
    void on_l_general_clicked();
    void on_l_calibration_clicked();

    void showBackMenu();
    void hideBackMenu();
private:
    Ui::MainMenu *ui;
    int currentMenu = 0;

};

#endif // MAINMENU_H
