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
    const float termA = 1.0f / 5.257f;

    _barometer.update();
    _pressure = _barometer.get_pressure();
    _temperature = _barometer.get_temperature();
    _altitude = (((pow((_sea_level_pressure / _pressure), termA) - 1.0f) * (_temperature + 273.15f)) / 0.0065f);
}

void CVario_v1::set_altitude(float altitude)
{

}

//------------------------------------------------------------------------------