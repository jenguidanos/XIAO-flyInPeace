/**
 *  @brief Variometer factory class definition
 *  @author Cooked by Vicente A. (TT)
 */

//---[ Includes: ]--------------------------------------------------------------

#include "../variometer.h"
#include "variometer/src/fip_v1/vario_v1.h"

using namespace vaf::fip;

//------------------------------------------------------------------------------

CfipVario *CFactoryVariometer::create(vario_type_t type, CfipBarometer &barometer)
{
    if (VARIO_TYPE_V1 == type)
        return new CVarioV1(barometer);
    return new CfipVario();
}

//------------------------------------------------------------------------------

// -- END OF FILE --
