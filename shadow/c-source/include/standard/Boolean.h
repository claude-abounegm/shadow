/**
 * Author: Claude Abounegm
 */
#ifndef SHADOW_BOOLEAN_H
#define SHADOW_BOOLEAN_H

#include <stdbool.h>
#include <standard/Class.h>

typedef bool shadow_boolean_t;

SHADOW_NOMANGLE_START
shadow_Class_t* shadowBoolean_GetClass();
SHADOW_NOMANGLE_END

#endif