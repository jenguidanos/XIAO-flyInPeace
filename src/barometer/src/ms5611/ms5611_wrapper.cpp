/**
 *  @brief Atmospheric Pressure Sensor definition
 *  @author Cooked by Vicente A. (TT)
 */

//---[ Includes: ]--------------------------------------------------------------

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "ms5611_wrapper.h"
#include <iomanip>

//------------------------------------------------------------------------------

err_code_t CBarometerMS5611::setup()
{
    baro.setOversampling(OSR_ULTRA_HIGH);
    baro.setCompensation(true);
    return baro.begin() ? ERR_CODE_NONE : ERR_CODE_SETUP;
}

void CBarometerMS5611::update()
{
    baro.read();
}

float CBarometerMS5611::get_pressure() const
{
    return baro.getPressure();
}

float CBarometerMS5611::get_temperature() const
{
    return baro.getTemperature();
}

void CBarometerMS5611::print(std::stringstream &ss) const
{
    ss << " Temperature: " << std::setw(6) << std::fixed << std::setprecision(2) << get_temperature();
    ss << " Pressure: " << std::setw(8) << std::fixed << std::setprecision(2) << get_pressure();
}

//------------------------------------------------------------------------------

// -- END OF FILE --