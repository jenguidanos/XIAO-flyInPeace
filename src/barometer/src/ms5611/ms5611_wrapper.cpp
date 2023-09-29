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

#include <Wire.h>
#include "ms5611_wrapper.h"

//------------------------------------------------------------------------------

CMS5611::CMS5611() : baro{0x77}
{}

err_code_t CMS5611::setup()
{
    Wire.begin();
    baro.setOversampling(OSR_ULTRA_HIGH);
    baro.setCompensation(true);
    return baro.begin()? ERR_CODE_NONE : ERR_CODE_SETUP;
}

void CMS5611::update() 
{
    baro.read();
}

float CMS5611::get_pressure() const
{
    return baro.getPressure();
}

float CMS5611::get_temperature() const
{
    return baro.getTemperature();
}

//------------------------------------------------------------------------------

// -- END OF FILE --