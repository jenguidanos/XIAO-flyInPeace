/**
 *  @brief IAO-flyInPeace project version file
 *  @author Cooked by Vicente A. (TT)
 */

#ifndef VERSION_H
#define VERSION_H

//---[ Includes: ]--------------------------------------------------------------

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

    //---[ Pin assignement: ]-------------------------------------------------------

#ifndef STR_HELPER
#define STR_HELPER(x) #x
#endif
#ifndef STR
#define STR(x) STR_HELPER(x)
#endif

//<h>Version
//   <i>Firmware version
//       <o>Major version <0-255>
#define VERSION_NUMBERS_1 0
//       <o>Minor version <0-255>
#define VERSION_NUMBERS_2 1
//       <o>Revision <0-255>
#define VERSION_NUMBERS_3 0
//       <o>Release candidate <0-255>
#define VERSION_NUMBERS_4 0

#define SOFTWARE_VERSION                                                                                               \
    ((VERSION_NUMBERS_1 << 24) + (VERSION_NUMBERS_2 << 16) + (VERSION_NUMBERS_3 << 8) + VERSION_NUMBERS_4)

#define SOFTWARE_SIGNATURE                                                                                             \
    " ** VAF-FIP v" STR(VERSION_NUMBERS_1) "." STR(VERSION_NUMBERS_2) "." STR(                                         \
        VERSION_NUMBERS_3) " - "                                                                                       \
                           "_rc" STR(VERSION_NUMBERS_4) " - " __DATE__ " " __TIME__ " ** "

    //-----------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif /* VERSION_H */
