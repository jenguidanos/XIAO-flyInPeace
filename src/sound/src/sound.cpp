/** 
 *  @brief Sound handler factory class definition
 *  @author Cooked by Vicente A. (TT)
 */

//---[ Includes: ]--------------------------------------------------------------

#include <sound/sound.h>
#include "ad9833/ad9833.h"

//------------------------------------------------------------------------------

Cfip_sound* CFactorySound::create(sound_type_t type)
{
    if(SOUND_TYPE_AD9833 == type) return new AD9833();
    return new Cfip_sound();
}


//------------------------------------------------------------------------------

// -- END OF FILE --
