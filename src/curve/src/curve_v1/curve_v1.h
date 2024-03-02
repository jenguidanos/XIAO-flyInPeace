/**
 *  @brief Version 1 curve declaration
 *  @author Cooked by vabarca (TT)
 */

#ifndef CIURVE_V1_H
#define CIURVE_V1_H

//---[ Includes: ]--------------------------------------------------------------

#include <commons.h>

//---[ Typedefs: ]--------------------------------------------------------------

namespace vaf::fip
{

class CCurveSoundV1 : public CfipCurve
{
  private:
    float computed_value_;

  public:
    CCurveSoundV1() = default;
    ~CCurveSoundV1() = default;

    err_code_t setup() override;
    void update(float value) override;
    float get() const override;
    void print(std::stringstream &ss) const override;
};

class CCurveVisualizerV1 : public CfipCurve
{
  private:
    float computed_value_;

  public:
    CCurveVisualizerV1() = default;
    ~CCurveVisualizerV1() = default;

    err_code_t setup() override;
    void update(float value) override;
    float get() const override;
    void print(std::stringstream &ss) const override;
};

} // namespace vaf::fip

//------------------------------------------------------------------------------

#endif /* CIURVE_V1_H */