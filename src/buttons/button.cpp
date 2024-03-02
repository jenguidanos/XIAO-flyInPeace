/**
 *  @brief Buttons handler classes definitions
 *  @author Original from (C) 2011 By P. Bauermeister
 *  @author Cooked by Vicente A. (TT)
 */

//---[ Includes: ]--------------------------------------------------------------

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "button.h"

using namespace vaf::fip;

//------------------------------------------------------------------------------

CfipButtonV1::CfipButtonV1(int p, int lp)
    : was_pressed_(false), generated_event_(false), pressed_counter_(0), pin_(p), long_press_len_(lp), lastLoopTime_(0)
{
}

err_code_t CfipButtonV1::setup()
{
    pinMode(pin_, INPUT);
    digitalWrite(pin_, HIGH); // pull-up
    was_pressed_ = false;
    pressed_counter_ = 0;
    lastLoopTime_ = millis();
    return ERR_CODE_NONE;
}

void CfipButtonV1::update()
{
    event_ = EV_NONE;

    if (millis() - lastLoopTime_ < 20)
        return;

    lastLoopTime_ = millis();

    int now_pressed(!digitalRead(pin_));

    if (!now_pressed && was_pressed_ && !generated_event_)
    {
        // handle release event
        if (pressed_counter_ < long_press_len_)
            event_ = EV_SHORT_PRESS;
        else
            event_ = EV_LONG_PRESS;
    }
    else if (now_pressed && was_pressed_)
    {
        // handle release event
        if (pressed_counter_ > long_press_len_)
        {
            pressed_counter_ = 0;
            event_ = EV_LONG_PRESS;
            generated_event_ = true;
        }
    }

    // update press running duration
    if (now_pressed)
    {
        ++pressed_counter_;
    }
    else
    {
        pressed_counter_ = 0;
        generated_event_ = false;
    }

    // remember state, and we're done
    was_pressed_ = now_pressed;
}

void CfipButtonV1::print(std::stringstream &ss) const
{
    const char* msg = EV_NONE != get_event()? "YES" : "NO";
    ss << " Pressed: " << std::string(msg);
}

//------------------------------------------------------------------------------

CfibButtonV2::CfibButtonV2(uint8_t p) : button_history_(0x00), pin_(p)
{
    pinMode(pin_, INPUT);
    digitalWrite(pin_, HIGH); // pull-up
}

uint8_t CfibButtonV2::is_pressed()
{
    button_history_ = button_history_ << 1;
    button_history_ |= digitalRead(pin_);
    if ((button_history_ & B11000111) == B00000111)
    {
        button_history_ = B11111111;
        return 1;
    }
    return 0;
}

uint8_t CfibButtonV2::is_released()
{
    button_history_ = button_history_ << 1;
    button_history_ |= digitalRead(pin_);
    if ((button_history_ & B11000111) == B11000000)
    {
        button_history_ = B00000000;
        return 1;
    }
    return 0;
}

uint8_t CfibButtonV2::is_down() const
{
    return (button_history_ == B11111111);
}

uint8_t CfibButtonV2::is_up() const
{
    return (button_history_ == B00000000);
}

void CfibButtonV2::print(std::stringstream &ss) const
{
    ss << " Pressed: " << is_down()? "YES" : "NO";
}

//------------------------------------------------------------------------------

// -- END OF FILE --