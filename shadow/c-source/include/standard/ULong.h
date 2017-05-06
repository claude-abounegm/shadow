/**
 * Author: Claude Abounegm
 */
#ifndef SHADOW_ULONG_H
#define SHADOW_ULONG_H

#include <stdint.h>
#include <standard/Class.h>

typedef uint64_t shadow_ulong_t;

SHADOW_NOMANGLE_START
shadow_Class_t* shadowULong_GetClass();
SHADOW_NOMANGLE_END

#endif