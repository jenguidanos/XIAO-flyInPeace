/**
 *  @brief Atmospheric Pressure Sensor factory class definition
 *  @author Cooked by Vicente A. (TT)
 */

//---[ Includes: ]--------------------------------------------------------------

#include "ms5611/ms5611_wrapper.h"
#include <barometer/barometer.h>

//------------------------------------------------------------------------------

CfipBarometer *CFactoryBarometer::create(baro_type_t type)
{
    if (BARO_TYPE_MS5611 == type)
        return new CBarometerMS5611();
    return new CfipBarometer();
}

//------------------------------------------------------------------------------

// -- END OF FILE --