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

//------------------------------------------------------------------------------

CfipNeopixel::CfipNeopixel(uint8_t pin, uint8_t num_of_pixels)
    : strip(num_of_pixels, pin, NEO_GRB + NEO_KHZ800), max_vario{10.0f}, min_vario{0.5f}
{
}

err_code_t CfipNeopixel::setup()
{
    strip.begin();
    strip.clear();
    return ERR_CODE_NONE;
}

void CfipNeopixel::update()
{
    strip.show();
}

void CfipNeopixel::set_vario(float vario)
{
    if (vario < min_vario)
    {
        hue = 0;
        strip.fill(0, 0, strip.numPixels());
        return;
    }

    if (vario > max_vario)
        vario = max_vario;
    hue = (uint16_t)(vario * 65536.0f / max_vario);

    uint32_t color = 0;

    if (hue)
    {
        color = strip.ColorHSV(hue, 255, 255);
        color = strip.gamma32(color);
    }

    strip.fill(color, 0, strip.numPixels());

    update();
}

void CfipNeopixel::print(std::stringstream &ss) const
{
    ss << " hue: " << std::setw(5) << std::fixed << std::setprecision(1) << hue;
}

//------------------------------------------------------------------------------

// -- END OF FILE --
