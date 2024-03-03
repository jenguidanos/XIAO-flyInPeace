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
    if (CURVE_TYPE_SOUND_V1 == type)
        return new CCurveSoundV1();
    if (CURVE_TYPE_VISUALIZER_V1 == type)
        return new CCurveVisualizerV1();
    if (CURVE_TYPE_PARAMETRIC_V1 == type)
        return new CCurveParametricV1();
    return new CfipCurve();
}

//------------------------------------------------------------------------------

// -- END OF FILE --