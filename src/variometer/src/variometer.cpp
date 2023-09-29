/** 
 *  @brief Variometer factory class definition
 *  @author Cooked by Vicente A. (TT)
 */

//---[ Includes: ]--------------------------------------------------------------

#include "../variometer.h"
#include "fip_v1/fip_v1.h"

//------------------------------------------------------------------------------

CVariometer* CFactoryVariometer::create(variometer_type_t type)
{
    if(VARIO_TYPE_FIP_V1 == type) return new Cfip_v1();
    return new CVariometer();
}

//------------------------------------------------------------------------------

// -- END OF FILE --