/**
 *  @brief Neopixel visualizer declaration
 *  @author Cooked by vabarca (TT)
 */

#ifndef MS5611_WRAPPER_H
#define MS5611_WRAPPER_H

//---[ Includes: ]--------------------------------------------------------------

#include <Adafruit_NeoPixel.h>
#include <commons.h>

//---[ Typedefs: ]--------------------------------------------------------------

namespace vaf::fip
{

class CfipNeopixel : public CfipVisualizer
{
  private:
    Adafruit_NeoPixel strip_;
    uint16_t hue_;

  private:
    uint16_t palette(float vario);

  public:
    CfipNeopixel(uint8_t pin, uint8_t num_of_pixels);
    ~CfipNeopixel() = default;

    err_code_t setup() override;
    void update(float value) override;
    void print(std::stringstream &ss) const override;
};

} // namespace vaf::fip

//------------------------------------------------------------------------------

#endif /* MS5611_WRAPPER_H */
