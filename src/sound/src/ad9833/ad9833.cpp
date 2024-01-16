/**
 *  @brief AD9833 sound handler definition
 *  @author Cooked by Vicente A. (TT)
 */

//---[ Includes: ]--------------------------------------------------------------

#include "ad9833.h"
#include <SPI.h>

//------------------------------------------------------------------------------

const uint8_t CSoundAD9833::_pin_data = 10;    ///< SPI Data pin number
const uint8_t CSoundAD9833::_pin_clk = 8;      ///< SPI Clock pin number
const uint8_t CSoundAD9833::_pin_fsync = 5;    ///< SPI Load pin number (FSYNC in AD9833 usage)
const uint8_t CSoundAD9833::_pin_shutdown = 3; ///< SPI Load pin number (FSYNC in AD9833 usage)

err_code_t CSoundAD9833::setup()
{
    ad.begin();
    ad.setMode(MD_AD9833::MODE_SINE);
    pinMode(CSoundAD9833::_pin_shutdown, OUTPUT);
    powerdown();
    return ERR_CODE_NONE;
}

void CSoundAD9833::set_vario(float vario)
{
    abs(vario) < 0.5f ? powerdown() : powerup();

    ad.setFrequency(MD_AD9833::CHAN_0, 200);
}

void CSoundAD9833::powerdown(void)
{
    digitalWrite(CSoundAD9833::_pin_shutdown, LOW);
}

void CSoundAD9833::powerup(void)
{
    digitalWrite(CSoundAD9833::_pin_shutdown, HIGH);
}

//------------------------------------------------------------------------------

// -- END OF FILE --
