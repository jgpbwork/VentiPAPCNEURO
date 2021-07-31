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

    std::uint16_t buzzAt(std::float_t freq, std::float_t duration);

    void buzzOn(std::float_t duration);
    void buzzOff(std::float_t duration);

    bool configureSignal();

    float_t pulseHigh_sec() const;
    float_t pulseLow_sec() const;

    void setAlarm(const bool value = false);

    bool static alarmIsSet();

    enum AlarmPriority
    {
        P_LOW = 0,
        P_MIDIUM = 1,
        P_HIGH = 2
    };

    inline void setAlarmType(ThrAlarm::AlarmPriority type);

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

    static const std::float_t T1;
    static const std::float_t T2;
    static const std::float_t T3;
    static const std::float_t C4;
    static const std::float_t A4;
    static const std::float_t F4;
    static const std::float_t FR;

    static const std::size_t DELAY_HIGH_PRIORITY = 7500;
    static const std::size_t DELAY_MIDIUM_PRIORITY = 20000;

    static bool alarm_;
    static std::uint8_t alarmPriority_;

    [[noreturn]] static void ThrAlarmRun();

    static AlarmPriority getAlarmPriority();
};

inline bool ThrAlarm::alarmIsSet() {
    return ThrAlarm::alarm_;
}

inline void ThrAlarm::setAlarmType(ThrAlarm::AlarmPriority type) {
    ThrAlarm::alarmPriority_ = static_cast<std::uint8_t>(type);
}
#endif // THRALARM_H
