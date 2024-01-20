/**
 *  @brief AD9833 sound handler definition
 *  @author Cooked by Vicente A. (TT)
 */

//---[ Includes: ]--------------------------------------------------------------

#include "ad9833.h"
#include <SPI.h>

//------------------------------------------------------------------------------

const uint8_t CSoundAD9833::_pin_data = D10;    ///< SPI Data pin number
const uint8_t CSoundAD9833::_pin_clk = D8;      ///< SPI Clock pin number
const uint8_t CSoundAD9833::_pin_cs = A0;       ///< SPI Load pin number (FSYNC in AD9833 usage)
const uint8_t CSoundAD9833::_pin_shutdown = A1; ///< SPI Load pin number (FSYNC in AD9833 usage)

err_code_t CSoundAD9833::setup()
{
    ad.begin();
    ad.setMode(MD_AD9833::MODE_SINE);
    ad.setFrequency(MD_AD9833::CHAN_0, 0);
    pinMode(CSoundAD9833::_pin_shutdown, OUTPUT);
    powerdown();
    return ERR_CODE_NONE;
}

void CSoundAD9833::set_vario(float vario)
{
    float tone = vario > 0.5f ? ((vario * 600.0f) / 5.0f) + 200.0f : 0.0f;
    ad.setFrequency(MD_AD9833::CHAN_0, tone);
}

void CSoundAD9833::powerdown(void)
{
    digitalWrite(CSoundAD9833::_pin_shutdown, HIGH); //Should be low to powerdown
}

void CSoundAD9833::powerup(void)
{
    digitalWrite(CSoundAD9833::_pin_shutdown, HIGH);
}

//------------------------------------------------------------------------------

// -- END OF FILE --
