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

class AD9833 : public Cfip_sound
{
private:
    static const uint8_t _pin_data; ///< SPI Data pin number
    static const uint8_t _pin_clk; ///< SPI Clock pin number
    static const uint8_t _pin_fsync; ///< SPI Load pin number (FSYNC in AD9833 usage)
    static const uint8_t _pin_shutdown; ///< Power down pin
    MD_AD9833 ad;

    void powerdown();
    void powerup();

public:

    AD9833();
    ~AD9833()=default;

    void set_vario(float vario) override;
};

//------------------------------------------------------------------------------

#endif /* AD9833_H */

