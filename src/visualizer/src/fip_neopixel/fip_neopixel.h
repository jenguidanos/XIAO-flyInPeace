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

  protected:
    uint16_t palette_(float vario);
    Adafruit_NeoPixel *get_strip_()
    {
        return &strip_;
    };
    uint16_t get_hue_()
    {
        return hue_;
    };
    void set_hue_(uint16_t hue)
    {
        hue_ = hue;
    };
    void update_(float value, uint16_t first, uint16_t cnt, uint8_t brightness);

  public:
    CfipNeopixel(uint8_t pin, uint8_t num_of_pixels);
    ~CfipNeopixel() = default;

    err_code_t setup() override;
    void update(float value) override;
    void print(std::stringstream &ss) const override;
};

class CfipNeopixelV1 : public CfipNeopixel
{
  private:
    static const uint8_t NUM_OF_PIXELS{9};

  public:
    CfipNeopixelV1(uint8_t pin) : CfipNeopixel(pin, NUM_OF_PIXELS)
    {
    }
    ~CfipNeopixelV1() = default;

    void update(float value) override;
};

} // namespace vaf::fip

//------------------------------------------------------------------------------

#endif /* MS5611_WRAPPER_H */
