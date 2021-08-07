#include "DrvAdc.h"
#include "ThrInput.h"
#include "IEEE754.h"
#include <wiringPiI2C.h>
#include <QDebug>

const std::float_t ADS1115::HARDWARE_GAIN = 45.5f;

ADS1115::ADS1115() : state_(INACTIVE), identifier_(0), gain(1.0f)
{}

ADS1115::~ADS1115(){}

bool ADS1115::Initialize() {
    volatile int configReg = 0;
    std::uint16_t regValue = 0;

    this->resetDevice();
    this->identifier_ = wiringPiI2CSetup(DEVICE_ID);
    this->state_ = (this->identifier_ == -1) ? INACTIVE : ACTIVE;
    if(this->state_ == ACTIVE) {
        configReg = wiringPiI2CReadReg16(this->identifier_, CONFIGURE_REG);
        regValue = static_cast<std::uint16_t>(configReg);
        IEEE_754::changeEndianess(reinterpret_cast<std::uint8_t*>(&regValue), sizeof (regValue));
        this->regValue_.OpStatusSingleStart = ~START_SINGLE_CONVERSION;
//            regValue_.OpStatusSingleStart = static_cast<std::bit_not<uint8_t>>(1);
        this->regValue_.Gain = FULL_SCALE_4V;
        this->regValue_.Multiplexer = SINGLE_ENDED_CH0;
        this->regValue_.DataRate = SPS_860;
        std::uint16_t regValue_ON = *reinterpret_cast<std::uint16_t*>(&this->regValue_);
        IEEE_754::changeEndianess(reinterpret_cast<std::uint8_t*>(&regValue_ON), sizeof (regValue_ON));
        //OS_START_SINGLE_CONVERSION | MUX_CH0_SINGLE_ENDED |
        //                       GAIN_1 | MODE_SINGLE_SHOT_POWER_DWN | DATA_RATE_860 |
        //                       DISABLE_COMPARATOR;
        wiringPiI2CWriteReg16(this->identifier_, CONFIGURE_REG,
                              regValue_ON);

        configReg = wiringPiI2CReadReg16(this->identifier_, CONFIGURE_REG);
        regValue = static_cast<std::uint16_t>(configReg);
        IEEE_754::changeEndianess(reinterpret_cast<std::uint8_t*>(&regValue), sizeof (regValue));
        this->setGain(FULL_SCALE_4V);
        //std::uint16_t adcData = this->readData();
        qDebug() << "ADC configure register: " << regValue
                 << " size: " << sizeof(regValue);
    }
    return (this->identifier_ == -1);
}

bool ADS1115::readDevice(int regAdd, int &data){
     if(this->identifier_ == INACTIVE) return false;
     data = wiringPiI2CReadReg16(this->identifier_, regAdd);
     return (data != -1);
}

bool ADS1115::writeDevice(int regAdd, int data){
    int retVal = 0;
    if(this->identifier_ == INACTIVE) return false;

    retVal = wiringPiI2CWriteReg16(this->identifier_, regAdd, data);
    return (retVal != -1);
}

bool ADS1115::readData(std::uint16_t &dataReg){
    this->startSingleConversion();
    int data = 0;
    if(!this->readDevice(ADS1115::CONVERSION_REG, data))
        return false;
    dataReg = static_cast<std::uint16_t>(data);
    IEEE_754::changeEndianess(reinterpret_cast<std::uint8_t*>(&dataReg), sizeof (dataReg));
    return true;
}

/// TODO To be implemented throught general Address Call (0x00) plus (0x06 command.
/// Is not working...
bool ADS1115::resetDevice(){
    int resetIdentifier_ = wiringPiI2CSetup(GENERAL_CALL_ADD);
    int retVal = wiringPiI2CReadReg16(resetIdentifier_, 0x06);

    std::uint16_t resetReg = 0;
    //wiringPiI2CReadReg16(resetIdentifier_, resetReg);
    return true;
}

bool ADS1115::startSingleConversion(){
    int data;
    if(!this->readDevice(ADS1115::CONFIGURE_REG, data)) return false;
    std::uint16_t regData = static_cast<std::uint16_t>(data);
    IEEE_754::changeEndianess(reinterpret_cast<std::uint8_t*>(&regData), sizeof (regData));
    if(regData & OS_START_SINGLE_CONVERSION) ///Device is on PowerDown
        this->regValue_.OpStatusSingleStart = START_SINGLE_CONVERSION;

    regData = *reinterpret_cast<std::uint16_t*>(&this->regValue_);
    IEEE_754::changeEndianess(reinterpret_cast<std::uint8_t*>(&regData), sizeof (regData));
    if(!this->writeDevice(ADS1115::CONFIGURE_REG, static_cast<int>(regData))) return false;

    ThrInput::instance().getThreadInstance().msleep(10);    /// TODO wait for end of convertion...

    return true;
}

std::float_t ADS1115::ToEngValue(std::uint16_t adcRegValue){
    std::float_t voltageInput = 0;
    std::uint32_t data = static_cast<std::uint32_t>(static_cast<std::uint16_t>(this->gain * 1000.0f) * adcRegValue);
    std::uint32_t data1 = static_cast<std::uint32_t>(65536 * static_cast<std::uint16_t>(HARDWARE_GAIN * 10.0f));
    std::float_t val = static_cast<std::float_t>(data) / static_cast<std::float_t>(data1) / 100.0f;
    voltageInput = static_cast<std::float_t>(static_cast<std::float_t>(this->gain) * static_cast<float>(adcRegValue)) /
                   static_cast<std::float_t>((static_cast<std::float_t>(ADC_RESOLUTION) * static_cast<std::float_t>(HARDWARE_GAIN)));

//    std::uint32_t data = static_cast<std::uint32_t>(voltageInput);
//    voltageInput = (std::float_t)data / (float_t)ADC_RESOLUTION;
//    voltageInput = static_cast<std::float_t>(data) / HARDWARE_GAIN;
//    voltageInput = static_cast<std::float_t>((static_cast<std::uint32_t>
//                                             (this->gain * static_cast<std::float_t>(adcRegValue)) >>
//                                             ADC_RESOLUTION)) / HARDWARE_GAIN;
    return val;
}

void ADS1115::setGain(ProgramableGainConfigure regGain){
    switch(regGain)
    {
    case ADS1115::FULL_SCALE_6V:
            this->gain = 2.0f * 6.114f;
        break;
    case FULL_SCALE_4V:
            this->gain = 2.0f * 4.096f;
        break;
    case FULL_SCALE_2V:
            this->gain = 2.0f * 2.048f;
        break;
    case FULL_SCALE_1V:
            this->gain = 2.0f * 1.024f;
        break;
    case FULL_SCALE_0V5:
            this->gain = 2.0f * 0.512f;
        break;
    case FULL_SCALE_0V2:
    case FULL_SCALE_0V22:
    case FULL_SCALE_0V222:
            this->gain = 2.0f * 0.256f;
        break;
    default:
        break;
    }
}
