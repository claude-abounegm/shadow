/**
 * Author: Claude Abounegm
 */
#ifndef SHADOW_INT_H
#define SHADOW_INT_H

#include <stdint.h>
#include <standard/Class.h>

typedef int32_t shadow_int_t;

SHADOW_NOMANGLE_START
shadow_Class_t* shadowInt_GetClass();
SHADOW_NOMANGLE_END

#endif