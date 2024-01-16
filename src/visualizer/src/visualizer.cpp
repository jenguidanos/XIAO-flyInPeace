/**
 *  @brief Visualizer factory class definition
 *  @author Cooked by Vicente A. (TT)
 */

//---[ Includes: ]--------------------------------------------------------------

#include "fipneopixel/fipneopixel.h"
#include <visualizer/visualizer.h>

//------------------------------------------------------------------------------

Cfip_visualizer *CFactoryVisualizer::create(visualizer_type_t type)
{
    if (BARO_TYPE_SINGLE_NEOPIXEL == type)
        return new CfipNeopixel(1);
    return new Cfip_visualizer();
}

//------------------------------------------------------------------------------

// -- END OF FILE --