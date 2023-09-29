/** 
 *  @brief Variometer API and factory class declarations
 *   Variometers measure the rate of change of altitude by detecting the change 
 *   in air pressure (static pressure) as altitude changes.
 *  @author Cooked by vabarca (TT)
 */

#ifndef VARIOMETER_H
#define VARIOMETER_H

//---[ Includes: ]--------------------------------------------------------------

#include <cstdint>
#include <string>
#include <barometer/barometer.h>
#include <commons/commons.h>

//---[ Typedefs: ]--------------------------------------------------------------

typedef enum variometer_type_e
{   
    VARIO_TYPE_UNKNOWN,
    VARIO_TYPE_FIP_V1,

    VARIO_TYPE_MAX_NUM
}variometer_type_t;

class CVariometer
{
  public:
    CVariometer(){}
    virtual ~CVariometer(){}
};

class CFactoryVariometer
{
  public:
    virtual ~CFactoryVariometer(){};
    static CVariometer* create(variometer_type_t type, CBarometer& const baro);
};


//------------------------------------------------------------------------------

#endif /* VARIOMETER_H */
