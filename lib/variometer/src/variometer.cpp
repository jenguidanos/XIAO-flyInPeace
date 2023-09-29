/** 
 *  @brief Variometer factory class definition
 *  @author Cooked by Vicente A. (TT)
 */

//---[ Includes: ]--------------------------------------------------------------

#include "fip_v1/fip_v1.h"
#include <variometer.h>

//------------------------------------------------------------------------------

CVariometer* CFactoryVariometer::create(variometer_type_t type, CBarometer& const baro)
{
    if(VARIO_TYPE_FIP_V1 == type) return new Cfip_v1(baro);
    return new CVariometer();
}


//------------------------------------------------------------------------------

// -- END OF FILE --