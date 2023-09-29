/**
 *  @brief MS5611 Atmospheric Pressure Sensor device
 *  @author Cooked by vabarca (TT)
 */

#ifndef FIP_V1_H
#define FIP_V1_H

//---[ Includes: ]--------------------------------------------------------------

#include <variometer.h>

//---[ Typedefs: ]--------------------------------------------------------------

class Cfip_v1 : public CVariometer
{
    private:
        CBarometer& const _baro;

    public:

        explicit Cfip_v1(CBarometer& const baro) : _baro{baro} {}
        virtual ~Cfip_v1(){}
};

//------------------------------------------------------------------------------

#endif /* FIP_V1_H */
