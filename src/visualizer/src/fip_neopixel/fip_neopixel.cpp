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
#include <utils/utils.h>

using namespace vaf::fip;

//------------------------------------------------------------------------------

CfipNeopixel::CfipNeopixel(uint8_t pin, uint8_t num_of_pixels) : strip_(num_of_pixels, pin, NEO_GRB + NEO_KHZ800)
{
}

err_code_t CfipNeopixel::setup()
{
    strip_.begin();
    strip_.clear();
    strip_.show();
    return ERR_CODE_NONE;
}

void CfipNeopixel::update(float value)
{
    static const uint8_t MAX_BRIGHTNESS{255};
    update_(value, 0, get_strip_()->numPixels(), MAX_BRIGHTNESS);
}

void CfipNeopixel::update_(float value, uint16_t first, uint16_t cnt, uint8_t brightness)
{
    set_hue_(palette_(value));

    Adafruit_NeoPixel *strip = get_strip_();

    static const uint8_t MAX_SATURATION{255};

    uint32_t color = get_hue_() ? strip->gamma32(strip->ColorHSV(get_hue_(), MAX_SATURATION, brightness)) : 0;

    strip->fill(color, first, cnt);
    strip->show();
}

uint16_t CfipNeopixel::palette_(float value)
{
    return (uint16_t)(trim_value(value) * (float)UINT16_MAX);
}

void CfipNeopixel::print(std::stringstream &ss) const
{
    ss << " hue: " << std::setw(5) << std::fixed << std::setprecision(1) << hue_;
}

void CfipNeopixelV1::update(float value)
{
    static const uint8_t MAX_BRIGHTNESS{100};
    static const uint8_t MIN_BRIGHTNESS{30};
    static const uint8_t WHEEL_SIZE{8};
    static const uint16_t FIRST{1};

    get_strip_()->clear();
    uint8_t num_of_pixels = (uint8_t)(ceil((float)WHEEL_SIZE * (1.0f - value)));
    num_of_pixels = num_of_pixels ? num_of_pixels : FIRST;

    update_(value, FIRST, num_of_pixels, map(num_of_pixels, 1, WHEEL_SIZE, MIN_BRIGHTNESS, MAX_BRIGHTNESS));
}

//------------------------------------------------------------------------------

// -- END OF FILE --