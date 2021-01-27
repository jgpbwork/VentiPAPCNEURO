#ifndef DRVGPIO_H
#define DRVGPIO_H

#include "wiringPi.h"

///
/// \brief The DrvGpio class
///
class DrvGpio
{
public:
    ///
    /// \brief The GpioPinMode enum
    ///
    enum GpioPinMode{
         GPIO_OUT = OUTPUT,
         GPIO_IN  = INPUT
    };

    ///
    /// \brief The GpioPinLevel enum
    ///
    enum GpioPinLevel{
         GPIO_HIGH = HIGH,
         GPIO_LOW = LOW
    };

    ///
    /// \brief DrvGpio
    ///
    DrvGpio();

    ///
    /// \brief setup
    /// \param pinNumber
    /// \param pinMode
    ///
    void setup(int pinNumber, GpioPinMode mode = DrvGpio::GPIO_IN);



    void write(int pinNumber, GpioPinLevel pinLevel = DrvGpio::GPIO_LOW);
};



#endif // DRVGPIO_H
