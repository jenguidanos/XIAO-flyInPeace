/**
 *  @brief MS5611 Atmospheric Pressure Sensor device
 *  @author Cooked by vabarca (TT)
 */

#ifndef MS5611_WRAPPER_H
#define MS5611_WRAPPER_H

//---[ Includes: ]--------------------------------------------------------------

#include "MS5611.h"
#include "../../barometer.h"

//---[ Typedefs: ]--------------------------------------------------------------

class CMS5611 : public Cfip_barometer
{
    private:
        MS5611 baro;

    public:

        CMS5611();
        ~CMS5611()= default;

        err_code_t setup() override;
        void update() override;
        float get_pressure() const override;
        float get_temperature() const override;
};

//------------------------------------------------------------------------------

#endif /* MS5611_WRAPPER_H */
