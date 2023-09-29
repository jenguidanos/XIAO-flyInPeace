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

#include "config.h"
#include "pinout.h"
#include "buttons/button_handler.h"

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include <barometer/barometer.h>
#include <commons/commons.h>

//---[ Globals: ]---------------------------------------------------------------

CButtonHandler goButton0(BUTTON_PIN0, DEFAULT_LONGPRESS_LEN);
CButtonHandler goButton1(BUTTON_PIN1, DEFAULT_LONGPRESS_LEN);
static CBarometer* baro {NULL};

//---[ Function declarations: ]-------------------------------------------------

static void process_button_events();
static void update_barometer(CBarometer* baro);
static void process_barometer_data(CBarometer* baro);

//------------------------------------------------------------------------------

void setup()
{
    // Initialize serial port
    SERIAL_BEGIN;

    // Initialize button
    goButton0.init();
    goButton1.init();
    delay(200);

    // Create barometer
    baro = CFactoryBarometer::create(BARO_TYPE_MS5611);
    err_code_t err {baro->setup()};

    SERIAL_PRINTLN(ERR_CODE_NONE != err? "ERROR: Unable to setup barometer" : 
                                         "INFO: Barometer ok");

    if (ERR_CODE_NONE != err) while (true);
}

void loop()
{
    process_button_events();
    update_barometer(baro);
    process_barometer_data(baro);
}

static void process_button_events()
{
    eEvent event(goButton0.handle());
    if (event == EV_SHORTPRESS);
    if (event == EV_LONGPRESS);
    event = goButton1.handle();
    if (event == EV_SHORTPRESS);
    if (event == EV_LONGPRESS);
}

static void update_barometer(CBarometer* const baro)
{
    baro->update();
}

static void process_barometer_data(CBarometer* const baro)
{
    std::string data_str {"Temperature: " + std::to_string(baro->get_temperature())};
    data_str += " Pressure: " + std::to_string(baro->get_pressure());
    
    SERIAL_PRINTLN(data_str.c_str());
}

//------------------------------------------------------------------------------

// -- END OF FILE --




/*










uint32_t start, stop;


void setup()
{
  delay(5000);
  Serial.begin(9600);
  while(!Serial);

  Serial.println();
  Serial.println(__FILE__);
  Serial.print("MS5611_LIB_VERSION: ");
  Serial.println(MS5611_LIB_VERSION);

  if (MS5611.begin() == true)
  {
    Serial.println("MS5611 found.");
  }
  else
  {
    Serial.println("MS5611 not found. halt.");
    while (1);
  }
  Serial.println();

  Serial.println("OSR \t TIME");


  start = micros();
  MS5611.read();   // uses default OSR_ULTRA_LOW  (fastest)
  stop = micros();
  Serial.print( (uint8_t) MS5611.getOversampling());
  Serial.print("\t");
  Serial.println(stop - start);
  delay(10); // to flush serial.


  MS5611.setOversampling(OSR_LOW);
  start = micros();
  MS5611.read();
  stop = micros();
  Serial.print( (uint8_t) MS5611.getOversampling());
  Serial.print("\t");
  Serial.println(stop - start);
  delay(10); // to flush serial.


  MS5611.setOversampling(OSR_STANDARD);
  start = micros();
  MS5611.read();
  stop = micros();
  Serial.print( (uint8_t) MS5611.getOversampling());
  Serial.print("\t");
  Serial.println(stop - start);
  delay(10); // to flush serial.


  MS5611.setOversampling(OSR_HIGH);
  start = micros();
  MS5611.read();
  stop = micros();
  Serial.print( (uint8_t) MS5611.getOversampling());
  Serial.print("\t");
  Serial.println(stop - start);
  delay(10); // to flush serial.


  MS5611.setOversampling(OSR_ULTRA_HIGH);
  start = micros();
  MS5611.read();
  stop = micros();
  Serial.print( (uint8_t) MS5611.getOversampling());
  Serial.print("\t");
  Serial.println(stop - start);
  delay(10); // to flush serial.


  Serial.println("\ndone...");
}

void loop()
{
}
*/

