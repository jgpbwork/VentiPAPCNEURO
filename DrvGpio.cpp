#include "DrvGpio.h"

DrvGpio::DrvGpio()
{
    wiringPiSetupPhys();
}

void DrvGpio::setup(int pinNumber, GpioPinMode mode)
{
    return pinMode(pinNumber, static_cast<int>(mode));
}

void DrvGpio::write(int pinNumber, GpioPinLevel level)
{
    return digitalWrite(pinNumber, static_cast<int>(level));
}
