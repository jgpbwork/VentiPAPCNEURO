#ifndef DRVGAUGE_H
#define DRVGAUGE_H

#include "DrvI2C.h"
#include <QtCore>

class LTC2942 : public DrvI2C {
public:
    LTC2942();
    virtual ~LTC2942();

    /// DrvI2C interface
    virtual bool Initialize();
    virtual bool readDevice(int regAdd, int &data);
    virtual bool writeDevice(int regAdd, int data);


    void setCharge(std::float_t charge);
    std::float_t getBattLvl();

    bool powerDown();
    bool powerUp();

    bool readTemperature(std::float_t &refValue);
    bool readVoltage(std::float_t &refValue);
    bool readCharge(std::uint16_t &refValue);

    bool setChargeRegister(std::uint16_t charge);

    std::float_t ToEngValue(std::uint16_t adcVoltVal);

    enum RegisterAddress{
         DEVICE_ID          = 0x64,
         STATUS_REG         = 0x00,
         CONTROL_REG        = 0x01,
         CHARGE_CUMUL_H     = 0x02,
         CHARGE_CUMUL_L     = 0x03,
         CHARGE_THRES_HH    = 0x04,
         CHARGE_THRES_HL    = 0x05,
         CHARGE_THRES_LH    = 0x06,
         CHARGE_THRES_LL    = 0x07,
         VOLTAGE_H          = 0x08,
         VOLTAGE_L          = 0x09,
         VOLT_THRES_H       = 0x0A,
         VOLT_THRES_L       = 0x0B,
         TEMPERATURE_H      = 0x0C,
         TEMPERATURE_L      = 0x0D,
         TEMP_THRES_H       = 0x0E,
         TEMP_THRES_L       = 0x0F,
         BYTE_MASK          = 0xFF
    };


    enum Prescaler{
         M1     = 0,
         M2     = 1,
         M4     = 2,
         M8     = 3,
         M16    = 4,
         M32    = 5,
         M64    = 6,
         M128   = 7,
         PRESCALER_MASK  = 0x38,
         PRESCALER_SHIFF = 3
    };

    enum AdcMode{
         SLEEP = 0,
         TEMP_SINGLE_CONV = 1,
         VOLTAGE_SINGLE_CONV = 2,
         AUTO_MODE           = 3,
         MODE_MASK           = 0xC0,
         MODE_SHIFF          = 6
    };

    enum AlertOnPin{
         DISABLE            = 0,
         CHARGE_CMP_IN      = 1,
         ALERT_OUTPUT       = 2,
         ALERT_CHARGE_MASK  = 0x06,
         ALERT_CHARGE_SHIFF = 1
    };

    enum Shutdown{
         SHUTDOWN = 1
    };

    struct ControlReg{
        std::uint8_t AdcMode        : 2;
        std::uint8_t Prescaler      : 3;
        std::uint8_t AlertCharge    : 2;
        std::uint8_t Shutdown       : 1;

        ControlReg() : AdcMode(LTC2942::SLEEP),
                       Prescaler(LTC2942::M128),
                       AlertCharge(LTC2942::ALERT_OUTPUT),
                       Shutdown(0)
        {}

        std::uint8_t value() {
            return static_cast<std::uint8_t>(
                     (AdcMode << 6)       |
                     (Prescaler << 3)     |
                     (AlertCharge << 1)   |
                      Shutdown);
        }
    }controlReg;

private:
    std::uint16_t temperature_;
    std::uint16_t voltage_;
    std::uint16_t charge_;

    std::uint8_t statusReg_;

    static const std::uint8_t VOLT_TO_ENG = 6;
    static const std::uint16_t TEMP_TO_ENG = 600;
    static const std::uint16_t KELVIN_TO_CELSIUS = 273;

    static std::float_t load_;
    static std::float_t limitLoad_;
    static std::float_t loadDt_;

    bool state_;
    int identifier_;

    void setCtrlReg(std::uint8_t data);

};

#endif // DRVGAUGE_H
