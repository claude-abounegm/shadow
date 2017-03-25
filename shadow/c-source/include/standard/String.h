/**
 * Author: Claude Abounegm
 */
#ifndef SHADOW_STRING_H
#define SHADOW_STRING_H

#include <ShadowCore.h>

typedef struct {
	shadow_ulong_t u1;
	void* u2;
	void* u3;
	
	shadow_NativeArray_t array;
	shadow_boolean_t ascii;
} shadow_String_t;

#endif