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
    update_(value, 0, get_strip_()->numPixels());
}

void CfipNeopixel::update_(float value, uint16_t first, uint16_t cnt)
{
    set_hue_(palette_(value));

    Adafruit_NeoPixel* strip = get_strip_();

    uint32_t color = get_hue_() ? strip->gamma32(strip->ColorHSV(get_hue_(), 255, 255)) : 0;

    strip->fill(color, 0, strip->numPixels());
    strip->show();
}

uint16_t CfipNeopixel::palette_(float value)
{
    static const float max_value = {1.0f};
    static const float min_value = {0.0f};

    if (value < min_value)
        return 0;

    if (value > max_value)
        value = max_value;

    return (uint16_t)(value * (float)UINT16_MAX / max_value);
}

void CfipNeopixel::print(std::stringstream &ss) const
{
    ss << " hue: " << std::setw(5) << std::fixed << std::setprecision(1) << hue_;
}

void CfipNeopixelV1::update(float value)
{
    update_(value, 1, CfipNeopixelV1::NUM_OF_PIXELS-1);
}

//------------------------------------------------------------------------------

// -- END OF FILE --