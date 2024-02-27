/**
 *  @brief Curve handler factory class definition
 *  @author Cooked by Vicente A. (TT)
 */

//---[ Includes: ]--------------------------------------------------------------

#include "curve_v1/curve_v1.h"
#include <curve/curve.h>

using namespace vaf::fip;

//------------------------------------------------------------------------------

CfipCurve *CFactoryCurve::create(curve_type_t type)
{
    if (CURVE_TYPE_V1 == type)
        return new CCurveV1();
    return new CfipCurve();
}

//------------------------------------------------------------------------------

// -- END OF FILE --