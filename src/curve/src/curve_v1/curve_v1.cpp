/**
 *  @brief Version 1 curve definition
 *  @author Cooked by Vicente A. (TT)
 */

//---[ Includes: ]--------------------------------------------------------------

#include "curve_v1.h"
#include <iomanip>

using namespace vaf::fip;

//------------------------------------------------------------------------------

void CCurveSoundV1::update(float value)
{
    set_value_(value);
}

void CCurveSoundV1::print(std::stringstream &ss) const
{
    ss << " Curve: " << std::setw(6) << std::fixed << std::setprecision(2) << get();
}

//------------------------------------------------------------------------------

void CCurveVisualizerV1::update(float value)
{
    set_value_(value ? (1.0f - value) : value);
}

//------------------------------------------------------------------------------

// -- END OF FILE --