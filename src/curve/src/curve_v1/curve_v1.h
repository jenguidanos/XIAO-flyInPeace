/**
 *  @brief Version 1 curve declaration
 *  @author Cooked by vabarca (TT)
 */

#ifndef CIURVE_V1_H
#define CIURVE_V1_H

//---[ Includes: ]--------------------------------------------------------------

#include <commons.h>
#include <vector>

//---[ Typedefs: ]--------------------------------------------------------------

namespace vaf::fip
{

class CCurveParametricV1 : public CfipCurve
{
  protected:
    std::vector<std::pair<float, float>> points_;
  public:
    virtual ~CCurveParametricV1() = default;
    void update(float value) override;
};

class CCurveSoundV1 : public CCurveParametricV1
{
  public:
    virtual ~CCurveSoundV1() = default;
    CCurveSoundV1()
    {
        points_.push_back({-100.0f, 0.0f});
        points_.push_back({0.1f, 0.0f});
        points_.push_back({3.0f, 1.0f});
        points_.push_back({3.1f, 0.0f});
        points_.push_back({100.0f, 0.0f});
    }
};

class CCurveVisualizerV1 : public CCurveParametricV1
{
  public:
    virtual ~CCurveVisualizerV1() = default;
    CCurveVisualizerV1()
    {
        points_.push_back({-100.0f, 0.0f});
        points_.push_back({0.1f, 0.0f});
        points_.push_back({3.0f, 1.0f});
        points_.push_back({3.1f, 0.0f});
        points_.push_back({100.0f, 0.0f});
    }
};

} // namespace vaf::fip

//------------------------------------------------------------------------------

#endif /* CIURVE_V1_H */