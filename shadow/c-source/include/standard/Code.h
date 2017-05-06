/**
 * Author: Claude Abounegm
 */
#ifndef SHADOW_CODE_H
#define SHADOW_CODE_H

#include <stdint.h>
#include <standard/Class.h>

typedef int32_t shadow_code_t;

SHADOW_NOMANGLE_START
shadow_Class_t* shadowCode_GetClass();
SHADOW_NOMANGLE_END

#endif