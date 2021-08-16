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

    ///
    /// \brief write
    /// \param pinNumber  The number for the GPIO to modified.
    /// \param pinLevel The value to be written in the GPIO. Posible values comes from @ref GpioPinLevel. 
    ///        Defaul value if non is set is @ref DrvGpio::GpioPinLevel "GPIO_LOW".
    void write(int pinNumber, GpioPinLevel pinLevel = DrvGpio::GPIO_LOW);


    ///
    /// \brief read
    /// \param pinNumber  The number for the GPIO to be read.
    /// \return The level for read GPIO.
    int read(int pinNumber);
};
#endif // DRVGPIO_H
