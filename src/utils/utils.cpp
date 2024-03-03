/**
 *  @brief Utilities definitions
 *  @author Cooked by Vicente A. (TT)
 */

//---[ Includes: ]--------------------------------------------------------------

#include "utils.h"
#include <cmath>

using namespace vaf::fip;

//------------------------------------------------------------------------------

err_code_t CMovAvg::setup()
{
    if (!_size)
        return ERR_CODE_SETUP;
    _buffer = (float *)calloc(_size, sizeof(float));
    return _buffer ? ERR_CODE_NONE : ERR_CODE_SETUP;
}

void CMovAvg::update()
{
    _movAvg = CMovAvg::_calculate(_buffer, _size);
}

void CMovAvg::push(float val)
{
    if (!_buffer)
        return;
    _buffer[_movAvgIndex] = val;
    _movAvgIndex = (_movAvgIndex + 1) % _size;
}

float CMovAvg::_calculate(float *buff, int size)
{
    if (!buff)
        return 0.0f;
    float sum = 0.0;
    for (int i = 0; i < size; i++)
        sum += buff[i];
    return sum / size;
}

CMovAvg::~CMovAvg()
{
    if (_buffer)
        free(_buffer);
    _buffer = nullptr;
}

float vaf::fip::fmap(float x, float fromLow, float fromHigh, float toLow, float toHigh)
{
    return (x - fromLow) * (toHigh - toLow) / (fromHigh - fromLow) + toLow;
}

float fmapExt(float x, std::pair<float, float> &a, std::pair<float, float> &b)
{
    return fmap(x, a.first, b.first, a.second, b.second);
}

float vaf::fip::trim_value(float value)
{
    static const float max_value = {1.0f};
    static const float min_value = {0.0f};

    if (value < min_value)
        return min_value;

    return value > max_value ? max_value : value;
}

//------------------------------------------------------------------------------
