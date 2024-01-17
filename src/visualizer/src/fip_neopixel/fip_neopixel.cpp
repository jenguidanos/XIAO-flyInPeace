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

CfipNeopixel::CfipNeopixel(uint8_t pin, uint8_t num_of_pixels) : strip(num_of_pixels, pin, NEO_GRB + NEO_KHZ800)
{
}

err_code_t CfipNeopixel::setup()
{
    strip.begin();
    strip.setBrightness(50);
    strip.clear(); 
    return ERR_CODE_NONE;
}

void CfipNeopixel::update()
{
    strip.show();
}

void CfipNeopixel::set_vario(float vario)
{
    //for (uint16_t i=0; i < strip.numPixels(); i++) {
        //strip.setPixelColor(1, strip.Color(127, 127, 127));    //turn every third pixel on
    //}
    for(uint16_t j=0; j<256; j++) 
    {
        for(uint16_t i=0; i<strip.numPixels(); i++) 
        {
        strip.setPixelColor(i, wheel((i+j) & 255));
        }
    }
    update();
    delay(50);
}

uint32_t CfipNeopixel::wheel(byte wheelPos) {
  wheelPos = 255 - wheelPos;
  if(wheelPos < 85) {
    return strip.Color(255 - wheelPos * 3, 0, wheelPos * 3);
  }
  if(wheelPos < 170) {
    wheelPos -= 85;
    return strip.Color(0, wheelPos * 3, 255 - wheelPos * 3);
  }
  wheelPos -= 170;
  return strip.Color(wheelPos * 3, 255 - wheelPos * 3, 0);
}

//------------------------------------------------------------------------------

// -- END OF FILE --

