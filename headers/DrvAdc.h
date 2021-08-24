#ifndef DRVADC_H
#define DRVADC_H

#include "DrvI2C.h"


#include <QtCore>

class ADS1115 : public DrvI2C {

public:
    ADS1115();
    virtual ~ADS1115();

    virtual bool Initialize();

    bool readData(std::uint16_t &data);

    bool startSingleConversion();

    bool resetDevice();

    std::float_t ToEngValue(std::uint16_t adcRegValue);
private:

    enum RegisterAddress{
         DEVICE_ID          = 0x48,
         CONVERSION_REG     = 0x00,
         CONFIGURE_REG      = 0x01,
         LOW_THRESHOLD_REG  = 0x02,
         HIGH_THRESHOLD_REG = 0x03,
         DEVIDE_RESET_CMD   = 0x06,
         GENERAL_CALL_ADD   = 0x00,
        ///Deprecated
         OS_START_SINGLE_CONVERSION = 0x8000,
         MUX_CH0_SINGLE_ENDED       = 0x0400,
         MUX_CH1_SINGLE_ENDED       = 0x0500,
         MUX_CH2_SINGLE_ENDED       = 0x0600,
         MUX_CH3_SINGLE_ENDED       = 0x0700,
         GAIN_2_3                   = 0x0000,
         GAIN_1                     = 0x0200,
         GAIN_2                     = 0x0400,
         GAIN_4                     = 0x0600,
         GAIN_8                     = 0x0800,
         GAIN_16                    = 0x0A00,
         MODE_SINGLE_SHOT_POWER_DWN = 0x0100,
         DATA_RATE_8                = 0x0000,
         DATA_RATE_16               = 0x0020,
         DATA_RATE_32               = 0x0040,
         DATA_RATE_64               = 0x0060,
         DATA_RATE_128              = 0x0080,
         DATA_RATE_250              = 0x00A0,
         DATA_RATE_475              = 0x00C0,
         DATA_RATE_860              = 0x00E0,
         WINDOWS_COMPARATOR         = 0x0010,
         COMPARATOR_ALERT_HIGH      = 0x0008,
         DISABLE_COMPARATOR         = 0x0003
    };

    enum MultiplexerInput{
         DIFERENTIAL_CH0_CH1    = 0,
         DIFERENTIAL_CH0_CH3    = 1,
         DIFERENTIAL_CH1_CH3    = 2,
         DIFERENTIAL_CH2_CH3    = 3,
         SINGLE_ENDED_CH0       = 4,
         SINGLE_ENDED_CH1       = 5,
         SINGLE_ENDED_CH2       = 6,
         SINGLE_ENDED_CH3       = 7,
         MULTIPLEXER_BITS_SHIFF = 12,
         MULTIPLEXER_ALL_MASK   = 0x7000
    };

    enum ProgramableGainConfigure{
         FULL_SCALE_6V      = 0,
         FULL_SCALE_4V      = 1,
         FULL_SCALE_2V      = 2,
         FULL_SCALE_1V      = 3,
         FULL_SCALE_0V5     = 4,
         FULL_SCALE_0V2     = 5,
         FULL_SCALE_0V22    = 6,
         FULL_SCALE_0V222   = 7,
         GAINS_BITS_SHIFF   = 9,
         GAINS_ALL_MASK     = 0x0E00
    };

    enum DeviceOpMode{
         CONTINUOS_CONVERSION           = 0,
         SINGLE_CONVERSION_POWER_DOWN   = 1
    };

    enum ConversionDataRate{
         SPS_8      = 0,
         SPS_16     = 1,
         SPS_32     = 2,
         SPS_64     = 3,
         SPS_128    = 4,
         SPS_250    = 5,
         SPS_475    = 6,
         SPS_860    = 7
    };

    enum ComparatorQueueAndDisabled{
         ASSERT_ON_CONV_1       = 0,
         ASSERT_ON_CONV_2       = 1,
         ASSERT_ON_CONV_4       = 2,
         DISABLED               = 3
    };

    enum OperationalStatus{
         START_SINGLE_CONVERSION = 1
    };

    struct ConfigureReg{
        const std::uint16_t ComparatorQueue       : 2;
        const std::uint16_t LatchingComparator    : 1;
        const std::uint16_t ComparatorPolarity    : 1;
        const std::uint16_t ComparatorMode        : 1;
              std::uint16_t DataRate              : 3;
              std::uint16_t OpMode                : 1;
              std::uint16_t Gain                  : 3;
              std::uint16_t Multiplexer           : 3;
              std::uint16_t OpStatusSingleStart   : 1;

        ConfigureReg () : ComparatorQueue(DISABLED),
                          LatchingComparator(0),
                          ComparatorPolarity(0),
                          ComparatorMode(0),
                          DataRate(SPS_128),
                          OpMode(SINGLE_CONVERSION_POWER_DOWN),
                          Gain(FULL_SCALE_2V),
                          Multiplexer(SINGLE_ENDED_CH0),
                          OpStatusSingleStart(START_SINGLE_CONVERSION)
        {}
    };

    bool state_;
    int identifier_;    
    ConfigureReg regValue_;
    std::float_t gain;

    static const std::uint32_t ADC_RESOLUTION = 65536;
    static const std::float_t HARDWARE_GAIN;

    virtual bool readDevice(int regAdd, int &data);

    virtual bool writeDevice(int regAdd, int data);

    void setGain(ProgramableGainConfigure regGain);
};

#endif // DRVADC_H
