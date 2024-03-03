/**
 *  @brief Version 1 curve definition
 *  @author Cooked by Vicente A. (TT)
 */

//---[ Includes: ]--------------------------------------------------------------

#include "curve_v1.h"

using namespace vaf::fip;

//------------------------------------------------------------------------------

void CCurveParametricV1::update(float value)
{

    set_value_(value);
}

//------------------------------------------------------------------------------

void CCurveSoundV1::update(float value)
{
    set_value_(value);
}

//------------------------------------------------------------------------------

void CCurveVisualizerV1::update(float value)
{
    set_value_(value ? (1.0f - value) : value);
}

//------------------------------------------------------------------------------

// -- END OF FILE --