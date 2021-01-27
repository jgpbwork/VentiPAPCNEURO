#ifndef OPTIONCALIBRATION_H
#define OPTIONCALIBRATION_H

#include <QWidget>
#include <QJsonArray>
#include <QJsonObject>
#include <QTimer>

#define INIT_MIN_CAL_STATE 2
#define INIT_MAX_CAL_STATE 5

#define CAL_TIME 120*1000 //2min //Unit -> milliseconds
#define CAL_INCREASE_VALUE 1

class MainScreen;

namespace Ui {
class OptionCalibration;
}

class OptionCalibration : public QWidget
{
    Q_OBJECT

public:
    explicit OptionCalibration(QWidget *parent = nullptr);
    ~OptionCalibration();

    QJsonObject getJsonObjectStateInitInformation();
    void setCurrentState(QJsonObject jsonObjectState);
    QJsonObject getJsonObjectStateInitMinCalibration();
    QJsonObject getJsonObjectStateRunningMinCalibration();
    QJsonObject getJsonObjectStateEndedMinCalibration();
    QJsonObject getJsonObjectStateInitMaxCalibration();
    QJsonObject getJsonObjectStateRunningMaxCalibration();
    QJsonObject getJsonObjectStateEndedMaxCalibration();

    QJsonObject getJsonObjectStateEndedCalibration();

    MainScreen *getMainScreenInstance();

    void setMainScreenImage(QString image_name);
    void unBlockDisplayValue();
    QJsonObject getJsonObjectStateErrorCalibration();
    QJsonObject getJsonObjectStateCancelCalibration();
signals:
    void closing();
    void minCalibrationEnded();
    void maxCalibrationEnded();

private slots:
    void on_l_calibration_back_clicked();
    void on_l_calibration_state_button_clicked();

    void on_l_calibration_state_button_out_clicked();

    void on_l_calibration_state_button_repeat_clicked();

    void initMaxCalibration();
    void initMinCalibration();
    void incProgressMinCalibration();
    void incProgressMaxCalibration();
    void navigateNextState();
private:
    Ui::OptionCalibration *ui;
    QJsonObject currentStateJsonObject;
    QJsonArray jsonArrayStates;
    int currentState = 0;
    int minCalibrationProgress = 0;
    int maxCalibrationProgress = 0;
    QTimer minCalTimer, maxCalTimer;

    double minCalValue = -1;
    double maxCalValue = -1;

};

#endif // OPTIONCALIBRATION_H
