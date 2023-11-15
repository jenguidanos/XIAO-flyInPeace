/**
 *  @brief MS5611 Atmospheric Pressure Sensor device
 *  @author Cooked by vabarca (TT)
 */

#ifndef FIP_V1_H
#define FIP_V1_H

//---[ Includes: ]--------------------------------------------------------------

#include <SimpleKalmanFilter.h>
#include <variometer/variometer.h>
#include <persistence/persistence.h>
#include <utils/utils.h>

//---[ Typedefs: ]--------------------------------------------------------------

class CVario_v1 : public Cfip_vario
{
private:
    static const float _termA;
    static const float _termB;
    static const float _termC;
    static const float _millis_in_a_second;
    Cfip_barometer& _barometer;
    Cpersistence _persistence;
    float _altitude;
    float _prev_altitude;
    float _sample_time;
    float _prev_sample_time;
    float _pressure;
    float _temperature;
    float _sea_level_pressure;
    CMovAvg _vario;
    SimpleKalmanFilter _varioKalmanFilter;

public:
    explicit CVario_v1(Cfip_barometer& barometer) :
        _barometer{barometer},
        _altitude{0.0f},
        _prev_altitude{0.0f},
        _sample_time{0.0f},
        _prev_sample_time{0.0f},
        _pressure{0.0f},
        _temperature{0.0f},
        _sea_level_pressure{DEFAULT_SEA_LEVEL_PRESSURE},
        _varioKalmanFilter{SimpleKalmanFilter(1, 1, 0.01)},
        _vario{CMovAvg(32)}
        {}
    ~CVario_v1(){}

    err_code_t setup() override;
    void update() override;
    void set_altitude(float altitude) override;

    float get_pressure() const override {return _pressure;};
    float get_temperature() const override {return _temperature;};
    float get_altitude() const override {return _altitude;};
    float get_vario() const override {return _vario.get();};
    void print(std::stringstream& ss) const override;
    
private:
    float calculate_vario();    
};

//------------------------------------------------------------------------------

#endif /* FIP_V1_H */
