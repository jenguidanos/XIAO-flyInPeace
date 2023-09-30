/** 
 *  @brief Atmospheric Pressure Sensor factory class definition
 *  @author Cooked by Vicente A. (TT)
 */

//---[ Includes: ]--------------------------------------------------------------

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "vario_v1.h"

//------------------------------------------------------------------------------

err_code_t CVario_v1::setup()
{
    return ERR_CODE_NONE;
}

void CVario_v1::update()
{
    _barometer.update();
}

//------------------------------------------------------------------------------

// -- END OF FILE --


