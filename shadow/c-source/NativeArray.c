/**
 * Author: Claude Abounegm
 */
#include <ShadowCore.h>
#include <stdlib.h>

VoidArray* shadow_UnpackArray(shadow_NativeArray_t* shadowArray, VoidArray* array)
{
	array->size = shadowArray->size;
	array->data = &shadowArray->data[1];

	return array;
}