/**
 *  @brief Buttons handler classes definitions
 *  @author Cooked by Vicente A. (TT)
 */

//---[ Includes: ]-------------------------------------------------------------

#include "persistence.h"

#define PERSISTENCE_STORAGE_SIZE 1024

//------------------------------------------------------------------------------

void Cpersistence::setup()
{
    EEPROM.begin(PERSISTENCE_STORAGE_SIZE);
}

//------------------------------------------------------------------------------

// -- END OF FILE --
