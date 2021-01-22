#include "DrvGauge.h"
#include "IEEE754.h"
#include <wiringPiI2C.h>

LTC2942::LTC2942() : controlReg(), temperature_(0),
                     voltage_(0), statusReg_(0),
                     state_(INACTIVE), identifier_(0)
{}

LTC2942::~LTC2942(){}

bool LTC2942::Initialize()
{
    int data = 0;
    this->identifier_ = wiringPiI2CSetup(DEVICE_ID);
    this->state_ = (this->identifier_ == -1) ? INACTIVE : ACTIVE;
    if(this->state_ == ACTIVE) {
        this->readDevice(CONTROL_REG, data);
        if(data != -1) {
            this->setCtrlReg(static_cast<std::uint8_t>(data));
            if(this->controlReg.AlertCharge != CHARGE_CMP_IN) {
                this->controlReg.AlertCharge = CHARGE_CMP_IN;
                this->controlReg.AdcMode = AUTO_MODE;
                std::uint8_t val = this->controlReg.value();
                this->writeDevice(CONTROL_REG, val);
            }
        }
        if(readDevice(STATUS_REG, data)){
            this->statusReg_ = static_cast<std::uint8_t>(data);
        }
        if(this->readDevice(CONTROL_REG, data)) {
            std::uint16_t val = static_cast<std::uint16_t>(data);
        }
    }

    return true;
}

void LTC2942::setCtrlReg(std::uint8_t data) {
    this->controlReg.AdcMode = ((data & MODE_MASK) >> MODE_SHIFF);
    this->controlReg.Prescaler = ((data & PRESCALER_MASK) >> PRESCALER_SHIFF);
    this->controlReg.AlertCharge = ((data & ALERT_CHARGE_MASK) >> ALERT_CHARGE_SHIFF);
    this->controlReg.Shutdown = (data & SHUTDOWN);
}

bool LTC2942::powerDown() {
    this->controlReg.Shutdown = SHUTDOWN;
    return this->writeDevice(CONTROL_REG, *reinterpret_cast<int*>(&this->controlReg));
}

bool LTC2942::powerUp() {
    this->controlReg.Shutdown = static_cast<std::uint8_t>(~SHUTDOWN);
    return this->writeDevice(CONTROL_REG, *reinterpret_cast<int*>(&this->controlReg));
}

std::uint16_t LTC2942::readTemperature() {
    std::uint8_t lowByte, highByte;
    int data = 0;
    if(this->readDevice(TEMPERATURE_L, data)) {
        lowByte = static_cast<std::uint8_t>(data);
    }
    if(this->readDevice(TEMPERATURE_H, data)) {
        highByte = static_cast<std::uint8_t>(data);
    }
    this->temperature_ = (static_cast<std::uint16_t>(highByte) << 8) |
                         (static_cast<std::uint16_t>(lowByte));
    return this->temperature_;
}

std::uint16_t LTC2942::readVoltage() {
    std::uint8_t lowByte = 0, highByte = 0;
    int data = 0;
    if(this->readDevice(VOLTAGE_L, data)) {
        lowByte = static_cast<std::uint8_t>(data);
    }
    if(this->readDevice(VOLTAGE_H, data)) {
        highByte = static_cast<std::uint8_t>(data);
    }
    this->voltage_ = (static_cast<std::uint16_t>(highByte) <<
                      static_cast<std::uint16_t>(8)) |
                     (static_cast<std::uint16_t>(lowByte));
    return this->voltage_;
}

std::float_t LTC2942::ToEngValue(std::uint16_t adcVoltVal) {
    std::float_t retVal = 0.0f;
    retVal = static_cast<std::float_t>(LTC2942::VOLT_TO_ENG * adcVoltVal) /
             static_cast<std::float_t>(LTC2942::MAX_BITS16);
    return retVal;
}

bool LTC2942::readDevice(int regAdd, int &data) {
    if(this->state_ == INACTIVE) return false;
    data = wiringPiI2CReadReg8(this->identifier_, regAdd);
    return (data != -1);
}

bool LTC2942::writeDevice(int regAdd, int data) {
    if(this->identifier_ == INACTIVE) return false;
    return (wiringPiI2CWriteReg8(this->identifier_, regAdd, data) != -1);
}
