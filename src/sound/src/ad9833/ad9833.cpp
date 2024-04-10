/**
 *  @brief AD9833 sound handler definition
 *  @author Cooked by Vicente A. (TT)
 */

//---[ Includes: ]--------------------------------------------------------------

#include "ad9833.h"

#include <SPI.h>
#include "utils.h"

using namespace vaf::fip;

//------------------------------------------------------------------------------

const uint8_t CSoundAD9833::pin_data_ = D10;    ///< SPI Data pin number
const uint8_t CSoundAD9833::pin_clk_ = D8;      ///< SPI Clock pin number
const uint8_t CSoundAD9833::pin_cs_ = A0;       ///< SPI Load pin number (FSYNC in AD9833 usage)
const uint8_t CSoundAD9833::pin_shutdown_ = A1; ///< SPI Load pin number (FSYNC in AD9833 usage)

err_code_t CSoundAD9833::setup()
{
    ad_.begin();
    ad_.setMode(MD_AD9833::MODE_SINE);
    ad_.setFrequency(MD_AD9833::CHAN_0, 0);
    pinMode(CSoundAD9833::pin_shutdown_, OUTPUT);
    powerdown();
    return ERR_CODE_NONE;
}

void CSoundAD9833::update(float value)
{
    tone_ = value;
    tone_ ? powerup() : powerdown();
    ad_.setFrequency(MD_AD9833::CHAN_0, (uint32_t)tone_);
}

void CSoundAD9833::powerdown(void)
{
    digitalWrite(CSoundAD9833::pin_shutdown_, LOW);
}

void CSoundAD9833::powerup(void)
{
    digitalWrite(CSoundAD9833::pin_shutdown_, HIGH);
}

//------------------------------------------------------------------------------

// -- END OF FILE --
