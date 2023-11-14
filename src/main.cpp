/** 
 *  @brief XIAO-flyInPeace project.
 *   Based on MS5611  aka  GY63 - see datasheet
 *
 *  SPI    I2C
 *              +--------+
 *  VCC    VCC  | o      |
 *  GND    GND  | o      |
 *         SCL  | o      |
 *  SDI    SDA  | o      |
 *  CSO         | o      |
 *  SDO         | o L    |   L = led
 *          PS  | o    O |   O = opening  PS = protocol select
 *              +--------+
 *
 *  PS to VCC  ==>  I2C  (GY-63 board has internal pull up, so not needed)
 *  PS to GND  ==>  SPI
 *  CS to VCC  ==>  0x76
 *  CS to GND  ==>  0x77
 *
 *
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
#include <iomanip>
#include <sstream>


//---[ Globals: ]---------------------------------------------------------------

static Cfip_vario* variometer {nullptr};
static Cfip_sound* sound {nullptr};

//---[ Function declarations: ]-------------------------------------------------

static void update_variometer(Cfip_vario* vario);
static void print_variometer(Cfip_vario* vario);

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
    update_variometer(variometer);
    print_variometer(variometer);
    sound->set_vario(variometer->get_vario());
}

static void update_variometer(Cfip_vario* vario)
{
    vario->update();
}

static void print_variometer(Cfip_vario* vario)
{
    std::stringstream ss;
    float h;
    float t;
    ss << " Temperature: " << std::setw(6) << std::fixed << std::setprecision(2) << vario->get_temperature();
    ss << " Pressure: " << std::setw(8) << std::fixed << std::setprecision(2) << vario->get_pressure();
    ss << " Altitude: " << std::setw(5) << std::fixed << std::setprecision(1) << vario->get_altitude();
    ss << " Vario: (m/s)" << std::setw(8) << std::fixed << std::setprecision(3) << vario->get_vario();
    SERIAL_PRINTLN(ss.str().c_str());
}

//------------------------------------------------------------------------------

// -- END OF FILE --
