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
    static const uint8_t _pin_data;     ///< SPI Data pin number
    static const uint8_t _pin_clk;      ///< SPI Clock pin number
    static const uint8_t _pin_cs;       ///< SPI Load pin number (FSYNC in AD9833 usage)
    static const uint8_t _pin_shutdown; ///< Power down pin
    MD_AD9833 ad;

    void powerdown();
    void powerup();

  public:
    CSoundAD9833() : ad(CSoundAD9833::_pin_data, CSoundAD9833::_pin_clk, CSoundAD9833::_pin_cs)
    {
    }
    ~CSoundAD9833() = default;

    err_code_t setup() override;
    void set_vario(float vario) override;
};

} // namespace vaf::fip

//------------------------------------------------------------------------------

#endif /* AD9833_H */
