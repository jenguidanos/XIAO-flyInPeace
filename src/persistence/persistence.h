/**
 * @brief Utility to save data to eeprom. Data can be both simple data and
 * complex structures
 * @author Cooked by Vicente A. (TT)
 */

#ifndef  PERSISTENCE_H
#define  PERSISTENCE_H

#include <EEPROM.h>

//---[ Methods: ]-------------------------------------------------------------

class Cpersistence
{
public:
    Cpersistence()= default;
    ~Cpersistence()= default;

    void setup();
    template <class T> int write(int ee, const T& target);
    template <class T> int read(int ee, T& target);
};

template<class T>
int Cpersistence::read(int ee, T &target) {
    byte* p = (byte*)(void*)&target;
    unsigned int i;
    for (i = 0; i < sizeof(target); i++)
    {
        *p++ = EEPROM.read(ee++);
    }
    return i;
}

template<class T>
int Cpersistence::write(int ee, const T &target) {
    const byte* p = (const byte*)(const void*)&target;
    unsigned int i;
    for (i = 0; i < sizeof(target); i++)
    {
        EEPROM.write(ee++, *p++);
    }
    EEPROM.commit();
    return i;
}

//-----------------------------------------------------------------------------

#endif // PERSISTENCE_H

