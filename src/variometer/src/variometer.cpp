/** 
 *  @brief Variometer factory class definition
 *  @author Cooked by Vicente A. (TT)
 */

//---[ Includes: ]--------------------------------------------------------------

#include "../variometer.h"
#include "variometer/src/fip_v1/vario_v1.h"

//------------------------------------------------------------------------------

Cfip_vario* CFactoryVariometer::create(vario_type_t type, Cfip_dev& barometer)
{
    if(VARIO_TYPE_V1 == type) return new CVario_v1(barometer);
    return new Cfip_vario();
}

//------------------------------------------------------------------------------

// -- END OF FILE --

