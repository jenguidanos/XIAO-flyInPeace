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
#include <commons.h>

//---[ Typedefs: ]--------------------------------------------------------------

typedef enum vario_type_e
{   
    VARIO_TYPE_UNKNOWN,
    VARIO_TYPE_V1,

    VARIO_TYPE_MAX_NUM
}vario_type_t;

class CFactoryVariometer
{
public:
    virtual ~CFactoryVariometer(){};
    static Cfip_vario* create(vario_type_t type, Cfip_dev& barometer);
};


//------------------------------------------------------------------------------

#endif /* VARIOMETER_H */
