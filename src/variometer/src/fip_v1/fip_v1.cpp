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

#include "fip_v1.h"

//------------------------------------------------------------------------------

Cfip_v1::Cfip_v1()
{

}

err_code_t Cfip_v1::setup()
{
    return ERR_CODE_NONE;
}

//------------------------------------------------------------------------------

// -- END OF FILE --


