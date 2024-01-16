/** 
 *  @brief Atmospheric Pressure Sensor factory class definition
 *  @author Cooked by Vicente A. (TT)
 */

//---[ Includes: ]--------------------------------------------------------------

#include <visualizer/visualizer.h>
#include "fipeopixel/fipeopixel.h"

//------------------------------------------------------------------------------

Cfip_visualizer* CFactoryVisualizer::create(visualizer_type_t type)
{
    if(BARO_TYPE_SINGLE_NEOPIXEL == type) return new CfipNeopixel(1);
    return new Cfip_visualizer();
}


//------------------------------------------------------------------------------

// -- END OF FILE --