/**
 *  @brief Buttons handler classes declaration
 *  @author Original from (C) 2011 By P. Bauermeister
 *  @author Cooked by Vicente A. (TT)
 */

#ifndef BUTTON_H
#define BUTTON_H

//---[ Includes: ]--------------------------------------------------------------

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

//---[ Global defines: ]--------------------------------------------------------

#define DEFAULT_LONG_PRESS_LEN 30 // Min nr of loops for a long press

//---[ Typedefs: ]--------------------------------------------------------------

enum eEvent
{
    EV_NONE = 0,
    EV_SHORT_PRESS,
    EV_LONG_PRESS
};

//------------------------------------------------------------------------------

class CfipButtonV1
{
  protected:
    boolean _was_pressed;      // previous state
    boolean _generated_event;  // generated event before release button
    int _pressed_counter;      // press running duration
    const uint8_t _pin;        // pin to which button is connected
    const int _long_press_len; // long-press duration
    long _lastLoopTime;

  public:
    explicit CfipButtonV1(int pin, int long_press_len = DEFAULT_LONG_PRESS_LEN);
    ~CfipButtonV1() = default;

    // Initialization done after construction, to permit static instances
    void init();

    // Handler, to be called in the loop()
    eEvent handle();
};

//------------------------------------------------------------------------------
// http://hackaday.com/2015/12/10/embed-with-elliot-debounce-your-noisy-buttons-part-ii/

class CfibButtonV2
{
  protected:
    uint8_t _button_history;
    const uint8_t _pin; // pin to which button is connected

  public:
    explicit CfibButtonV2(uint8_t pin);
    ~CfibButtonV2() = default;

    uint8_t is_pressed();
    uint8_t is_released();
    uint8_t is_down() const;
    uint8_t is_up() const;
};

//------------------------------------------------------------------------------

#endif /* BUTTON_H */
