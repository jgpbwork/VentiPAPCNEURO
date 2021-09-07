/**
 * Created by Ing. Luis Alejandro Reyes Morales on 8/12/2020.
 *
 * email: inglreyesm@gmail.com
 * github: https://github.com/lreyesm
 * linkedin: https://linkedin.com/in/luis-alejandro-reyes-morales-9b672012a
 *
 */

#ifndef IEEE_754_H
#define IEEE_754_H

#include <QByteArray>

#define NTH_BIT(b, n) ((b >> n) & 0x1)

#define BYTE_TO_BIN(b)   (( b & 0x80 ) ) |\
            (( b & 0x40 ) ) |\
            (( b & 0x20 ) ) |\
            (( b & 0x10 ) ) |\
            (( b & 0x08 ) ) |\
            (( b & 0x04 ) ) |\
            (( b & 0x02 ) ) |\
            ( b & 0x01 )

#define MANTISSA_TO_BIN(b)  (( b & 0x400000 ) ) |\
             (( b & 0x200000 ) ) |\
             (( b & 0x100000 ) ) |\
             (( b &  0x80000 ) ) |\
             (( b &  0x40000 ) ) |\
             (( b &  0x20000 ) ) |\
             (( b &  0x10000 ) ) |\
             (( b &  0x8000 ) ) |\
             (( b &  0x4000 ) ) |\
             (( b &  0x2000 ) ) |\
             (( b &  0x1000 ) ) |\
             (( b &  0x800 ) ) |\
             (( b &  0x400 ) ) |\
             (( b &  0x200 ) ) |\
             (( b &  0x100 ) ) |\
             (( b &  0x80 ) ) |\
             (( b &  0x40 ) ) |\
             (( b &  0x20 ) ) |\
             (( b &  0x10 ) ) |\
             (( b &  0x08 ) ) |\
             (( b &  0x04 ) ) |\
             (( b &  0x02 ) ) |\
              ( b & 0x01 )

class IEEE_754
{

    typedef union UnFloatingPointIEEE754
    {
    struct
     {
      unsigned int mantissa : 23;
      unsigned int exponent : 8;
      unsigned int sign : 1;
     } raw;
   float f;
   } UFloatingPointIEEE754;

public:
    IEEE_754();
    static QByteArray changeEndianess(QByteArray bytes);
    static QByteArray convert_Uint32To_Bytes(uint32_t value);
    static uint32_t convert_Bytes_To_Uint32(QByteArray bytes);
    static uint32_t convertirA_754_32(float f);
    static float convertirDesde_754_32(uint32_t floatingToIntValue);
    static void changeEndianess(uint8_t *bytes, unsigned int size= 4);
    static void convertUint32ToUintArray(uint32_t uint32_value, uint8_t *buf_8b);
    static void convertByteArrayToUintArray(QByteArray byte_array, uint8_t *buf_8b, int size = 0);
    static QByteArray convertUintArrayToByteArray(uint8_t *buf_8b, int size);
};

#endif // IEEE_754_H
