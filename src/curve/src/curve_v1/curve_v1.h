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

class CCurveV1 : public CfipCurve
{
  private:
    float computed_value_;

  public:
    CCurveV1() = default;
    ~CCurveV1() = default;

    err_code_t setup() override;
    void update(float value) override;
    float get() const override;
    void print(std::stringstream &ss) const override;
};

} // namespace vaf::fip

//------------------------------------------------------------------------------

#endif /* CIURVE_V1_H */