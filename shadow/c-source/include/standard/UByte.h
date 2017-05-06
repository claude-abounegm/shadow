/**
 * Author: Claude Abounegm
 */
#ifndef SHADOW_UBYTE_H
#define SHADOW_UBYTE_H

#include <stdint.h>
#include <standard/Class.h>

typedef uint8_t shadow_ubyte_t;

SHADOW_NOMANGLE_START
shadow_Class_t* shadowUByte_GetClass();
SHADOW_NOMANGLE_END

#endif