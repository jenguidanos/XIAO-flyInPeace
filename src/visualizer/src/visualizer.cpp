/**
 *  @brief Visualizer factory class definition
 *  @author Cooked by Vicente A. (TT)
 */

//---[ Includes: ]--------------------------------------------------------------

#include "fip_neopixel/fip_neopixel.h"
#include <visualizer/visualizer.h>

//------------------------------------------------------------------------------

CfipVisualizer *CFactoryVisualizer::create(visualizer_type_t type)
{
    if (VISUALIZER_TYPE_SINGLE_NEOPIXEL == type)
        return new CfipNeopixel(1);
    return new CfipVisualizer();
}

//------------------------------------------------------------------------------

// -- END OF FILE --