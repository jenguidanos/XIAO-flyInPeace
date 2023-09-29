/** 
 *  @brief IAO-flyInPeace pin assignment project file
 *
 *  @author Cooked by Vicente A. (TT)
 */

#ifndef PINOUT_H
#define PINOUT_H

//---[ Includes: ]--------------------------------------------------------------

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

//------------------------------------------------------------------------------

/**
 * Button0 pin assignment
 */
const uint8_t BUTTON_PIN0         (8);

/**
 * Button1 pin assignment
 */
const uint8_t BUTTON_PIN1         (7);

/**
 * LED pins assignment
 */
const uint8_t LED_PIN             (13);

/**
 * I2C0
 */
const uint8_t I2C_SCL0            (5);
const uint8_t I2C_SDA0            (4);

//------------------------------------------------------------------------------

#endif /* PINOUT_H */


