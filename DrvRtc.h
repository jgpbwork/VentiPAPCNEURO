#ifndef DRVRTC_H
#define DRVRTC_H

#include "DrvI2C.h"


class DS1307 : public DrvI2C
{
public:
    DS1307();
    virtual ~DS1307();

    virtual bool Initialize();


    int getSeconds();
    int getMinutes();
    int getHours();

    int getWeekDay();
    int getDay();
    int getMonth();
    int getYear();



private:
    enum RegisterAddress{
         DEVICE_ID          = 0x68,
         HALT_REG           = 0x00,
         SECONDS_REG   = 0x00,
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

    bool state_;
    int identifier_;

    virtual bool readDevice(int regAdd, int &data);
    virtual bool writeDevice(int regAdd, int data);
};

#endif // DRVRTC_H
