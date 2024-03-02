/**
 *  @brief Version 1 curve definition
 *  @author Cooked by Vicente A. (TT)
 */

//---[ Includes: ]--------------------------------------------------------------

#include "curve_v1.h"
#include <iomanip>

using namespace vaf::fip;

//------------------------------------------------------------------------------

err_code_t CCurveSoundV1::setup()
{
    return ERR_CODE_NONE;
}

void CCurveSoundV1::update(float value)
{
    computed_value_ = value;
}

float CCurveSoundV1::get() const
{
    return computed_value_;
}

void CCurveSoundV1::print(std::stringstream &ss) const
{
    ss << " Curve: " << std::setw(6) << std::fixed << std::setprecision(2) << get();
}

//------------------------------------------------------------------------------

err_code_t CCurveVisualizerV1::setup()
{
    return ERR_CODE_NONE;
}

void CCurveVisualizerV1::update(float value)
{
    computed_value_ = value;
}

float CCurveVisualizerV1::get() const
{
    return computed_value_;
}

void CCurveVisualizerV1::print(std::stringstream &ss) const
{
    ss << " Curve: " << std::setw(6) << std::fixed << std::setprecision(2) << get();
}

//------------------------------------------------------------------------------

// -- END OF FILE --