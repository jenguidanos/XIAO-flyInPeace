/**
 *  @brief Visualizer factory class definition
 *  @author Cooked by Vicente A. (TT)
 */

//---[ Includes: ]--------------------------------------------------------------

#include "fip_neopixel/fip_neopixel.h"
#include <visualizer/visualizer.h>

//------------------------------------------------------------------------------

CfipVisualizer *CFactoryVisualizer::create(visualizer_type_t type, uint8_t pin)
{
    if (VISUALIZER_TYPE_NEOPIXEL_SINGLE == type)
        return new CfipNeopixel(pin, 1);
    if (VISUALIZER_TYPE_NEOPIXEL_WHEEL12 == type)
        return new CfipNeopixel(pin, 12);
    if (VISUALIZER_TYPE_NEOPIXEL_WHEEL9 == type)
        return new CfipNeopixel(pin, 9);        
    return new CfipVisualizer();
}

//------------------------------------------------------------------------------

// -- END OF FILE --