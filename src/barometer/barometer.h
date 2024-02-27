/**
 *  @brief Generic Atmospheric Pressure Sensor API and factory class declarations
 *  @author Cooked by vabarca (TT)
 */

#ifndef BAROMETER_H
#define BAROMETER_H

//---[ Includes: ]--------------------------------------------------------------

#include "commons.h"
#include <cstdint>
#include <string>

//---[ Typedefs: ]--------------------------------------------------------------

namespace vaf::fip
{

typedef enum baro_type_e
{
    BARO_TYPE_UNKNOWN,
    BARO_TYPE_MS5611,

    BARO_TYPE_MAX_NUM
} baro_type_t;

class CFactoryBarometer
{
  public:
    virtual ~CFactoryBarometer() = default;
    static CfipBarometer *create(baro_type_t type);
};

} // namespace vaf::fip

//------------------------------------------------------------------------------

#endif /* BAROMETER_H */
