/**
 *  @brief Generic sound handler API and factory class declarations
 *  @author Cooked by vabarca (TT)
 */

#ifndef SOUND_H
#define SOUND_H

//---[ Includes: ]--------------------------------------------------------------

#include <commons.h>

//---[ Typedefs: ]--------------------------------------------------------------

typedef enum sound_type_e
{
    SOUND_TYPE_UNKNOWN,
    SOUND_TYPE_AD9833,

    SOUND_TYPE_MAX_NUM
} sound_type_t;

class CFactorySound
{
  public:
    virtual ~CFactorySound() = default;
    static CfipSound *create(sound_type_t type);
};

//------------------------------------------------------------------------------

#endif /* SOUND_H */
