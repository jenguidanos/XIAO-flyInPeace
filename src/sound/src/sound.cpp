/**
 *  @brief Sound handler factory class definition
 *  @author Cooked by Vicente A. (TT)
 */

//---[ Includes: ]--------------------------------------------------------------

#include "ad9833/ad9833.h"
#include <sound/sound.h>

//------------------------------------------------------------------------------

CfipSound *CFactorySound::create(sound_type_t type)
{
    if (SOUND_TYPE_AD9833 == type)
        return new CSoundAD9833();
    return new CfipSound();
}

//------------------------------------------------------------------------------

// -- END OF FILE --
