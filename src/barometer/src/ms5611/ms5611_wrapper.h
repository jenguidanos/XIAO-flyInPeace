/**
 *  @brief MS5611 Atmospheric Pressure Sensor device
 *  @author Cooked by vabarca (TT)
 */

#ifndef MS5611_WRAPPER_H
#define MS5611_WRAPPER_H

//---[ Includes: ]--------------------------------------------------------------

#include <barometer/barometer.h>
#include "MS5611.h"

//---[ Typedefs: ]--------------------------------------------------------------

class CMS5611 : public CBarometer
{
    private:
        MS5611 baro;

    public:

        CMS5611();
        virtual ~CMS5611(){}

        virtual err_code_t setup() override;
        virtual void update() override;
        float get_pressure() const override;
        float get_temperature() const override;
};

//------------------------------------------------------------------------------

#endif /* MS5611_WRAPPER_H */
