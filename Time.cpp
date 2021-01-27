#include "Time.h"

Time::Time()
{}

std::uint32_t Time::secondsToMicroseconds(float_t value){
    std::uint32_t retVal = static_cast<std::uint32_t>(value * MICRO_SECONDS);
    Q_ASSERT(retVal > 0);
    return retVal;
}
