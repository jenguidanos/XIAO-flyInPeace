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

//------------------------------------------------------------------------------

CfipButtonV1::CfipButtonV1(int p, int lp)
    : _was_pressed(false), _generated_event(false), _pressed_counter(0), _pin(p), _long_press_len(lp), _lastLoopTime(0)
{
}

//------------------------------------------------------------------------------

void CfipButtonV1::init()
{
    pinMode(_pin, INPUT);
    digitalWrite(_pin, HIGH); // pull-up
    _was_pressed = false;
    _pressed_counter = 0;
    _lastLoopTime = millis();
}

//------------------------------------------------------------------------------

eEvent CfipButtonV1::handle()
{
    eEvent event(EV_NONE);

    if (millis() - _lastLoopTime < 20)
        return event;

    _lastLoopTime = millis();

    int now_pressed(!digitalRead(_pin));

    if (!now_pressed && _was_pressed && !_generated_event)
    {
        // handle release event
        if (_pressed_counter < _long_press_len)
            event = EV_SHORT_PRESS;
        else
            event = EV_LONG_PRESS;
    }
    else if (now_pressed && _was_pressed)
    {
        // handle release event
        if (_pressed_counter > _long_press_len)
        {
            _pressed_counter = 0;
            event = EV_LONG_PRESS;
            _generated_event = true;
        }
    }

    // update press running duration
    if (now_pressed)
    {
        ++_pressed_counter;
    }
    else
    {
        _pressed_counter = 0;
        _generated_event = false;
    }

    // remember state, and we're done
    _was_pressed = now_pressed;
    return event;
}

//------------------------------------------------------------------------------

CfibButtonV2::CfibButtonV2(uint8_t p) : _button_history(0x00), _pin(p)
{
    pinMode(_pin, INPUT);
    digitalWrite(_pin, HIGH); // pull-up
}

//------------------------------------------------------------------------------

uint8_t CfibButtonV2::is_pressed()
{
    _button_history = _button_history << 1;
    _button_history |= digitalRead(_pin);
    if ((_button_history & B11000111) == B00000111)
    {
        _button_history = B11111111;
        return 1;
    }
    return 0;
}

//------------------------------------------------------------------------------

uint8_t CfibButtonV2::is_released()
{
    _button_history = _button_history << 1;
    _button_history |= digitalRead(_pin);
    if ((_button_history & B11000111) == B11000000)
    {
        _button_history = B00000000;
        return 1;
    }
    return 0;
}

//------------------------------------------------------------------------------

uint8_t CfibButtonV2::is_down() const
{
    return (_button_history == B11111111);
}

//------------------------------------------------------------------------------

uint8_t CfibButtonV2::is_up() const
{
    return (_button_history == B00000000);
}

//------------------------------------------------------------------------------

// -- END OF FILE --