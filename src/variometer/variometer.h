/**
 *  @brief Variometer API and factory class declarations
 *   Variometers measure the rate of change of altitude by detecting the change
 *   in air pressure (static pressure) as altitude changes.
 *  @author Cooked by vabarca (TT)
 */

#ifndef VARIOMETER_H
#define VARIOMETER_H

//---[ Includes: ]--------------------------------------------------------------

#include <barometer/barometer.h>
#include <commons.h>
#include <cstdint>
#include <string>

//---[ Typedefs: ]--------------------------------------------------------------

typedef enum vario_type_e
{
    VARIO_TYPE_UNKNOWN,
    VARIO_TYPE_V1,

    VARIO_TYPE_MAX_NUM
} vario_type_t;

class CFactoryVariometer
{
  public:
    virtual ~CFactoryVariometer() = default;
    static CfipVario *create(vario_type_t type, CfipBarometer &barometer);
};

//------------------------------------------------------------------------------

#endif /* VARIOMETER_H */
