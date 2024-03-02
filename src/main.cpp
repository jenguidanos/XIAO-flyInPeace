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
#include <buttons/button.h>
#include <commons.h>
#include <curve/curve.h>
#include <iomanip>
#include <sound/sound.h>
#include <variometer/variometer.h>
#include <visualizer/visualizer.h>

using namespace vaf::fip;

//---[ Globals: ]---------------------------------------------------------------

static CfipVario *variometer{nullptr};
static CfipSound *sound{nullptr};
static CfipVisualizer *visualizer{nullptr};
static CfipBarometer *barometer{nullptr};
static CfipCurve *sound_curve{nullptr};
static CfipCurve *visualization_curve{nullptr};
static CfipButtonV1 *button0{nullptr};
static CfipButtonV1 *button1{nullptr};

//---[ Declarations: ]----------------------------------------------------------

static void initialize_fip_object(CfipObj *obj);

//------------------------------------------------------------------------------

void setup()
{
    SERIAL_BEGIN;

    sound = CFactorySound::create(SOUND_TYPE_AD9833);
    initialize_fip_object(sound);

    visualizer = CFactoryVisualizer::create(VISUALIZER_TYPE_NEOPIXEL_V1, STRIP_PIN);
    initialize_fip_object(visualizer);

    barometer = CFactoryBarometer::create(BARO_TYPE_MS5611);
    initialize_fip_object(barometer);

    variometer = CFactoryVariometer::create(VARIO_TYPE_V1, *barometer);
    initialize_fip_object(variometer);

    sound_curve = CFactoryCurve::create(CURVE_TYPE_SOUND_V1);
    initialize_fip_object(sound_curve);

    visualization_curve = CFactoryCurve::create(CURVE_TYPE_VISUALIZER_V1);
    initialize_fip_object(visualization_curve);

    button0 = new CfipButtonV1(BUTTON_PIN0, DEFAULT_LONG_PRESS_LEN);
    initialize_fip_object(button0);

    button1 = new CfipButtonV1(BUTTON_PIN1, DEFAULT_LONG_PRESS_LEN);
    initialize_fip_object(button1);
}

static void initialize_fip_object(CfipObj *obj)
{
    std::stringstream ss;
    ss << " Initializing " << std::string(obj->objType()) << " ...";
    do
    {
        SERIAL_PRINTLN(ss.str().c_str());
        delay(100);
    } while (ERR_CODE_NONE != obj->setup());
}

static void print_output(void)
{
    std::stringstream ss;
    barometer->print(ss);
    variometer->print(ss);
    visualizer->print(ss);
    sound_curve->print(ss);
    visualization_curve->print(ss);
    button0->print(ss);
    button1->print(ss);
    SERIAL_PRINTLN(ss.str().c_str());
}

#define DEBUG

float cnt = 0.0f;

void loop()
{
    button0->update();
    button1->update();

    float vario = {0};

#ifdef DEBUG
    if (EV_SHORT_PRESS == button0->get_event())
    {
        cnt -= 0.05f;
        if (cnt < 0.0f)
            cnt = 1.0f;
    }

    if (EV_SHORT_PRESS == button1->get_event())
    {
        cnt += 0.05f;
        if (cnt > 1.0f)
            cnt = 0.0f;
    }

    vario = cnt;
#else
    variometer->update();
    vario = variometer->get_norm();
#endif

    sound_curve->update(vario);
    sound->update(sound_curve->get());

    visualization_curve->update(vario);
    visualizer->update(visualization_curve->get());

    print_output();

#ifdef DEBUG
    delay(50);
#endif
}

//------------------------------------------------------------------------------

// -- END OF FILE --
