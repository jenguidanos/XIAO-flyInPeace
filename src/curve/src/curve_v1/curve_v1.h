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
  private:
    std::vector<std::pair<float, float>> points_ = {
        {0.0f, 0.0f}, {0.01f, 0.0f}, {0.02f, 1.0f}, {0.3f, 0.0f}, {1.0f, 0.0f}};

  public:
    void update(float value) override;
};

class CCurveSoundV1 : public CfipCurve
{
  public:
    void update(float value) override;
};

class CCurveVisualizerV1 : public CfipCurve
{
  public:
    void update(float value) override;
};

} // namespace vaf::fip

//------------------------------------------------------------------------------

#endif /* CIURVE_V1_H */