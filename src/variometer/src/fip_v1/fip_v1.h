/**
 *  @brief MS5611 Atmospheric Pressure Sensor device
 *  @author Cooked by vabarca (TT)
 */

#ifndef FIP_V1_H
#define FIP_V1_H

//---[ Includes: ]--------------------------------------------------------------

#include <variometer/variometer.h>

//---[ Typedefs: ]--------------------------------------------------------------

class Cfip_v1 : public Cfip_vario
{
    private:
    Cfip_dev& _barometer;
    float _delta_h;
    float _delta_t;
    float _altitude;

    public:
        explicit Cfip_v1(Cfip_dev& barometer) : _barometer{barometer} {};
        ~Cfip_v1(){}
        err_code_t setup() override;
        void update() override;
        float get_pressure() const override {return _barometer.get_pressure();};
        float get_temperature() const override {return _barometer.get_temperature();};
        float get_altitude() const override {return _altitude;};
        float get_delta_h() const override {return _delta_h;};
        float get_delta_t() const override {return _delta_t;};

};

//------------------------------------------------------------------------------

#endif /* FIP_V1_H */
