#include "ThrAlarm.h"
#include "mainwindow.h"

#include <wiringPi.h>
#include <QMath.h>
#include <QDebug>

#define BUZZER_PIN 37
#define BUZZER_FREQ 2000
#define ALARM_PERIODS 1000

bool ThrAlarm::alarm_;

const std::float_t ThrAlarm::T1 = 150e-3f;
const std::float_t ThrAlarm::T2 = 120e-3f;
const std::float_t ThrAlarm::T3 = 390e-3f;

const std::float_t ThrAlarm::C4 = 262.0f;
const std::float_t ThrAlarm::A4 = 440.0f;
const std::float_t ThrAlarm::F4 = 349.0f;
const std::float_t ThrAlarm::FR = 2400.0f;

ThrAlarm::ThrAlarm(QObject *parent) : QObject (),
                                      Singleton(this),
                                      Time() {
    Q_UNUSED(parent)
    ThrAlarm::alarm_ = false;

    this->gpioBuzzer.setup(BUZZER_PIN, DrvGpio::GPIO_OUT);
    this->gpioBuzzer.write(BUZZER_PIN, DrvGpio::GPIO_HIGH);
    this->gpioBuzzer.write(BUZZER_PIN, DrvGpio::GPIO_LOW);
//    this->gpioBuzzer.write(BUZZER_PIN, DrvGpio::GPIO_HIGH);
//    this->gpioBuzzer.write(BUZZER_PIN, DrvGpio::GPIO_LOW);
//    this->gpioBuzzer.write(BUZZER_PIN, DrvGpio::GPIO_HIGH);
//    this->gpioBuzzer.write(BUZZER_PIN, DrvGpio::GPIO_LOW);
//    this->gpioBuzzer.write(BUZZER_PIN, DrvGpio::GPIO_HIGH);
//    this->gpioBuzzer.write(BUZZER_PIN, DrvGpio::GPIO_LOW);
//    this->gpioBuzzer.write(BUZZER_PIN, DrvGpio::GPIO_HIGH);
//    this->gpioBuzzer.write(BUZZER_PIN, DrvGpio::GPIO_LOW);
//    this->gpioBuzzer.write(BUZZER_PIN, DrvGpio::GPIO_HIGH);
//    this->gpioBuzzer.write(BUZZER_PIN, DrvGpio::GPIO_LOW);


//    this->setBuzzerFreq(static_cast<float_t>(BUZZER_FREQ));
//    this->configureSignal();

    qThrAlarm_ = QThread::create(&ThrAlarm::ThrAlarmRun);
    if(qThrAlarm_ != nullptr) {
        qThrAlarm_->setParent(this);
        qThrAlarm_->setObjectName("ThrAlarm");
        qThrAlarm_->setPriority(QThread::TimeCriticalPriority);
        this->moveToThread(qThrAlarm_);
        connect(qThrAlarm_, &QThread::started, this, &ThrAlarm::onInit);
        connect(qThrAlarm_, &QThread::finished, this, &QObject::deleteLater);
        connect(this, SIGNAL(finished()), qThrAlarm_, SLOT(quit()));
        connect(this, SIGNAL(finished()), qThrAlarm_, SLOT(deleteLater()));
        qThrAlarm_->start();
    }
//    QTimer::singleShot(timeout1, this, )
//    timer->setInterval(timeout1);
//    connect(timer, &QTimer::timeout, this, )
//    timer->start();
}

ThrAlarm::~ThrAlarm()
{    
    this->qThrAlarm_->exit();
//    this->qThrAlarm_->wait();
    qDebug() << "At Destructor: ThrAlarm isFinished: " << this->qThrAlarm_->isFinished();
    if(this->qThrAlarm_->isRunning()) {
        this->qThrAlarm_->terminate();
    }
    this->gpioBuzzer.write(BUZZER_PIN, DrvGpio::GPIO_LOW);
    //emit this->finished();
}

void ThrAlarm::onInit()
{
    qDebug() << "Add Initialization code for " << this->thread()->objectName()
             << "Run method here...";
    this->timer = new QTimer(this);
}

