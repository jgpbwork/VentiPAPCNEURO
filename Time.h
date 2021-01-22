#ifndef TIME_H
#define TIME_H

#include "QMath.h"

#define MICRO_SECONDS 1000000

class Time
{
public:
    Time();

    static std::uint32_t secondsToMicroseconds(float_t value);

};

#endif // TIME_H
