/**
 *  @brief Version 1 curve definition
 *  @author Cooked by Vicente A. (TT)
 */

//---[ Includes: ]--------------------------------------------------------------

#include "curve_v1.h"
#include "utils.h"

using namespace vaf::fip;

//------------------------------------------------------------------------------

void CCurveParametricV1::update(float value)
{
    for (unsigned int i = 0; i < points_.size(); i++)
    {
        if (points_[i].first < value)
            continue;

        if (points_[i].first == value)
        {
            set_value_(points_[i].second);
        }
        else
        {
            set_value_(fmapExt(value, points_[i], points_[i - 1]));
        }

        break;
    }
}

//------------------------------------------------------------------------------

// -- END OF FILE --