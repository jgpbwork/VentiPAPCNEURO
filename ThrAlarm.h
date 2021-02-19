#ifndef THRALARM_H
#define THRALARM_H

#include <QtCore>
#include <QObject>
#include <QThread>

#include "Singleton.h"
#include "Time.h"
#include "DrvGpio.h"

class ThrAlarm : public QObject,
                 public Singleton<ThrAlarm>,
                 public Time
{
    Q_OBJECT
public:
    explicit ThrAlarm(QObject *parent = nullptr);

    ~ThrAlarm();

    bool setBuzzerFreq(float_t freq);

    float_t buzzerFreq() const;

    std::uint8_t buzzAt(std::float_t freq, std::float_t duration);

    void buzzOn(std::float_t duration);
    void buzzOff(std::float_t duration);

    bool configureSignal();

    float_t pulseHigh_sec() const;
    float_t pulseLow_sec() const;

    void setAlarm(const bool value = false);

    bool static alarmIsSet();

signals:
    void finished();
    void valueChanged(int);
    void timerConfig(int);


public slots:
    void alarmOn();
    void alarmOff();

private slots:
    void onInit();

private:
    QThread* qThrAlarm_;
    QTimer *timer;

    QString name;
    DrvGpio gpioBuzzer;
    QStringList scripts;

    float_t local; ///TODO try setting widthtype to std::float32_t...
    float_t buzzerFreq_;
    float_t pulseHigh_;
    float_t pulseLow_;
    std::uint32_t onTime_;
    std::uint32_t offTime_;

    static bool alarm_;

    [[noreturn]] static void ThrAlarmRun();
};

inline bool ThrAlarm::alarmIsSet() {
    return ThrAlarm::alarm_;
}

#endif // THRALARM_H
