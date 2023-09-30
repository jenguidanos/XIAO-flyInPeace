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

//---[ Globals: ]---------------------------------------------------------------

static Cfip_dev* barometer {NULL};
static Cfip_vario* variometer {NULL};

//---[ Function declarations: ]-------------------------------------------------

static void update_variometer(Cfip_vario* vario);
static void process_variometer_data(Cfip_vario* vario);

//------------------------------------------------------------------------------

void setup()
{
    // Initialize serial port
    SERIAL_BEGIN;

    // Create barometer
    barometer = CFactoryBarometer::create(BARO_TYPE_MS5611);
    err_code_t err = barometer->setup();
    SERIAL_PRINTLN(ERR_CODE_NONE != err? "ERROR: Unable to setup barometer" :
                                         "INFO: Barometer ok");
    if(ERR_CODE_NONE != err) while(true);

    variometer = CFactoryVariometer::create(VARIO_TYPE_V1, *barometer);
    err = variometer->setup();
    SERIAL_PRINTLN(ERR_CODE_NONE != err? "ERROR: Unable to setup variometer" :
                                         "INFO: Variometer ok");

    if(ERR_CODE_NONE != err) while(true);
}

void loop()
{
    update_variometer(variometer);
    process_variometer_data(variometer);
}

static void update_variometer(Cfip_vario* vario)
{
    vario->update();
}

static void process_variometer_data(Cfip_vario* vario)
{
    std::string data_str {"Temperature: " + std::to_string(vario->get_temperature())};
    data_str += " Pressure: " + std::to_string(vario->get_pressure());
    
    SERIAL_PRINTLN(data_str.c_str());
}

//------------------------------------------------------------------------------

// -- END OF FILE --
