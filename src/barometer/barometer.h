/** 
 *  @brief Generic Atmospheric Pressure Sensor API and factory class declarations
 *  @author Cooked by vabarca (TT)
 */

#ifndef BAROMETER_H
#define BAROMETER_H

//---[ Includes: ]--------------------------------------------------------------

#include <cstdint>
#include <string>
#include "commons.h"

//---[ Typedefs: ]--------------------------------------------------------------

typedef enum barometer_type_e
{   
    BARO_TYPE_UNKNOWN,
    BARO_TYPE_MS5611,

    BARO_TYPE_MAX_NUM
}barometer_type_t;


class CFactoryBarometer
{
    public:
        virtual ~CFactoryBarometer(){};
        static Cfip_dev* create(barometer_type_t type);
};


//------------------------------------------------------------------------------

#endif /* BAROMETER_H */
