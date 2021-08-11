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
    this->readings = std::array<std::uint16_t, ThrInput::MAX_AVERAGE>{65520,65520,65520,65520,65520};
//    this->processReadings();
    this->readings.fill(0);

    ///delete this after testing
    std::float_t cal;
    std::uint16_t diff = 30;

     cal = static_cast<std::float_t>(diff) * 0.085f * ((false) ?0.5f:1.0f);

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
    std::uint8_t average = 0;
    static std::uint8_t regCtrl=0;
    float val = 0.0f;
    float engValue = 0.0f, battVoltage = 0.0f, battTemp = 0.0f;
    int data;
    ThrInput::instance().drvRtc.start();

    qDebug() << ThrInput::instance().drvRtc.getDateTime().toString("dd/MM/yy hh:mm:ss");

    time_t rawTime;
    struct tm *timeInfo;
    if(ThrInput::instance().drvBattGauge.readCharge(battCharge)){
        emit ThrInput::instance().batteryChargeLevel(battCharge);
    }

    while(true)
    {        
        lastDataADC = 0;
        val = 0.0f;
        engValue = 0.0f;
        
        if(!ThrInput::instance().drvBattGauge.readDevice(LTC2942::CONTROL_REG, data))
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
//        if(ThrInput::instance().drvBattGauge.readTemperature(battTemp)){
//            qDebug() << "BattTemperature: " << battTemp;
//        }
        if(!(--loop)){
            battCharge = 0;
            if(ThrInput::instance().drvBattGauge.readDevice(LTC2942::CONTROL_REG, data))
            if(ThrInput::instance().drvBattGauge.readCharge(battCharge)){
                qDebug() << "****BattCharge: " << battCharge << " ****";
                ThrInput::instance().readings.at(average++) = battCharge;
                emit ThrInput::instance().batteryChargeLevel(battCharge);
                if(average == MAX_AVERAGE){
//                    ThrInput::instance().processReadings();
                    average = 0;
                }
            }
            ThrInput::instance().drvBattGauge.readDevice(LTC2942::CONTROL_REG, data);
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

void ThrInput::processReadings(void){
    std::uint16_t diff;
    std::float_t cal, ave = 0.0f;
    for (uint8_t i = 0, n = MAX_AVERAGE - 1; i < n; ++i){
        if(this->readings.at(i) > this->readings.at(i + 1)){ //is discharging
            std::uint16_t val = this->readings.at(i);
            std::uint16_t nextVal = this->readings.at(i + 1);
            diff = (val - nextVal);
            cal = static_cast<std::float_t>(diff) * ((this->drvBattGauge.controlReg.Prescaler == LTC2942::M64) ?
                                                      LTC2942::CHARGE_COULOMB_RATIO_M64 :
                                                      (this->drvBattGauge.controlReg.Prescaler == LTC2942::M128) ?
                                                      LTC2942::CHARGE_COULOMB_RATIO_M128 : 0.0f) * -1.0f;
            ///send discharge signal with value;            
            qDebug() << "*********Discharge: " << cal;
//            emit this->batteryIsCharging(false);
            emit this->updateBatteryCharge(static_cast<double>(cal));
            if (i == 0)
                ave += cal;
            else {
                ave = (ave + cal) / 2.0f;
            }
            continue;
        }
        else if(this->readings.at(i) < this->readings.at(i + 1)){ //is charging
            /// Send Charge signal with value;
            diff = this->readings.at(i + 1) - this->readings.at(i);
            cal = static_cast<std::float_t>(diff) * ((this->drvBattGauge.controlReg.Prescaler == LTC2942::M64) ?
                                                         LTC2942::CHARGE_COULOMB_RATIO_M64 :
                                                         (this->drvBattGauge.controlReg.Prescaler == LTC2942::M128) ?
                                                         LTC2942::CHARGE_COULOMB_RATIO_M128 : 0.0f);
            ///Send Charging signal with value;
            qDebug() << "**********Charging: " << cal;
            emit this->updateBatteryCharge(static_cast<double>(cal));
            if (i == 0)
                ave += cal;
            else {
                ave = (ave + cal) / 2.0f;
            }
            continue;
        }
        else {
            if(this->readings.at(i) == std::numeric_limits<std::uint16_t>::max()){
                ///TODO emit signal baterry fully charge;
                emit this->batteryFull();
                this->readings.fill(0);
                return;
            }
            qDebug() << "Error at Battery charge: " << this->readings.at(i);
        }
    }
    qDebug() << "Emit signal Ave: " << ave;
    this->readings.fill(0);
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

void ThrInput::updateReadings(std::float_t oxygenVal, std::float_t battVoltage) {
    emit updateOxygenLevel(static_cast<double>(oxygenVal));
//    emit updateOxygenLevel(QString::number(static_cast<double>(oxygenVal), 'f', 1));
    emit updateBatteryVoltage("Batt: " + QString::number(static_cast<double>(battVoltage), 'f', 2) + " volts");    
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
