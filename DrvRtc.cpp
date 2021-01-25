#include "DrvRtc.h"
#include "ThrInput.h"
#include <wiringPiI2C.h>

DS1307::DS1307() : isRunning_(false) {
    this->dateTime_ = QDateTime::fromString("01.01.2001", "dd.MM.yyyy");
}

DS1307::~DS1307(){}

bool DS1307::Initialize() {
    std:uint8_t sec, min, hour, day, month, year;
    this->identifier_ = wiringPiI2CSetup(DEVICE_ID);
    this->state_ = (this->identifier_ == -1) ? INACTIVE : ACTIVE;
    if(this->state_ == ACTIVE){
        int ctrlReg = wiringPiI2CReadReg8(this->identifier_, CTRL_REG);
        ctrlReg = wiringPiI2CWriteReg8(this->identifier_, CTRL_REG, RATE_SELECT_4kHz | SQUARE_WAVE_ENABLED);
        ctrlReg = wiringPiI2CReadReg8(this->identifier_, CTRL_REG);
        if(!this->isRunning())
            this->start();
        this->writeDevice(YEAR_REG, 21);
        this->writeDevice(MONTH_REG, 01);
        this->writeDevice(DAY_REG, 23);

        this->writeDevice(HOURS_REG, 23);
        this->writeDevice(MINUTES_REG, 34);

//        qDebug() << this->getSeconds(sec) << sec
//                 << DS1307::formatFromBCD(static_cast<std::uint8_t>(sec) &
//                                          SEC_BCD_FORMAT_MASK);
//        qDebug() << this->getMinutes(min) << min
//                 << DS1307::formatFromBCD(static_cast<std::uint8_t>(min) &
//                                          MIN_BCD_FORMAT_MASK);

//        qDebug() << this->getMonth(month) << month
//                 << DS1307::formatFromBCD(static_cast<std::uint8_t>(month) &
//                                          MONTH_BCD_FORMAT_MASK);

//        qDebug() << this->getSeconds(sec) << sec
//                 << DS1307::formatFromBCD(static_cast<std::uint8_t>(sec) &
//                                          SEC_BCD_FORMAT_MASK);
//        qDebug() << this->getSeconds(sec) << sec
//                 << DS1307::formatFromBCD(static_cast<std::uint8_t>(sec) &
//                                          SEC_BCD_FORMAT_MASK);
//        qDebug() << this->getSeconds(sec) << sec
//                 << DS1307::formatFromBCD(static_cast<std::uint8_t>(sec) &
//                                          SEC_BCD_FORMAT_MASK);
//        qDebug() << this->getSeconds(sec) << sec
//                 << DS1307::formatFromBCD(static_cast<std::uint8_t>(sec) &
//                                          SEC_BCD_FORMAT_MASK);


        //wiringPiI2CWriteReg8(this->identifier_, HALT_REG, HALT_CLK);
        int isHalt = wiringPiI2CReadReg8(this->identifier_, HALT_REG);
        if((isHalt & HALT_CLK)) {
            wiringPiI2CWriteReg8(this->identifier_, HALT_REG, (isHalt & ~HALT_CLK));
            //wiringPiI2CReadReg8(this->identifier_, SECONDS_REG);
        }
        int hourFormat = wiringPiI2CReadReg8(this->identifier_, HOURS_REG);
        if(hourFormat != -1 && hourFormat & HOUR_FORMAT_12){
            hourFormat = wiringPiI2CWriteReg8(this->identifier_, HOURS_REG, hourFormat & ~HOUR_FORMAT_12);
            hourFormat = wiringPiI2CReadReg8(this->identifier_, HOURS_REG);
        }
        std::uint8_t seconds;
        this->getSeconds(seconds);
    }
    return (this->identifier_ == -1);
}

std::uint8_t DS1307::formatFromBCD(std::uint8_t value) {
    std::uint8_t unit, decimal, result;
    decimal = ((value & 0xF0) >> 4);
    decimal *= 10;
    unit = (value & 0x0F);
    result = decimal + unit;
    return result;
}

bool DS1307::stop() {
    if(this->isRunning_){
        if(this->writeDevice(static_cast<int>(HALT_REG),
                             static_cast<int>(HALT_CLK))){
            this->isRunning_ = false;
        }
        return false;
    }
   return this->isRunning_;
}

bool DS1307::start() {
    if(!this->isRunning_){
        if(this->writeDevice(static_cast<int>(HALT_REG),
                             static_cast<int>(~HALT_CLK))){
            this->isRunning_ = true;
        }
        return false;
    }
    return this->isRunning_;
}

