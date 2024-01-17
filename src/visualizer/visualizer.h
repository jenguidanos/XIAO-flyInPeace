/**
 *  @brief Visualizer API and factory class declarations
 *  @author Cooked by vabarca (TT)
 */

#ifndef VISUALIZER_H
#define VISUALIZER_H

//---[ Includes: ]--------------------------------------------------------------

#include "commons.h"
#include <cstdint>
#include <string>

//---[ Typedefs: ]--------------------------------------------------------------

typedef enum visualizer_type_e
{
    VISUALIZER_TYPE_UNKNOWN,
    VISUALIZER_TYPE_NEOPIXEL_SINGLE,
    VISUALIZER_TYPE_NEOPIXEL_WHEEL12,

    VISUALIZER_TYPE_MAX_NUM
} visualizer_type_t;

class CFactoryVisualizer
{
  public:
    virtual ~CFactoryVisualizer() = default;
    static CfipVisualizer *create(visualizer_type_t type, uint8_t pin);
};

//------------------------------------------------------------------------------

#endif /* VISUALIZER_H */
