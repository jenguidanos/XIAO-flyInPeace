/**
 *  @brief Generic curve API and factory class declarations
 *  @author Cooked by vabarca (TT)
 */

#ifndef CURVE_H
#define CURVE_H

//---[ Includes: ]--------------------------------------------------------------

#include <commons.h>

//---[ Typedefs: ]--------------------------------------------------------------

namespace vaf::fip
{

typedef enum curve_type_e
{
    CURVE_TYPE_UNKNOWN,
    CURVE_TYPE_SOUND_V1,
    CURVE_TYPE_VISUALIZER_V1,
    CURVE_TYPE_PARAMETRIC_V1,

    CURVE_TYPE_MAX_NUM
} curve_type_t;

class CFactoryCurve
{
  public:
    virtual ~CFactoryCurve() = default;
    static CfipCurve *create(curve_type_t type);
};

} // namespace vaf::fip

//------------------------------------------------------------------------------

#endif /* CURVE_H */