#include "DrvRtc.h"
#include "ThrInput.h"

#include <wiringPiI2C.h>
#include <sys/time.h>

DS1307::DS1307() : isRunning_(false) {
    this->dateTime_ = QDateTime::fromString("Fri Jan 01 12:00:00 2021");
}

DS1307::~DS1307(){}

bool DS1307::Initialize() {
    std:uint8_t sec, min, hour, day, month, year;
    time_t rawTime;
    struct tm *timeInfo;

    this->identifier_ = wiringPiI2CSetup(DEVICE_ID);
    this->state_ = (this->identifier_ == -1) ? INACTIVE : ACTIVE;
    if(this->state_ == ACTIVE){
        int ctrlReg = wiringPiI2CReadReg8(this->identifier_, CTRL_REG);
        ctrlReg = wiringPiI2CWriteReg8(this->identifier_, CTRL_REG, RATE_SELECT_4kHz | SQUARE_WAVE_ENABLED);
        ctrlReg = wiringPiI2CReadReg8(this->identifier_, CTRL_REG);

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

        ///Set DateTime from Local System time at boot
        time(&rawTime);
        timeInfo = localtime(&rawTime);
        QString dt = asctime(timeInfo);
        dt = dt.remove(dt.size()-1, 1);
        QDateTime systemDateTime = QDateTime::fromString(dt);

        ///Reading RTC and compare to system time before update
        if(this->update()){
            if(this->dateTime_.isValid() && systemDateTime.isValid()){
                if(systemDateTime > this->dateTime_){
                    this->dateTime_ = systemDateTime;
                    if(this->dateTime_.isValid()){
                        int year_t = this->dateTime_.date().year();

                        if(year_t >= BASE_YEAR){
                            year_t -= BASE_YEAR;
                        }
                        else{
                            year_t = BASE_YEAR + 1;
                        }
                        if(!year_t) year_t = BASE_YEAR_OVF;   ///Fix this

                        qDebug()<< "Setting year: " << static_cast<std::uint8_t>(year_t);
                        qDebug() << "Set Year: " << this->writeDevice(YEAR_REG,
                                                                      DS1307::formatToBCD(static_cast<std::uint8_t>
                                                                                          (this->dateTime_.date().year() - BASE_YEAR)))
                                                  << this->getYear(year) << year;
                        ThrInput::instance().getThreadInstance().msleep(10);
                        qDebug() << "Set Month: " << this->writeDevice(MONTH_REG,
                                                                       DS1307::formatToBCD(static_cast<std::uint8_t>
                                                                                           (this->dateTime_.date().month())))
                                                  << this->getMonth(month) << month;
                        ThrInput::instance().getThreadInstance().msleep(10);
                        qDebug() << "Set Day: " << this->writeDevice(DAY_REG,
                                                                     DS1307::formatToBCD(static_cast<std::uint8_t>
                                                                                         (this->dateTime_.date().day())))
                                                << this->getDay(day) << day;
                        ThrInput::instance().getThreadInstance().msleep(10);
                        qDebug() << "Set Hour: " << this->writeDevice(HOURS_REG,
                                                                      DS1307::formatToBCD(static_cast<std::uint8_t>
                                                                                          (this->dateTime_.time().hour())))
                                                 << this->getHours(hour) << hour;
                        ThrInput::instance().getThreadInstance().msleep(10);
                        qDebug() << "Set Minutes: " << this->writeDevice(MINUTES_REG,
                                                                         DS1307::formatToBCD(static_cast<std::uint8_t>
                                                                                             (this->dateTime_.time().minute())))
                                                    << this->getMinutes(min) << min;
                    }

                }
            }

        }


//        this->dateTime_ = (systemDateTime.isValid()) ? systemDateTime
//                                                     : QDateTime::fromString("Fri Jan 01 12:00:00 2021");


        qDebug() << "System time at boot: " << this->dateTime_.toString("ddd MMM dd hh:mm:ss yyyy")
                 << "After casted: " << systemDateTime.toString("ddd MMM dd hh:mm:ss yyyy");

        int val1;
        this->readDevice(YEAR_REG, val1);

        sec = static_cast<std::uint8_t>(val1 & SEC_BCD_FORMAT_MASK);

        if(!this->isRunning())
            this->start();

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

std::uint8_t DS1307::formatToBCD(std::uint8_t value){
    std::uint8_t shift = 0;
    std::uint8_t retVal = 0;
    while(value){
        retVal |= (value % 10) << (shift++ << 2);
        value /= 10;
    }
    return retVal;
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
    std:uint8_t sec = 0, min = 0, hour = 0, wday = 1,
                day = 0, month = 0, year = 0;

    Q_UNUSED(wday);

    if(this->isRunning()){
        ThrInput::instance().getThreadInstance().msleep(100);
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
    }
    return false;
}

bool DS1307::setDate(QDateTime currentDate)
{
    std:uint8_t sec, min, hour, day, month, year;

    Q_UNUSED(sec);

    if(currentDate.isValid()){
        int year_t = currentDate.date().year();

        if(year_t >= BASE_YEAR){
            year_t -= BASE_YEAR;
        }
        else{
            year_t = BASE_YEAR + 1;
        }
        if(!year_t) year_t = BASE_YEAR_OVF;   ///Fix this

        ///////TODO update System time...
        qDebug() << "Setting Time at: " << currentDate.time().toString("hh:mm");
        qDebug() << "Setting Date at: " << currentDate.date().toString("dd/MM/yyyy");

        qDebug()<< "Setting year: " << static_cast<std::uint8_t>(year_t);
        qDebug() << "Set Year: " << this->writeDevice(YEAR_REG,
                                                      DS1307::formatToBCD(static_cast<std::uint8_t>
                                                                          (year_t)))
                                  << this->getYear(year) << year;
        ThrInput::instance().getThreadInstance().msleep(10);
        qDebug() << "Set Month: " << this->writeDevice(MONTH_REG,
                                                       DS1307::formatToBCD(static_cast<std::uint8_t>
                                                                           (currentDate.date().month())))
                                  << this->getMonth(month) << month;
        ThrInput::instance().getThreadInstance().msleep(10);
        qDebug() << "Set Day: " << this->writeDevice(DAY_REG,
                                                     DS1307::formatToBCD(static_cast<std::uint8_t>
                                                                         (currentDate.date().day())))
                                << this->getDay(day) << day;
        ThrInput::instance().getThreadInstance().msleep(10);
        qDebug() << "Set Hour: " << this->writeDevice(HOURS_REG,
                                                      DS1307::formatToBCD(static_cast<std::uint8_t>
                                                                          (currentDate.time().hour())))
                                 << this->getHours(hour) << hour;
        ThrInput::instance().getThreadInstance().msleep(10);
        qDebug() << "Set Minutes: " << this->writeDevice(MINUTES_REG,
                                                         DS1307::formatToBCD(static_cast<std::uint8_t>
                                                                             (currentDate.time().minute())))
                                    << this->getMinutes(min) << min;
        this->dateTime_ = currentDate;
        return true;
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
    if(this->state_ == INACTIVE || !readDevice(SECONDS_REG, seconds)) return false;
    std::uint8_t secondFromBCD = DS1307::formatFromBCD(static_cast<std::uint8_t>(seconds) &
                                                       SEC_BCD_FORMAT_MASK);
    if(!(secondFromBCD >=  SEC_MIN && secondFromBCD <= SEC_MAX)){
        refValue = SEC_MIN;
        return false;
    }
    refValue = secondFromBCD;
    return true;
}

bool DS1307::getMinutes(std::uint8_t &refValue) {
    int minutes = 0;
    if(this->state_ == INACTIVE || !readDevice(MINUTES_REG, minutes)) return false;
    std::uint8_t minutesFromBCD = DS1307::formatFromBCD(static_cast<std::uint8_t>(minutes) &
                                                        MIN_BCD_FORMAT_MASK);
    if(!(minutesFromBCD >= MINUTES_MIN && minutesFromBCD <= MINUTES_MAX)){
        refValue = MINUTES_MIN;
        return false;
    }
    refValue = minutesFromBCD;
    return true;
}

bool DS1307::getHours(std::uint8_t &refValue) {
    int hours = 0;
    if(this->state_ == INACTIVE || !readDevice(HOURS_REG, hours)) return false;
    std::uint8_t hoursFromBCD = DS1307::formatFromBCD(static_cast<std::uint8_t>(hours) &
                                                      HOUR24_BCD_FORMAT_MASK);
    if(!(hoursFromBCD >= HOUR_MIN && hoursFromBCD <= HOUR_MAX)){
        refValue = HOUR_MIN;
        return false;
    }
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
    if(!(dayFromBCD >= DAY_MIN && dayFromBCD <= DAY_MAX)){
        refValue = DAY_MIN;
        return false;
    }
    refValue = dayFromBCD;
    return true;
}

bool DS1307::getMonth(std::uint8_t &refValue){
    int month = 0;
    if(this->state_ == INACTIVE || !readDevice(MONTH_REG, month)) return false;
    std::uint8_t monthFromBCD = DS1307::formatFromBCD(static_cast<std::uint8_t>(month) &
                                                      MONTH_BCD_FORMAT_MASK);
    if(!(monthFromBCD >= MONTH_MIN && monthFromBCD <= MONTH_MAX)){
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

    if(!(yearFromBCD >= YEAR_MIN && yearFromBCD <= YEAR_MAX)){
        refValue = YEAR_MIN;
        return false;
    }
    refValue = yearFromBCD;
    return true;
}
