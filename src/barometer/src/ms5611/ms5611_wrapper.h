/**
 *  @brief MS5611 Atmospheric Pressure Sensor device declaration
 *  @author Cooked by vabarca (TT)
 */

#ifndef MS5611_WRAPPER_H
#define MS5611_WRAPPER_H

//---[ Includes: ]--------------------------------------------------------------

#include "MS5611.h"
#include <barometer/barometer.h>

//---[ Typedefs: ]--------------------------------------------------------------

namespace vaf::fip
{

class CBarometerMS5611 : public CfipBarometer
{
  private:
    MS5611 baro;

  public:
    CBarometerMS5611() = default;
    ~CBarometerMS5611() = default;

    err_code_t setup() override;
    void update() override;
    float get_pressure() const override;
    float get_temperature() const override;
    void print(std::stringstream &ss) const override;
};

} // namespace vaf::fip

//------------------------------------------------------------------------------

#endif /* MS5611_WRAPPER_H */
