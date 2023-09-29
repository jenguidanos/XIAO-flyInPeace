/**
 *  @brief MS5611 Atmospheric Pressure Sensor device
 *  @author Cooked by vabarca (TT)
 */

#ifndef FIP_V1_H
#define FIP_V1_H

//---[ Includes: ]--------------------------------------------------------------

#include <variometer/variometer.h>

//---[ Typedefs: ]--------------------------------------------------------------

class Cfip_v1 : public CVariometer
{
    private:

    public:
        Cfip_v1();
        ~Cfip_v1(){}
        err_code_t setup() override;
};

//------------------------------------------------------------------------------

#endif /* FIP_V1_H */
