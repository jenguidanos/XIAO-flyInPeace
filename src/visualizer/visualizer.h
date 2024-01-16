/** 
 *  @brief Visualizer API and factory class declarations
 *  @author Cooked by vabarca (TT)
 */

#ifndef VISUALIZER_H
#define VISUALIZER_H

//---[ Includes: ]--------------------------------------------------------------

#include <cstdint>
#include <string>
#include "commons.h"

//---[ Typedefs: ]--------------------------------------------------------------

typedef enum visualizer_type_e
{   
    BARO_TYPE_UNKNOWN,
    BARO_TYPE_SINGLE_NEOPIXEL,

    BARO_TYPE_MAX_NUM
}visualizer_type_t;


class CFactoryVisualizer
{
    public:
        virtual ~CFactoryVisualizer()= default;
        static Cfip_visualizer* create(visualizer_type_t type);
};


//------------------------------------------------------------------------------

#endif /* VISUALIZER_H */
