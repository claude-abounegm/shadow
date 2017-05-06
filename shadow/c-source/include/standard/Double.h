/**
 * Author: Claude Abounegm
 */
#ifndef SHADOW_DOUBLE_H
#define SHADOW_DOUBLE_H

#include <stdint.h>
#include <standard/Class.h>

typedef double shadow_double_t;

SHADOW_NOMANGLE_START
shadow_Class_t* shadowDouble_GetClass();
SHADOW_NOMANGLE_END

#endif