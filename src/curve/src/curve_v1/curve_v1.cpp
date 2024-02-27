/**
 *  @brief Version 1 curve definition
 *  @author Cooked by Vicente A. (TT)
 */

//---[ Includes: ]--------------------------------------------------------------

#include "curve_v1.h"
#include <iomanip>

using namespace vaf::fip;

//------------------------------------------------------------------------------

err_code_t CCurveV1::setup()
{
    return ERR_CODE_NONE;
}

void CCurveV1::update(float value)
{
    computed_value_ = value;
}

float CCurveV1::get() const
{
    return computed_value_;
}

void CCurveV1::print(std::stringstream &ss) const
{
    ss << " Curve: " << std::setw(6) << std::fixed << std::setprecision(2) << get();
}

//------------------------------------------------------------------------------

// -- END OF FILE --