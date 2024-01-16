/**
 *  @brief Neopixel visualizer declaration
 *  @author Cooked by vabarca (TT)
 */

#ifndef MS5611_WRAPPER_H
#define MS5611_WRAPPER_H

//---[ Includes: ]--------------------------------------------------------------

#include <commons.h>

//---[ Typedefs: ]--------------------------------------------------------------

class CfipNeopixel : public CfipVisualizer
{
  private:
    uint8_t num_of_pixels;

  public:
    CfipNeopixel() : CfipNeopixel(1)
    {
    }
    CfipNeopixel(uint8_t num_of_pixels);
    ~CfipNeopixel() = default;

    void set_vario(float vario) override;
};

//------------------------------------------------------------------------------

#endif /* MS5611_WRAPPER_H */
