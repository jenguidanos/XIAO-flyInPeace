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

#include <commons.h>

//---[ Global defines: ]--------------------------------------------------------

namespace vaf::fip
{

#define DEFAULT_LONG_PRESS_LEN 20 // Min nr of loops for a long press

//---[ Typedefs: ]--------------------------------------------------------------

enum eEvent
{
    EV_NONE = 0,
    EV_SHORT_PRESS,
    EV_LONG_PRESS
};

//------------------------------------------------------------------------------

class CfipButtonV1 : public CfipButton
{
  protected:
    boolean was_pressed_;      // previous state
    boolean generated_event_;  // generated event before release button
    int pressed_counter_;      // press running duration
    const uint8_t pin_;        // pin to which button is connected
    const int long_press_len_; // long-press duration
    long lastLoopTime_;
    eEvent event_;

  public:
    explicit CfipButtonV1(int pin, int long_press_len = DEFAULT_LONG_PRESS_LEN);
    ~CfipButtonV1() = default;

    void update() override;
    eEvent get_event() const {return event_;}
    err_code_t setup() override;
    void print(std::stringstream &ss) const override;
};

//------------------------------------------------------------------------------
// http://hackaday.com/2015/12/10/embed-with-elliot-debounce-your-noisy-buttons-part-ii/

class CfibButtonV2 : public CfipButton
{
  protected:
    uint8_t button_history_;
    const uint8_t pin_; // pin to which button is connected

  public:
    explicit CfibButtonV2(uint8_t pin);
    ~CfibButtonV2() = default;

    uint8_t is_pressed();
    uint8_t is_released();
    uint8_t is_down() const;
    uint8_t is_up() const;

    void print(std::stringstream &ss) const override;
};

} // namespace vaf::fip

//------------------------------------------------------------------------------

#endif /* BUTTON_H */
