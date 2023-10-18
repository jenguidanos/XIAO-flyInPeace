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
    static const float _termA;
    static const float _termB;
    static const float _termC;
    Cfip_barometer& _barometer;
    float _altitude;
    float _prev_altitude;
    float _sample_time;
    float _prev_sample_time;
    float _pressure;
    float _temperature;
    float _sea_level_pressure;

public:
    explicit CVario_v1(Cfip_barometer& barometer) :
        _barometer{barometer},
        _altitude{0.0f},
        _prev_altitude{0.0f},
        _sample_time{0.0f},
        _prev_sample_time{0.0f},
        _pressure{0.0f},
        _temperature{0.0f},
        _sea_level_pressure{SEA_LEVEL_PRESSURE}
        {};
    ~CVario_v1(){}

    err_code_t setup() override;
    void update() override;
    void set_altitude(float altitude) override;

    float get_pressure() const override {return _pressure;};
    float get_temperature() const override {return _temperature;};
    float get_altitude() const override {return _altitude;};
    void get_delta(float &h, float &t) override;
};

//------------------------------------------------------------------------------

#endif /* FIP_V1_H */
