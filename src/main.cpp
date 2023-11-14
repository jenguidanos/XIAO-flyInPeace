/** 
 *  @brief XIAO-flyInPeace project.
 *  @author Cooked by Vicente A. (TT)
  */

//---[ Includes: ]--------------------------------------------------------------

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "config.h"
#include <commons.h>
#include <barometer/barometer.h>
#include <variometer/variometer.h>
#include <sound/sound.h>

//---[ Globals: ]---------------------------------------------------------------

static Cfip_vario* variometer {nullptr};
static Cfip_sound* sound {nullptr};

//------------------------------------------------------------------------------

void setup()
{
    // Initialize serial port
    SERIAL_BEGIN;

    // Create barometer
    Cfip_barometer* barometer = CFactoryBarometer::create(BARO_TYPE_MS5611);
    err_code_t err = barometer->setup();
    SERIAL_PRINTLN(ERR_CODE_NONE != err? "ERROR: Unable to setup barometer" :
                                         "INFO: Barometer ok");
    if(ERR_CODE_NONE != err) while(true);

    variometer = CFactoryVariometer::create(VARIO_TYPE_V1, *barometer);
    err = variometer->setup();
    SERIAL_PRINTLN(ERR_CODE_NONE != err? "ERROR: Unable to setup variometer" :
                                         "INFO: Variometer ok");
    
    sound = CFactorySound::create(SOUND_TYPE_AD9833);

    if(ERR_CODE_NONE != err) while(true);
}

void loop()
{
    variometer->update();
    sound->set_vario(variometer->get_vario());

    std::stringstream ss;
    variometer->print(ss);
    SERIAL_PRINTLN(ss.str().c_str());
}

//------------------------------------------------------------------------------

// -- END OF FILE --
