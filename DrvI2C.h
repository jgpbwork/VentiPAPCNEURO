#ifndef DRVI2C_H
#define DRVI2C_H

#include <QtCore>

class DrvI2C
{
public:
    DrvI2C();
    virtual ~DrvI2C();

    virtual bool Initialize() = 0;

    virtual bool readDevice(int regAdd, int &data) = 0;
    virtual bool writeDevice(int regAdd, int data) = 0;

    void byteSwap(std::uint8_t &byte);

    enum DeviceSate{
         INACTIVE,
         ACTIVE
    };

    static const std::uint32_t MAX_BITS16 = 65536;
};

inline void DrvI2C::byteSwap(std::uint8_t &byte) {
    std::uint8_t low, high;
    low = ((byte & (std::uint8_t)0xF0) >> 4);
    high = ((byte & (std::uint8_t)0x0F) << 4);
    std::uint8_t local = high | low;
    byte = local;
}
#endif // DRVI2C_H