bool DS1307::update(){
    std:uint8_t sec = 0, min = 0, hour = 0, wday = 1, day = 0, month = 0, year = 0;
    if(this->isRunning()){
        this->getYear(year);
        ThrInput::instance().getThreadInstance().msleep(10);
        this->getMonth(month);
        ThrInput::instance().getThreadInstance().msleep(10);
        this->getDay(day);
        ThrInput::instance().getThreadInstance().msleep(10);
        this->getHours(hour);
        ThrInput::instance().getThreadInstance().msleep(10);
        this->getMinutes(min);
        ThrInput::instance().getThreadInstance().msleep(10);
        this->getSeconds(sec);
        ThrInput::instance().getThreadInstance().msleep(10);
        qDebug() << "Time: " << hour << min << sec;
        qDebug() << "Date: " << day << month << year;
        QDate* date = new QDate(year, month, day);

        QTime *time = new QTime(hour, min, sec);
//        qDebug() << "DateTime before: " << this->dateTime_.toString();
        if(date->isValid())
            this->dateTime_.setDate(*date);
        if(time->isValid())
            this->dateTime_.setTime(*time);

        ///check dateTime overflow
        //qDebug() << "DateTime after: " << this->dateTime_.toString();
        return true;

//        return true;
    }
    return false;
}

bool DS1307::isRunning(){
    int isHalt;
    if(this->readDevice(HALT_REG, isHalt)){
        this->isRunning_ = (isHalt & HALT_CLK) ? false : true;
        return this->isRunning_;
    }
    return false;
}

QDateTime& DS1307::getDateTime(){
    return this->dateTime_;
}

bool DS1307::readDevice(int regAdd, int &data) {
    if(this->state_ == INACTIVE) return false;
    data = wiringPiI2CReadReg8(this->identifier_, regAdd);
    return (data != -1);
}

bool DS1307::writeDevice(int regAdd, int data) {
    if(this->state_ == INACTIVE) return false;
    return (wiringPiI2CWriteReg8(this->identifier_, regAdd, data) != -1);
}

bool DS1307::getSeconds(std::uint8_t &refValue){
    int seconds = 0;
    if(this->state_ == INACTIVE || !readDevice(SECONDS_REG, seconds)){
        return false;
    }
    std::uint8_t secondFromBCD = DS1307::formatFromBCD(static_cast<std::uint8_t>(seconds) &
                                                       SEC_BCD_FORMAT_MASK);
//    qDebug()<< "Seconds (BCD): " << seconds;
//    qDebug()<< "Seconds (binnary): " << secondFromBCD;
    if(!(secondFromBCD >=  SEC_MIN && secondFromBCD <= SEC_MAX)){
//        refValue = SEC_MIN;
        return false;
    }
    refValue = secondFromBCD;
    return true;
}

bool DS1307::getMinutes(std::uint8_t &refValue) {
    int minutes = 0;
    if(this->state_ == INACTIVE || !readDevice(MINUTES_REG, minutes)) {
        return false;
    }
    std::uint8_t minutesFromBCD = DS1307::formatFromBCD(static_cast<std::uint8_t>(minutes) &
                                                        MIN_BCD_FORMAT_MASK);
    if(!(minutesFromBCD >= MINUTES_MIN && minutesFromBCD <= MINUTES_MAX)) return false;
    refValue = minutesFromBCD;
    return true;
}

bool DS1307::getHours(std::uint8_t &refValue) {
    int hours = 0;
    if(this->state_ == INACTIVE || !readDevice(HOURS_REG, hours))
        return false;
    std::uint8_t hoursFromBCD = DS1307::formatFromBCD(static_cast<std::uint8_t>(hours) &
                                                      HOUR24_BCD_FORMAT_MASK);
    if(!(hoursFromBCD >= HOUR_MIN && hoursFromBCD <= HOUR_MAX)) return false;
    refValue = hoursFromBCD;
    return true;
}

int DS1307::getWeekDay(){
    int weekDay = 0;
    if(this->state_ == INACTIVE || !readDevice(WEEK_DAY_REG, weekDay))
        return -1;
    return weekDay;
}

bool DS1307::getDay(std::uint8_t &refValue){
    int day = 0;
    if(this->state_ == INACTIVE || !readDevice(DAY_REG, day)) return false;
    std::uint8_t dayFromBCD = DS1307::formatFromBCD(static_cast<std::uint8_t>(day) &
                                                    DAY_BCD_FORMAT_MASK);
    if(!(dayFromBCD >= DAY_MIN && dayFromBCD <= DAY_MAX)) return false;
    refValue = dayFromBCD;
    return true;
}

bool DS1307::getMonth(std::uint8_t &refValue){
    int month = 0;
    if(this->state_ == INACTIVE || !readDevice(MONTH_REG, month)) return false;
    std::uint8_t monthFromBCD = DS1307::formatFromBCD(static_cast<std::uint8_t>(month) &
                                                      MONTH_BCD_FORMAT_MASK);
    if(!(monthFromBCD >= MONTH_MIN && monthFromBCD <= MONTH_MAX))
    {
        refValue = MONTH_MIN;
        return false;
    }

    refValue = monthFromBCD;
    return true;
}

bool DS1307::getYear(std::uint8_t &refValue){
    int year = 0;
    if(this->state_ == INACTIVE || !readDevice(YEAR_REG, year)) return false;
    std::uint8_t yearFromBCD = DS1307::formatFromBCD(static_cast<std::uint8_t>(year) &
                                                     YEAR_BCD_FORMAT_MASK);

    if(!(yearFromBCD >= YEAR_MIN && yearFromBCD <= YEAR_MAX)) return false;
//    qDebug()<< "Year (BCD): " << year;
//    qDebug() << "Year: " << yearFromBCD;
    refValue = yearFromBCD;
    return true;
}
