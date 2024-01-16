/**
 *  @brief Atmospheric Pressure Sensor factory class definition
 *  @author Cooked by Vicente A. (TT)
 */

//---[ Includes: ]--------------------------------------------------------------

#include "ms5611/ms5611_wrapper.h"
#include <barometer/barometer.h>

//------------------------------------------------------------------------------

Cfip_barometer *CFactoryBarometer::create(baro_type_t type)
{
    if (BARO_TYPE_MS5611 == type)
        return new CMS5611();
    return new Cfip_barometer();
}

//------------------------------------------------------------------------------

// -- END OF FILE --