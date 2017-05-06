/**
 * Author: Claude Abounegm
 */
#ifndef SHADOW_UINT_H
#define SHADOW_UINT_H

#include <stdint.h>
#include <standard/Class.h>

typedef uint32_t shadow_uint_t;

SHADOW_NOMANGLE_START
shadow_Class_t* shadowUInt_GetClass();
SHADOW_NOMANGLE_END

#endif