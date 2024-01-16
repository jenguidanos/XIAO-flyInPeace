/**
 *  @brief Atmospheric Pressure Sensor factory class definition
 *  @author Cooked by Vicente A. (TT)
 */

//---[ Includes: ]--------------------------------------------------------------

#include "vario_v1.h"
#include <cmath>
#include <iomanip>
#include <persistence/persistence.h>

//------------------------------------------------------------------------------

err_code_t CVario_v1::setup()
{
    _vario.setup();
    _persistence.setup();
    _persistence.read(0, _sea_level_pressure);

    if (isnan(_sea_level_pressure))
    {
        /*Just for the first time*/
        _sea_level_pressure = DEFAULT_SEA_LEVEL_PRESSURE;
        _persistence.write(0, _sea_level_pressure);
    }

    return ERR_CODE_NONE;
}

const float CVario_v1::_termA{1.0f / 5.257f};
const float CVario_v1::_termB{0.0065f};
const float CVario_v1::_termC{5.257f};
const float CVario_v1::_millis_in_a_second{1000.0f};

void CVario_v1::update()
{
    _barometer.update();
    _pressure = _barometer.get_pressure();
    _temperature = _barometer.get_temperature();
    _altitude = (((pow((_sea_level_pressure / _pressure), CVario_v1::_termA) - 1.0f) * (_temperature + ABSOLUTE_ZERO)) /
                 CVario_v1::_termB);
    _sample_time = millis();
    _vario.push(calculate_vario());
    _vario.update();
}

void CVario_v1::set_altitude(float altitude)
{
    _sea_level_pressure =
        _pressure * pow(((CVario_v1::_termB * altitude) / (_temperature + ABSOLUTE_ZERO) + 1.0f), CVario_v1::_termC);
    _persistence.write(0, _sea_level_pressure);
}

float CVario_v1::calculate_vario()
{
    float h = _altitude - _prev_altitude;
    float t = _sample_time - _prev_sample_time;
    _prev_altitude = _altitude;
    _prev_sample_time = _sample_time;

    float vario{h * CVario_v1::_millis_in_a_second / t};

    return _varioKalmanFilter.updateEstimate(vario);
}

void CVario_v1::print(std::stringstream &ss) const
{
    _barometer.print(ss);
    ss << " Altitude: " << std::setw(5) << std::fixed << std::setprecision(1) << get_altitude();
    ss << " Vario: (m/s)" << std::setw(8) << std::fixed << std::setprecision(3) << get_vario();
}

//------------------------------------------------------------------------------
