/**
 *  @brief MS5611 Atmospheric Pressure Sensor device
 *  @author Cooked by vabarca (TT)
 */

#ifndef FIP_V1_H
#define FIP_V1_H

//---[ Includes: ]--------------------------------------------------------------

#include <variometer/variometer.h>

//---[ Typedefs: ]--------------------------------------------------------------

class CVario_v1 : public Cfip_vario
{
private:
    Cfip_barometer& _barometer;
    float _delta_h;
    float _delta_t;
    float _altitude;
    float _pressure;
    float _temperature;
    float _sea_level_pressure;

public:
    explicit CVario_v1(Cfip_barometer& barometer) :
        _barometer{barometer},
        _sea_level_pressure{SEA_LEVEL_PRESSURE}
        {};
    ~CVario_v1(){}

    err_code_t setup() override;
    void update() override;
    void set_altitude(float altitude) override;

    float get_pressure() const override {return _pressure;};
    float get_temperature() const override {return _temperature;};
    float get_altitude() const override {return _altitude;};
    float get_delta_h() const override {return _delta_h;};
    float get_delta_t() const override {return _delta_t;};
};

//------------------------------------------------------------------------------

#endif /* FIP_V1_H */
