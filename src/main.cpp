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
#include <barometer/barometer.h>
#include <commons.h>
#include <sound/sound.h>
#include <variometer/variometer.h>
#include <visualizer/visualizer.h>

//---[ Globals: ]---------------------------------------------------------------

static CfipVario *variometer{nullptr};
static CfipSound *sound{nullptr};
static CfipVisualizer *visualizer{nullptr};

//------------------------------------------------------------------------------

void setup()
{
    // Initialize serial port
    SERIAL_BEGIN;

    // Create barometer
    CfipBarometer *barometer = CFactoryBarometer::create(BARO_TYPE_MS5611);
    err_code_t err = barometer->setup();
    SERIAL_PRINTLN(ERR_CODE_NONE != err ? "ERROR: Unable to setup barometer" : "INFO: Barometer ok");
    if (ERR_CODE_NONE != err)
        while (true)
            ;

    variometer = CFactoryVariometer::create(VARIO_TYPE_V1, *barometer);
    err = variometer->setup();
    SERIAL_PRINTLN(ERR_CODE_NONE != err ? "ERROR: Unable to setup variometer" : "INFO: Variometer ok");

    if (ERR_CODE_NONE != err)
    {
        while (true)
            ;
    }

    sound = CFactorySound::create(SOUND_TYPE_AD9833);
    err = sound->setup();
    SERIAL_PRINTLN(ERR_CODE_NONE != err ? "ERROR: Unable to setup sound" : "INFO: sound ok");

    if (ERR_CODE_NONE != err)
    {
        while (true)
            ;
    }

    visualizer = CFactoryVisualizer::create(VISUALIZER_TYPE_SINGLE_NEOPIXEL);
    err = visualizer->setup();
    SERIAL_PRINTLN(ERR_CODE_NONE != err ? "ERROR: Unable to setup visualizer" : "INFO: visualizer ok");

    if (ERR_CODE_NONE != err)
    {
        while (true)
            ;
    }
}

void loop()
{
    variometer->update();
    float vario = variometer->get_vario();
    sound->set_vario(vario);
    visualizer->set_vario(vario);

    std::stringstream ss;
    variometer->print(ss);
    SERIAL_PRINTLN(ss.str().c_str());
}

//------------------------------------------------------------------------------

// -- END OF FILE --
