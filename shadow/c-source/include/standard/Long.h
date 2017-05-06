/**
 * Author: Claude Abounegm
 */
#ifndef SHADOW_LONG_H
#define SHADOW_LONG_H

#include <stdint.h>
#include <standard/Class.h>

typedef int64_t shadow_long_t;

SHADOW_NOMANGLE_START
shadow_Class_t* shadowLong_GetClass();
SHADOW_NOMANGLE_END

#endif