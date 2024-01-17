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

//------------------------------------------------------------------------------

CfipNeopixel::CfipNeopixel(uint8_t pin) : CfipNeopixel(1, pin)
{
}

CfipNeopixel::CfipNeopixel(uint8_t pin, uint8_t num_of_pixels) : strip(num_of_pixels, pin, NEO_GRB + NEO_KHZ800)
{
}

err_code_t CfipNeopixel::setup()
{
    strip.begin();
    return ERR_CODE_NONE;
}

void CfipNeopixel::update()
{
    strip.show();
}

void CfipNeopixel::set_vario(float vario)
{
    for (uint16_t i=0; i < strip.numPixels(); i++) {
        strip.setBrightness(50);
        strip.setPixelColor(i, strip.Color(255, 0, 0));    //turn every third pixel on
    }
    update();
}

//------------------------------------------------------------------------------

// -- END OF FILE --