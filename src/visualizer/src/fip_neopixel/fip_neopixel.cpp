/**
 *  @brief Neopixel visualizer definition
 *  @author Cooked by Vicente A. (TT)
 */

//---[ Includes: ]--------------------------------------------------------------

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "fip_neopixel.h"
#include <iomanip>


using namespace vaf::fip;

//------------------------------------------------------------------------------

CfipNeopixel::CfipNeopixel(uint8_t pin, uint8_t num_of_pixels)
    : strip_(num_of_pixels, pin, NEO_GRB + NEO_KHZ800)
{
}

err_code_t CfipNeopixel::setup()
{
    strip_.begin();
    strip_.fill(0, 0, strip_.numPixels());
    return ERR_CODE_NONE;
}

void CfipNeopixel::update(float value)
{
    hue_ = palette(value);

    uint32_t color = hue_ ? strip_.gamma32(strip_.ColorHSV(hue_, 255, 255)) : 0;

    strip_.fill(color, 0, strip_.numPixels());
    strip_.show();
}

uint16_t CfipNeopixel::palette(float value)
{
    static const float max_value = {1.0f};
    static const float min_value = {0.0f};

    if (value < min_value)
        return 0;

    if (value > max_value)
        value = max_value;

    return (uint16_t)(value * 65536.0f / max_value);
}

void CfipNeopixel::print(std::stringstream &ss) const
{
    ss << " hue: " << std::setw(5) << std::fixed << std::setprecision(1) << hue_;
}

//------------------------------------------------------------------------------

// -- END OF FILE --