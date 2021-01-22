#include "DrvRtc.h"
#include <wiringPiI2C.h>

DS1307::DS1307(){}

DS1307::~DS1307(){}

bool DS1307::Initialize() {
    this->identifier_ = wiringPiI2CSetup(DEVICE_ID);
    this->state_ = (this->identifier_ == -1) ? INACTIVE : ACTIVE;
    if(this->state_ == ACTIVE){
        int ctrlReg = wiringPiI2CWriteReg8(this->identifier_, CTRL_REG, RATE_SELECT_4kHz | SQUARE_WAVE_ENABLED);
        wiringPiI2CWriteReg8(this->identifier_, HALT_REG, HALT_CLK);
        int isHalt = wiringPiI2CReadReg8(this->identifier_, HALT_REG);
        if((isHalt & HALT_CLK)) {
            wiringPiI2CWriteReg8(this->identifier_, HALT_REG, (isHalt & ~HALT_CLK));
            int seconds = wiringPiI2CReadReg8(this->identifier_, SECONDS_REG);
        }
    }
    return (this->identifier_ == -1);
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


int DS1307::getSeconds(){
    int seconds = 0;
    if(this->state_ == INACTIVE || !readDevice(SECONDS_REG, seconds))
        return -1;
    return seconds;
}

int DS1307::getMinutes() {
    int minutes = 0;
    if(this->state_ == INACTIVE || !readDevice(MINUTES_REG, minutes))
        return -1;
    return minutes;
}

int DS1307::getHours() {
    int hours = 0;
    if(this->state_ == INACTIVE || !readDevice(HOURS_REG, hours))
        return -1;
    return hours;
}

int DS1307::getWeekDay(){
    int weekDay = 0;
    if(this->state_ == INACTIVE || !readDevice(WEEK_DAY_REG, weekDay))
        return -1;
    return weekDay;
}

int DS1307::getDay(){
    int day = -1;
    if(this->state_ == INACTIVE || !readDevice(DAY_REG, day))
        return -1;
    return day;
}

int DS1307::getMonth(){
    int month = 0;
    if((this->state_ == INACTIVE) ||
       !(readDevice(MONTH_REG, month)))
        return -1;
    return month;
}

int DS1307::getYear(){
    int year = 0;
    if(this->state_ == INACTIVE || !readDevice(YEAR_REG, year))
        return -1;
    return year;
}
