/**
 *  @brief AD9833 sound handler declaration
 *  @author Cooked by vabarca (TT)
 */

#ifndef AD9833_H
#define AD9833_H

//---[ Includes: ]--------------------------------------------------------------

#include <MD_AD9833.h>
#include <commons.h>

//---[ Typedefs: ]--------------------------------------------------------------

namespace vaf::fip
{

class CSoundAD9833 : public CfipSound
{
  private:
    static const uint8_t pin_data_;     ///< SPI Data pin number
    static const uint8_t pin_clk_;      ///< SPI Clock pin number
    static const uint8_t pin_cs_;       ///< SPI Load pin number (FSYNC in AD9833 usage)
    static const uint8_t pin_shutdown_; ///< Power down pin
    MD_AD9833 ad_;
    float tone_{0.0f};

    void powerdown();
    void powerup();

  public:
    CSoundAD9833() : ad_(CSoundAD9833::pin_data_, CSoundAD9833::pin_clk_, CSoundAD9833::pin_cs_)
    {
    }
    ~CSoundAD9833() = default;

    err_code_t setup() override;
    void update(float value) override;
};

} // namespace vaf::fip

//------------------------------------------------------------------------------

#endif /* AD9833_H */
