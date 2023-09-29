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

class CBarometer
{
  public:

    CBarometer(){};
    virtual ~CBarometer(){}

    virtual err_code_t setup() {return ERR_CODE_SETUP;}
    virtual void update() {};

    // Handler, to be called in the loop()
    virtual float get_pressure() const {return 0.0f;}
    virtual float get_temperature() const {return 0.0f;}
};


class CFactoryBarometer
{
  public:
    virtual ~CFactoryBarometer(){};
    static CBarometer* create(barometer_type_t type);
};


//------------------------------------------------------------------------------

#endif /* BAROMETER_H */
