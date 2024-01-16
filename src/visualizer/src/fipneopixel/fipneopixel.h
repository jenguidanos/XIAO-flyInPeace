/**
 *  @brief MS5611 Atmospheric Pressure Sensor device declaration
 *  @author Cooked by vabarca (TT)
 */

#ifndef MS5611_WRAPPER_H
#define MS5611_WRAPPER_H

//---[ Includes: ]--------------------------------------------------------------

#include <visualizer/barometer.h>

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
        void print(std::stringstream& ss) const override;
};

//------------------------------------------------------------------------------

#endif /* MS5611_WRAPPER_H */
