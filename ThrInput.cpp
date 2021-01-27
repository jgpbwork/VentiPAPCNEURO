#include "ThrInput.h"
#include "IEEE754.h"
#include <QDebug>
#include <wiringPiI2C.h>
#include <sys/time.h>

ThrInput::ThrInput(QObject *parent) : QObject(),
                                      Singleton(this) {
    Q_UNUSED(parent)
    this->minVal = 0.0f;
    this->maxVal = 100.0f;
    this->lastReading = 20.9f;
//    this->sensor = new QSerialPort(this);

    /// Low Level Driver Initialization Sequence...
    /// Real Time Clock Initialization.
    /// Analog to Digital Converter for Oxigen Sensor Initialization Sequence...

    this->drvAdc.Initialize();
    this->drvRtc.Initialize();    
    this->drvBattGauge.Initialize();

    /// Instance Variables Initialization and Synchronization Sequence...
//    int seconds = this->drvRtc.getSeconds();
//    int minutes = this->drvRtc.getMinutes();
//    int hours = this->drvRtc.getHours();

//    int dayOfWeek = this->drvRtc.getWeekDay();
//    int day = this->drvRtc.getDay();
//    int month = this->drvRtc.getMonth();
//    int year = this->drvRtc.getYear();

    qThrInput_ = QThread::create(&ThrInput::ThrInputRun);
    if(qThrInput_ != nullptr /*&& this->sensor != nullptr*/){
        qThrInput_->setParent(this);
        this->deviceInit();
//        qDebug() << "At ThrInput Constructor: " << this->thread();
//        qDebug() << "ThrInput's QserialPort: " << this->sensor->thread();
//        qDebug() << "ThrInput's inner thraed: " << this->qThrInput_->thread();
        this->moveToThread(qThrInput_);
        qThrInput_->start();
    }
}

ThrInput::~ThrInput() {
    //this->sensor->close();
}

void ThrInput::deviceInit() {
//    if(sensor != nullptr) {
//        if(deviceConfigure()) {
//            QObject::connect(this->sensor, &QSerialPort::readyRead, this, &ThrInput::readValue);
////            QObject::connect(sensor, SIGNAL(readyRead()), this, SLOT(readValue()));
////            QMetaMethod signal = QMetaMethod::fromSignal(&QSerialPort::readyRead);
////            qDebug() << "Device Configured...";
////            qDebug() << "connected signal: " << signal.name();
////            qDebug() << signal.methodSignature() << signal.isValid();
//        }
//    }
}

bool ThrInput::deviceConfigure() {
//    this->sensor->setPortName("/dev/serial0");//portName_);
//    qDebug() << ((this->sensor->open(QSerialPort::ReadOnly) == true) ? "Device open: " : "Device not open") << this->sensor->portName();
//    this->sensor->setBaudRate(921600);
//    this->sensor->setDataBits(QSerialPort::Data8);
//    this->sensor->setFlowControl(QSerialPort::NoFlowControl);
//    this->sensor->setParity(QSerialPort::NoParity);
//    this->sensor->setStopBits(QSerialPort::OneStop);
    return true;
}

void ThrInput::ThrInputRun() {
//    qDebug() << "ThrInput's new thread Run method: " << ThrInput::instance().thread();
//    qDebug() << "ThrInput's QserialPort: " << ThrInput::instance().sensor->thread();
//    qDebug() << "ThrInput's inner thraed: " << ThrInput::instance().qThrInput_->thread();
//    ThrInput::instance().thread()->wait();
    std::uint16_t lastDataADC = 0, battCharge = 0;
    float val = 0.0f;
    float engValue = 0.0f, battVoltage = 0.0f, battTemp = 0.0f;
    ThrInput::instance().drvRtc.start();

    qDebug() << ThrInput::instance().drvRtc.getDateTime().toString("dd/MM/yy hh:mm:ss");

    time_t rawTime;
    struct tm *timeInfo;

    while(true)
    {
        //ThrInput::instance().sensor->waitForReadyRead(Q_WAIT_FOREVER);  ///wait forever
        //ThrInput::instance().validateReading();

        ThrInput::instance().qThrInput_->msleep(1000);   ///Wait a second to update readings...        
        lastDataADC = 0;
        val = 0.0f;
        engValue = 0.0f;
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
        if(ThrInput::instance().drvBattGauge.readCharge(battCharge)){
            qDebug() << "BattCharge: " << battCharge;
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

void ThrInput::readValue()
{
//    QByteArray bytes = this->sensor->readAll();
//    qDebug() << "At input Slot: " << this->thread();
//    qDebug() << "New data has been read...";
//    qDebug() << "Readed " << bytes.size() << " bytes...";
////    for(uint8_t index = 0; index < bytes.size(); index++)
////        qDebug() << "Byte " << index <<": " << bytes.at(index);

//    if(bytes.size() == sizeof(float)) {
//        float engValue = IEEE_754::convertirDesde_754_32(IEEE_754::convert_Bytes_To_Uint32(bytes));
////        qDebug() << "Readed value: " << engValue;
//        this->lastReading = engValue;
//        emit updateOxygenLevel(QString::number(static_cast<double>(engValue), 'f', 1));
//    }
//    else {
//        this->sensor->flush();
//    }
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
