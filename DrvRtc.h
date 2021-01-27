#ifndef DRVRTC_H
#define DRVRTC_H

#include "DrvI2C.h"
#include <QDateTime>

class DS1307 : public DrvI2C
{
public:
    DS1307();
    virtual ~DS1307();

    virtual bool Initialize();

    QDateTime &getDateTime();

    static std::uint8_t formatFromBCD(std::uint8_t value);
    static std::uint8_t formatToBCD(std::uint8_t value);

    bool stop();
    bool start();

    bool update();

    bool isRunning();
private:
    enum RegisterAddress{
         DEVICE_ID          = 0x68,
         HALT_REG           = 0x00,
         SECONDS_REG        = 0x00,
         MINUTES_REG        = 0x01,
         HOURS_REG          = 0x02,
         WEEK_DAY_REG       = 0x03,
         DAY_REG            = 0x04,
         MONTH_REG          = 0x05,
         YEAR_REG           = 0x06,
         CTRL_REG           = 0x07,
         HALT_CLK           = 0x80,
         RATE_SELECT_1Hz    = 0x00,
        RATE_SELECT_4kHz    = 0x01,
        RATE_SELECT_8kHz    = 0x02,
        RATE_SELECT_32kHz   = 0x03,
        SQUARE_WAVE_ENABLED = 0x10,
        OUTPUT_ON_SQW_OUT   = 0x80
    };

    enum Settings{
        BASE_YEAR           = 0x07D0, ///Valid Leap year range from 2001 to 2100.
        BASE_YEAR_OVF       = 0x64,   ///Year 2000 is to be casted to 2100.
        YEAR_MIN            = 0x00,
        YEAR_MAX            = 0x99,
        MONTH_MIN           = 0x01,
        MONTH_MAX           = 0x12,
        DAY_MIN             = 0x01,
        DAY_MAX             = 0x31,
        WDAY_MIN            = 0x01,
        WDAY_MAX            = 0x07,
        HOUR_MIN            = 0x00,
        HOUR_MAX            = 0x23,
        MINUTES_MIN         = 0x00,
        MINUTES_MAX         = 0x59,
        SEC_MIN             = 0x00,
        SEC_MAX             = 0x59,
        HOUR_FORMAT_12      = 0x40,
        SEC_BCD_FORMAT_MASK = 0x7F,
        MIN_BCD_FORMAT_MASK = 0x7F,
        HOUR24_BCD_FORMAT_MASK  = 0x3F,
        WDAY_BCD_FORMAT_MASK    = 0x07,
        DAY_BCD_FORMAT_MASK     = 0x3F,
        MONTH_BCD_FORMAT_MASK   = 0x1F,
        YEAR_BCD_FORMAT_MASK    = 0xFF


    };

    bool state_;
    bool isRunning_;
    int identifier_;

    QDateTime dateTime_;


    virtual bool readDevice(int regAdd, int &data);
    virtual bool writeDevice(int regAdd, int data);


    bool getSeconds(std::uint8_t &refValue);
    bool getMinutes(std::uint8_t &refValue);
    bool getHours(std::uint8_t &refValue);

    int getWeekDay();
    bool getDay(std::uint8_t &refValue);
    bool getMonth(std::uint8_t &refValue);
    bool getYear(std::uint8_t &refValue);

};



#endif // DRVRTC_H
