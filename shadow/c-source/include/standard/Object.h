/**
 * Author: Claude Abounegm
 */
#ifndef SHADOW_OBJECT_H
#define SHADOW_OBJECT_H

#include <standard/String.h>
#include <standard/Class.h>

typedef void* shadow_Object_t;

SHADOW_NOMANGLE_START
shadow_String_t* shadowObject_ToString(shadow_Object_t* ref);
shadow_Class_t* shadowObject_GetClass(shadow_Object_t* ref);
SHADOW_NOMANGLE_END

#endif