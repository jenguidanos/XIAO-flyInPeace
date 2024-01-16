/**
 *  @brief IAO-flyInPeace configuration project file
 *  @author Cooked by Vicente A. (TT)
 */

#ifndef CONFIG_H
#define CONFIG_H

//---[ Includes: ]--------------------------------------------------------------

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

//---[ Defines: ]---------------------------------------------------------------

#define SERIAL_OUTPUT

//---[ Macros: ]----------------------------------------------------------------

#ifdef SERIAL_OUTPUT
#define SERIAL_BEGIN Serial.begin(115200)
#define SERIAL_PRINTLN(a) Serial.println(a)
#define SERIAL_PRINT(a) Serial.print(a)
#else
#define SERIAL_BEGIN
#define SERIAL_PRINTLN(a)
#define SERIAL_PRINT(a)
#endif

//-----------------------------------------------------------------------------

#endif /* CONFIG_H */
