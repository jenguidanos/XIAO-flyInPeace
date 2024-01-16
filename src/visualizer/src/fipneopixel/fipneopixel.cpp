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

#include "fipneopixel.h"

//------------------------------------------------------------------------------

CfipNeopixel::CfipNeopixel(uint8_t num_of_pixels) :
    num_of_pixels(num_of_pixels)
{

}

void CfipNeopixel::set_vario(float vario)
{

}

//------------------------------------------------------------------------------

// -- END OF FILE --