/**
 * Author: Claude Abounegm
 */
#ifndef SHADOW_SHORT_H
#define SHADOW_SHORT_H

#include <stdint.h>
#include <standard/Class.h>

typedef int16_t shadow_short_t;

SHADOW_NOMANGLE_START
shadow_Class_t* shadowShort_GetClass();
SHADOW_NOMANGLE_END

#endif