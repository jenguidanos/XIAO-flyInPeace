/**
 *  @brief Buttons handler classes definitions
 *  @author Cooked by Vicente A. (TT)
 */

//---[ Includes: ]--------------------------------------------------------------

#include "persistence.h"

using namespace vaf::fip;

//---[ Defines: ]---------------------------------------------------------------

#define PERSISTENCE_STORAGE_SIZE 1024

//------------------------------------------------------------------------------

void CfipPersistence::setup()
{
    EEPROM.begin(PERSISTENCE_STORAGE_SIZE);
}

//------------------------------------------------------------------------------

// -- END OF FILE --
