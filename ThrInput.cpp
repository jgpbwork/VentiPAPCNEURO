#include "ThrInput.h"
#include "IEEE754.h"
#include <QDebug>
#include <wiringPiI2C.h>
#include <sys/time.h>

#define MAX_COUNT 30

ThrInput::ThrInput(QObject *parent) : QObject(),
                                      Singleton(this) {
    Q_UNUSED(parent)
    this->minVal = 0.0f;
    this->maxVal = 100.0f;
    this->lastReading = 20.9f;

    /// Low Level Driver Initialization Sequence...
    /// Real Time Clock Initialization.
    /// Analog to Digital Converter for Oxigen Sensor Initialization Sequence...
    this->drvAdc.Initialize();
    this->drvRtc.Initialize();    
    this->drvBattGauge.Initialize();

    /// Instance Variables Initialization and Synchronization Sequence...
    qThrInput_ = QThread::create(&ThrInput::ThrInputRun);
    if(qThrInput_ != nullptr){
        qThrInput_->setParent(this);
        this->deviceInit();
//        qDebug() << "At ThrInput Constructor: " << this->thread();
//        qDebug() << "ThrInput's inner thraed: " << this->qThrInput_->thread();
        this->moveToThread(qThrInput_);
        qThrInput_->start();
    }
}

ThrInput::~ThrInput() {}

void ThrInput::deviceInit() {}

bool ThrInput::deviceConfigure() {
    return true;
}

void ThrInput::ThrInputRun() {
    std::uint16_t lastDataADC = 0, battCharge = 0;
    std::uint8_t loop = MAX_COUNT;
    static std::uint8_t regCtrl=0;
    float val = 0.0f;
    float engValue = 0.0f, battVoltage = 0.0f, battTemp = 0.0f;
    ThrInput::instance().drvRtc.start();

    qDebug() << ThrInput::instance().drvRtc.getDateTime().toString("dd/MM/yy hh:mm:ss");

    time_t rawTime;
    struct tm *timeInfo;

    while(true)
    {        
        lastDataADC = 0;
        val = 0.0f;
        engValue = 0.0f;
        
        if(!ThrInput::instance().drvBattGauge.getCtrlReg(regCtrl))
            regCtrl = 0;
        if(!ThrInput::instance().drvAdc.readData(lastDataADC)) {
            ///Signal Device Error Reading...
            continue;
        }
        /// data validation...
        val = ThrInput::instance().drvAdc.ToEngValue(lastDataADC);
        engValue = (val * 1000.0f) * 20.9f / 11.5f;
        qDebug() << "Sensor Voltage: " << val << " (" << engValue << ") % O2.";
        ThrInput::instance().lastReading = val;

        /// Continue to read Battery Gauge Value
        if(ThrInput::instance().drvBattGauge.readVoltage(battVoltage)){
            qDebug() << "BattVoltage: " << battVoltage;
        }
        if(ThrInput::instance().drvBattGauge.readTemperature(battTemp)){
            qDebug() << "BattTemperature: " << battTemp;
        }
        if(!(--loop)){
            battCharge = 0;
            if(ThrInput::instance().drvBattGauge.readCharge(battCharge)){
                qDebug() << "****BattCharge: " << battCharge << " ****";
            }
            loop = MAX_COUNT;
        }

        /// Continue to read RTC
        if(ThrInput::instance().drvRtc.update()){
            qDebug() << ThrInput::instance().drvRtc.getDateTime().toString("dd/MM/yy hh:mm:ss");
            time(&rawTime);
            timeInfo = localtime(&rawTime);
            qDebug() << "System time: " << asctime(timeInfo);
            ThrInput::instance().updateRealTimeClock(ThrInput::instance().drvRtc.getDateTime());
        }
        /// emit UI signal...
        ThrInput::instance().updateReadings(val, battVoltage);
        ThrInput::instance().qThrInput_->msleep(1000);   ///Wait a second to update next readings...
    }
}

void ThrInput::validateReading(){
    if(this->lastReading > this->minVal &&
       this->lastReading < this->maxVal) {
        emit ThrInput::instance().inRange();
    }
    else{
        emit ThrInput::instance().outOfRange();
    }
}

bool ThrInput::setDateTime(QDateTime currentDate)
{
    if(currentDate.isValid()) { ///TODO check time regretion
        return this->drvRtc.setDate(currentDate);
    }
    return false;
}

void ThrInput::updateReadings(std::float_t oxygenVal, std::float_t battVal) {
    emit updateOxygenLevel(static_cast<double>(oxygenVal));
//    emit updateOxygenLevel(QString::number(static_cast<double>(oxygenVal), 'f', 1));
    emit updateBatteryLevel("Batt: " + QString::number(static_cast<double>(battVal), 'f', 2) + " volts");
    ///TODO emit RTC content with QDateTime Variable...
}

void ThrInput::updateDateTime(QDateTime &refValue) {
    if(refValue.isValid())
        emit updateRealTimeClock(refValue);
}

void ThrInput::setMinimumValue(const QString& value)
{
    try {
        this->minVal = value.toFloat();       
    } catch (std::exception ex) {
      qDebug() << "Error at UI: " << ex.what();
    }
}

void ThrInput::setMaximumValue(const QString value)
{
    try {
        this->maxVal = value.toFloat();
    } catch (std::exception ex) {
      qDebug() << "Error at UI: " << ex.what();
    }
}
