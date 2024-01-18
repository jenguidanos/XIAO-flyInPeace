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

class CfipNeopixel : public CfipVisualizer
{
  private:
    Adafruit_NeoPixel strip;
    uint16_t hue;
    float max_vario;
    float min_vario;

  private:
    uint16_t palette(float vario);

  public:
    CfipNeopixel(uint8_t pin, uint8_t num_of_pixels);
    ~CfipNeopixel() = default;

    err_code_t setup() override;
    void update() override;
    void set_vario(float vario) override;
    void print(std::stringstream &ss) const override;
    void setMax(float max)
    {
        max_vario = max;
    }
    void setMin(float min)
    {
        min_vario = min;
    }
};

//------------------------------------------------------------------------------

#endif /* MS5611_WRAPPER_H */