void ThrAlarm::ThrAlarmRun() {

     while (true) {
         if(ThrAlarm::alarmIsSet()) {
//               qDebug() << "Beeping on 29!!!...";
             ///Initiate Alarm sequence
             /// 1st Pulse C4 = 262Hz for 150ms
             ThrAlarm::instance().buzzAt(ThrAlarm::FR, ThrAlarm::T1);
             ThrAlarm::instance().buzzOff(ThrAlarm::T2); /// 120ms of Silence
             /// 2nd Pulse A4 = 440Hz for 150ms
             ThrAlarm::instance().buzzAt(ThrAlarm::FR, ThrAlarm::T1);
             ThrAlarm::instance().buzzOff(ThrAlarm::T2); /// 120ms of Silence
             /// 3rd Pulse F4 = 349Hz for 150ms
             ThrAlarm::instance().buzzAt(ThrAlarm::FR, ThrAlarm::T1);
             ThrAlarm::instance().buzzOff(ThrAlarm::T3); /// 390ms of Silence
             ///--------------------------------             
             /// 2nd Pulse A4 = 440Hz for 150ms
             ThrAlarm::instance().buzzAt(ThrAlarm::FR, ThrAlarm::T1);
             ThrAlarm::instance().buzzOff(ThrAlarm::T2); /// 120ms of Silence
             /// 3rd Pulse F4 = 349Hz for 150ms
             ThrAlarm::instance().buzzAt(ThrAlarm::FR, ThrAlarm::T1);
             ThrAlarm::instance().buzzOff(ThrAlarm::T3); /// 390ms of Silence
         }         
         else {
//             qDebug() << "Not Beeping...";
             ThrAlarm::instance().gpioBuzzer.write(BUZZER_PIN, DrvGpio::GPIO_LOW);             
         }
         ThrAlarm::instance().qThrAlarm_->usleep(500);
     }
}

bool ThrAlarm::setBuzzerFreq(float_t freq)
{
    if(freq <= 0.0f){
        return false;
    }
    this->buzzerFreq_ = freq;
    return true;
}

float_t ThrAlarm::buzzerFreq() const
{
    return this->buzzerFreq_;
}

bool ThrAlarm::configureSignal()
{
    this->pulseHigh_ = 3 / (4 * this->buzzerFreq());
    this->pulseLow_ = 1 / (4 * this->buzzerFreq());
    return true;
}

std::uint16_t ThrAlarm::buzzAt(std::float_t freq, std::float_t duration) {
    if(freq <= 0.0f || isnanf(freq) ||
       duration <= 0.0f || isnanf(duration)) {
        return 0;
    }
    std::float_t pulse = (0.5f * (1.0f / freq) * 1000000.0f) - 65;
    std::uint16_t cycles = static_cast<std::uint16_t>(freq * duration);

    std::uint16_t index;
    for(index = 0; index < cycles; index++) {
        this->gpioBuzzer.write(BUZZER_PIN, DrvGpio::GPIO_HIGH);
        ThrAlarm::instance().qThrAlarm_->usleep(static_cast<unsigned int>(pulse));//140));//pulse * 1000000.0f));
//        delay(static_cast<unsigned int>(pulse));
        this->gpioBuzzer.write(BUZZER_PIN, DrvGpio::GPIO_LOW);
        ThrAlarm::instance().qThrAlarm_->usleep(static_cast<unsigned int>(pulse));//140));//pulse * 1000000.0f));
//        delay(static_cast<unsigned int>(pulse));
    }
    return index;
}

void ThrAlarm::buzzOn(std::float_t duration) {
    if(duration <= 0.0f || isnanf(duration)) {
        return;
    }
    this->gpioBuzzer.write(BUZZER_PIN, DrvGpio::GPIO_HIGH);
    ThrAlarm::instance().qThrAlarm_->msleep(static_cast<unsigned int>(duration * 1000.0f));
    //delay(static_cast<unsigned int>(duration));
}

void ThrAlarm::buzzOff(std::float_t duration) {
    if(duration <= 0.0f || isnanf(duration)) {
        return;
    }
    this->gpioBuzzer.write(BUZZER_PIN, DrvGpio::GPIO_LOW);
    ThrAlarm::instance().qThrAlarm_->msleep(static_cast<unsigned int>(duration * 1000.0f));
//    delay(static_cast<unsigned int>(duration));
}

float_t ThrAlarm::pulseHigh_sec() const
{
    return this->pulseHigh_;
}

float_t ThrAlarm::pulseLow_sec() const
{
    return this->pulseLow_;
}

void ThrAlarm::alarmOn()
{
    ThrAlarm::alarm_ = true;
    qDebug() << "alarmOn Signal emited";
}

void ThrAlarm::alarmOff()
{
    ThrAlarm::alarm_ = false;
    qDebug() << "alarmOff Signal emited";
}

void ThrAlarm::setAlarm(const bool value){
    return (value) ? this->alarmOn() : this->alarmOff();
}
