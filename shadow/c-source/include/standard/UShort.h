/**
 * Author: Claude Abounegm
 */
#ifndef SHADOW_USHORT_H
#define SHADOW_USHORT_H

#include <stdint.h>
#include <standard/Class.h>

typedef uint16_t shadow_ushort_t;

SHADOW_NOMANGLE_START
shadow_Class_t* shadowUShort_GetClass();
SHADOW_NOMANGLE_END

#endif