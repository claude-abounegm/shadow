/**
 * Author: Claude Abounegm
 */
#ifndef SHADOW_BYTE_H
#define SHADOW_BYTE_H

#include <stdint.h>
#include <standard/Class.h>

typedef int8_t shadow_byte_t;

SHADOW_NOMANGLE_START
shadow_Class_t* shadowByte_GetClass();
SHADOW_NOMANGLE_END

#endif