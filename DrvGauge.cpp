#include "DrvGauge.h"
#include "IEEE754.h"
#include <wiringPiI2C.h>

std::float_t LTC2942::load_ = 100.0f;
std::float_t LTC2942::limitLoad_ = 100.0f;
std::float_t LTC2942::loadDt_;

const std::float_t LTC2942::BATT_CAPACITY = 1900.0f;
const std::float_t LTC2942::COULOMBS_CAPACITY_RATE = 3.6f;
const std::float_t LTC2942::BATT_CHARGE_REG_RESOLUTION = 0.104371f;

LTC2942::LTC2942() : controlReg(), status(BATT_CAPACITY * COULOMBS_CAPACITY_RATE / 20.0f), ///Assumes battery is at 5% -> (Full charge / 20)
                     temperature_(0), voltage_(0), statusReg_(0),
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
                this->controlReg.Prescaler = Prescaler::M64;
                this->controlReg.AdcMode = AUTO_MODE;
                std::uint8_t val = this->controlReg.value();
                this->writeDevice(CONTROL_REG, this->controlReg.value());
            }
        }
        this->setCharge(this->status.load);
        if(readDevice(STATUS_REG, data)){
            this->statusReg_ = static_cast<std::uint8_t>(data);
        }
        if(this->readDevice(CONTROL_REG, data)) {
            std::uint16_t val = static_cast<std::uint16_t>(data);
        }
    }

    std::float_t currentLoad = (this->readVoltage(currentLoad)) ? currentLoad * BATT_CHARGE_REG_RESOLUTION : 0.0f;

    if (currentLoad > LTC2942::limitLoad_)
       LTC2942::limitLoad_ = currentLoad;

    return true;
}

void LTC2942::setCtrlReg(std::uint8_t data) {
    this->controlReg.AdcMode = ((data & MODE_MASK) >> MODE_SHIFF);
    this->controlReg.Prescaler = ((data & PRESCALER_MASK) >> PRESCALER_SHIFF);
    this->controlReg.AlertCharge = ((data & ALERT_CHARGE_MASK) >> ALERT_CHARGE_SHIFF);
    this->controlReg.Shutdown = (data & SHUTDOWN);
}

bool LTC2942::getCtrlReg(std::uint8_t &value){
    int data = 0;
    if (this->readDevice(CONTROL_REG, data)){
        value = static_cast<std::uint8_t>(data);
        this->controlReg = *reinterpret_cast<LTC2942::ControlReg*>(&value);
        if(this->controlReg.Shutdown){
            this->controlReg.AdcMode = LTC2942::AUTO_MODE;
            this->controlReg.Shutdown = ~LTC2942::SHUTDOWN;
            value = this->controlReg.value();
            return this->writeDevice(CONTROL_REG, value);
        }
        return true;
    }
    return false;
}

void LTC2942::setCharge(std::float_t charge) {
     std::uint16_t chargeReg = static_cast<std::uint16_t>((charge / BATT_CHARGE_REG_RESOLUTION));
     this->powerDown();
     this->setChargeRegister(chargeReg);
     this->powerUp();
     std::uint16_t chargeRegBack = 0;
     if(this->readCharge(chargeRegBack))
         return;
         ///TODO signal error

}

std::float_t LTC2942::getBattLvl() {
    std::float_t retVal =  0.0f;
    retVal = ((LTC2942::load_ - LTC2942::limitLoad_) / ((LTC2942::BATT_CAPACITY * LTC2942::COULOMBS_CAPACITY_RATE) - LTC2942::limitLoad_)) * 100.0f;
    LTC2942::loadDt_ = retVal;
    if(retVal > 100.0f)
        return 100.0f;
    else if (retVal < 0.0f)
        return 0.0f;
    else {
        return retVal;
    }
}

std::float_t LTC2942::getLoad() {
    return this->status.load;
}

std::float_t LTC2942::getIntensityCurrent() {
    return this->status.current;
}

bool LTC2942::powerDown() {
    this->controlReg.Shutdown = SHUTDOWN;
    return this->writeDevice(CONTROL_REG, *reinterpret_cast<int*>(&this->controlReg));
}

bool LTC2942::powerUp() {
    this->controlReg.Shutdown = static_cast<std::uint8_t>(~SHUTDOWN);
    return this->writeDevice(CONTROL_REG, *reinterpret_cast<int*>(&this->controlReg));
}

bool LTC2942::readTemperature(std::float_t &refValue) {
    int dataL = 0, dataH = 0;
    if(this->readDevice(TEMPERATURE_H, dataH) &&
       this->readDevice(TEMPERATURE_L, dataL)) {
        this->temperature_ = ((static_cast<std::uint16_t>(dataH) << 8) |
                               static_cast<std::uint16_t>(dataL));
        refValue = (((static_cast<std::float_t>(this->temperature_) /
                      static_cast<std::float_t>(UINT16_MAX)) *
                      static_cast<std::float_t>(TEMP_TO_ENG)) -
                      static_cast<std::float_t>(KELVIN_TO_CELSIUS));
        return true;
    }
    refValue = 0.0f;
    return false;
}

bool LTC2942::readVoltage(std::float_t &refValue) {
    int dataL = 0, dataH = 0;
    if(this->readDevice(VOLTAGE_H, dataH) &&
       this->readDevice(VOLTAGE_L, dataL)) {
        this->voltage_ = ((static_cast<std::uint16_t>(dataH) << 8) |
                           static_cast<std::uint16_t>(dataL));
        refValue = ((static_cast<std::float_t>(this->voltage_) /
                     static_cast<std::float_t>(UINT16_MAX)) *
                     static_cast<std::float_t>(LTC2942::VOLT_TO_ENG));
        return true;
    }
    refValue = -1.0f;
    return false;
}

bool LTC2942::readCharge(std::uint16_t &refValue){
    int dataL = 0, dataH = 0;
    if(this->readDevice(CHARGE_CUMUL_H, dataH) &&
       this->readDevice(CHARGE_CUMUL_L, dataL)){
        this->charge_ = ((static_cast<std::uint16_t>(dataH) << 8) |
                         static_cast<std::uint16_t>(dataL));
        refValue = this->charge_;
        return true;
    }
    return false;
}



bool LTC2942::setChargeRegister(std::uint16_t charge) {
    std::uint8_t regLow, regHigh;
    regLow = static_cast<std::uint8_t>(charge);
    regHigh = static_cast<std::uint8_t>(charge >> 8);
    if(this->writeDevice(CHARGE_CUMUL_H, regHigh) &&
       this->writeDevice(CHARGE_CUMUL_L, regLow)) {
        return true;
    }
    return false;
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
