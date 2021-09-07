#ifndef THRINPUT_H
#define THRINPUT_H

#include <QtCore>
#include <QObject>
#include <QThread>

#include "Singleton.h"
#include "DrvAdc.h"
#include "DrvRtc.h"
#include "DrvGauge.h"
#include "DrvGpio.h"

#define MAX_COUNT 30
#define SHUTDOWN_BUTTON_GPIO 7

class ThrInput : public QObject,
                 public Singleton<ThrInput>
{
    Q_OBJECT
    static const std::uint8_t MAX_AVERAGE = 5;
public:
    explicit ThrInput(QObject *parent = nullptr);

    ~ThrInput();

    void deviceInit();
    bool deviceConfigure();
    void validateReading();

    bool setDateTime(QDateTime);

    QDateTime& getDateTime();

    QThread &getThreadInstance();

signals:
    void updateOxygenLevel(double);
    void updateBatteryCharge(double);/// not needed;
    void batteryChargeLevel(int);
    void batteryFull(void);
    void shutdownSignalArrived(void);

    void updateBatteryVoltage(QString);
    void updateRealTimeClock(QDateTime);

    void inRange();
    void outOfRange();

public slots:      
    void updateReadings(std::float_t oxygenVal, std::float_t battVoltage);
    void updateDateTime(QDateTime &refValue);
    void setMinimumValue(const QString &value);
    void setMaximumValue(const QString value);

private slots:
    void emitInitialBatteryChargeValue();
private:
    QThread* qThrInput_;    

    QString portName_;

    ADS1115 drvAdc;
    DS1307 drvRtc;
    LTC2942 drvBattGauge;
    DrvGpio offSignal;

    std::float_t minVal;
    std::float_t maxVal;
    std::float_t lastReading;

    std::array<std::uint16_t, MAX_AVERAGE> readings;

    int currentBattCharge = 0;

    [[noreturn]] static void ThrInputRun();

    void processReadings(void);
};

inline QThread& ThrInput::getThreadInstance() {
    return *this->qThrInput_;
}

inline QDateTime& ThrInput::getDateTime(){
    return this->drvRtc.getDateTime();
}
#endif // THRINPUT_H
