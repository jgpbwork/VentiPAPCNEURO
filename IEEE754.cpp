/**
 * Created by Ing. Luis Alejandro Reyes Morales on 8/12/2020.
 *
 * email: inglreyesm@gmail.com
 * github: https://github.com/lreyesm
 * linkedin: https://linkedin.com/in/luis-alejandro-reyes-morales-9b672012a
 *
 */

#include "IEEE754.h"
/**
 * IEEE_754 :: IEEE_754
 * 
 * Constructor of static class for proccessing IEEE_754 values
 */
IEEE_754::IEEE_754()
{}

/**
 * IEEE_754 :: convertUintArrayToByteArray
 * 
 * Converts uint8_t* array buffer to QByteArray Qt type
 *
 * @param  {uint8_t*} buf_8b : Pointer to the buffer to convert
 * @param  {int} size        : Size of the array buffer to convert
 * @return {QByteArray}      : QByteArray Qt type with the converted value
 */
QByteArray IEEE_754::convertUintArrayToByteArray(uint8_t* buf_8b, int size){
    QByteArray bytesArray;
    for (int i=0; i < size ;++i){
        bytesArray.append(static_cast<char>(buf_8b[i]));
    }
    return bytesArray;
}

/**
 * IEEE_754 :: convertUint32ToUintArray 
 * 
 * Converts uint32_t containing array buffer of uint8_t[4] to uint8_t*
 *
 * @param  {uint32_t} value  : uint32_t containing array buffer of uint8_t[4]
 * @param  {uint8_t*} buf_8b : Pointer to the converted buffer  
 */
void IEEE_754::convertUint32ToUintArray(uint32_t value, uint8_t* buf_8b){
    for (int i=0; i<4 ;++i){
        buf_8b[i] = (reinterpret_cast<uint8_t*>(&value))[3 - i];//(uint8_t*)(&value))[3-i];
    }
}

/**
 * IEEE_754 :: convertByteArrayToUintArray 
 * 
 * Converts QByteArray Qt type buffer to uint8_t* array buffer
 *
 * @param  {QByteArray} byte_array : QByteArray Qt type with the value to be converted 
 * @param  {uint8_t*} buf_8b       : Pointer to the converted buffer  
 * @param  {int} size              : Size of the bytes in byte_array: QByteArray to convert
 */
void IEEE_754::convertByteArrayToUintArray(QByteArray byte_array, uint8_t* buf_8b, int size){
    if(size <= 0){
        size = byte_array.size();
    }
    for (int i = 0; i < size; i++) {
        buf_8b[i] = static_cast<uint8_t>(byte_array.at(i));
    }
}

/**
 * IEEE_754 :: changeEndianess 
 * 
 * Change the endianness of QByteArray Qt type buffer
 *
 * @param  {QByteArray} bytes : QByteArray Qt type buffer to change
 * @return {QByteArray}       : Converted QByteArray Qt type buffer with the new endianness
 */
QByteArray IEEE_754::changeEndianess(QByteArray bytes){
    QByteArray bytes_reverse;
    for (int i=0; i < bytes.size(); i++) {
        bytes_reverse.prepend(bytes.at(i));
    }
    return bytes_reverse;
}

/**
 * IEEE_754 :: changeEndianess 
 * 
 * Change the endianness of uint8_t* array buffer
 *
 * @param  {uint8_t*} bytes : Pointer to the uint8_t* array buffer to change
 * @param  {unsigned} int   : size of the uint8_t* array buffer
 */
void IEEE_754::changeEndianess(uint8_t* bytes, unsigned int size){
    uint8_t* bytes_reverse = new uint8_t[size];
    unsigned int c = size - 1;
    for (unsigned int i=0; i < size; i++) {
        bytes_reverse[i] = bytes[c];
        c--;
    }
    for (unsigned int i=0; i < size; i++) {
        bytes[i] = bytes_reverse[i];
    }
}

/**
 * IEEE_754 :: convert_Uint32To_Bytes 
 *
 * Converts uint32_t containing array buffer of uint8_t[4] to QByteArray Qt type buffer
 *
 * @param  {uint32_t} value : uint32_t containing array buffer of uint8_t[4]
 * @return {QByteArray}     : Converted QByteArray Qt type buffer
 */
QByteArray IEEE_754::convert_Uint32To_Bytes(uint32_t value){

    QByteArray bytes;
    bytes.append((value >> 24) & 0xFF);
    bytes.append((value >> 16) & 0xFF);
    bytes.append((value >> 8 ) & 0xFF);
    bytes.append(value & 0xFF);
    return bytes;
}

/**
 * IEEE_754 :: convert_Bytes_To_Uint32 
 * 
 * Converts  QByteArray Qt type buffer to uint32_t containing array buffer of uint8_t[4] 
 *
 * @param  {QByteArray} bytes : QByteArray Qt type buffer to convert
 * @return {uint32_t}         : Converted uint32_t containing array buffer of uint8_t[4] 
 */
uint32_t IEEE_754::convert_Bytes_To_Uint32(QByteArray bytes){
    uint32_t value;
    value = (0xFF & (uint8_t)bytes.at(0));
    value = (value << 8) & 0xFF00;

    value = (value | (uint8_t)bytes.at(1));
    value = (value << 8) & 0xFFFF00;

    value = (value | (uint8_t)bytes.at(2));
    value = (value << 8) & 0xFFFFFF00;

    value = (value | (uint8_t)bytes.at(3));

    return value;
}

/**
 * IEEE_754 :: convertirA_754_32 
 * 
 * Converts Floating point in IEEE_754 to uint32_t containing array buffer of uint8_t[4] 
 *
 * @param  {float} f   : Floating point in IEEE_754 value to convert
 * @return {uint32_t}  : Converted uint32_t containing array buffer of uint8_t[4] 
 */
uint32_t IEEE_754::convertirA_754_32 ( float f )
{
    UFloatingPointIEEE754 ieee754;
    uint32_t    floatingToIntValue = 0;
    ieee754.f = f;
    floatingToIntValue = (((NTH_BIT(ieee754.raw.sign, 0) << 8) |
                           (BYTE_TO_BIN(ieee754.raw.exponent)))  << 23 ) | MANTISSA_TO_BIN(ieee754.raw.mantissa);
    return floatingToIntValue;
}

/**
 * IEEE_754 :: convertirDesde_754_32 
 * 
 * Converts uint32_t containing array buffer of uint8_t[4] to Floating point in IEEE_754 
 *
 * @param  {uint32_t} floatingToIntValue : uint32_t containing array buffer of uint8_t[4] to convert
 * @return {float}                       : Converted Floating point in IEEE_754 value 
 */
float IEEE_754::convertirDesde_754_32( uint32_t floatingToIntValue )
{
    UFloatingPointIEEE754 ieee754;    unsigned int mantissa = 0;
    unsigned int exponent = 0 ;
    unsigned int sign = 0;

    sign = NTH_BIT(floatingToIntValue, 31);
    for( int ix=0; ix<8; ix++)
        exponent = (exponent | (NTH_BIT(floatingToIntValue, (30 - ix)))) << 1;
    exponent = exponent >> 1;
    for( int ix=0; ix<23; ix++)
        mantissa = (mantissa | (NTH_BIT(floatingToIntValue, (22 - ix)))) << 1;
    mantissa = mantissa >> 1;

    ieee754.raw.sign = sign;
    ieee754.raw.exponent = exponent;
    ieee754.raw.mantissa = mantissa;
    return ieee754.f;
}
