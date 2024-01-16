/**
 *  @brief AD9833 sound handler definition
 *  @author Cooked by Vicente A. (TT)
 */

//---[ Includes: ]--------------------------------------------------------------

#include "ad9833.h"
#include <SPI.h>

//------------------------------------------------------------------------------

const uint8_t AD9833::_pin_data = 10;    ///< SPI Data pin number
const uint8_t AD9833::_pin_clk = 8;      ///< SPI Clock pin number
const uint8_t AD9833::_pin_fsync = 5;    ///< SPI Load pin number (FSYNC in AD9833 usage)
const uint8_t AD9833::_pin_shutdown = 3; ///< SPI Load pin number (FSYNC in AD9833 usage)

err_code_t AD9833::setup()
{
    ad.begin();
    ad.setMode(MD_AD9833::MODE_SINE);
    pinMode(AD9833::_pin_shutdown, OUTPUT);
    powerdown();
    return ERR_CODE_NONE;
}

void AD9833::set_vario(float vario)
{
    abs(vario) < 0.5f ? powerdown() : powerup();

    ad.setFrequency(MD_AD9833::CHAN_0, 200);
}

void AD9833::powerdown(void)
{
    digitalWrite(AD9833::_pin_shutdown, LOW);
}

void AD9833::powerup(void)
{
    digitalWrite(AD9833::_pin_shutdown, HIGH);
}

//------------------------------------------------------------------------------

// -- END OF FILE --
