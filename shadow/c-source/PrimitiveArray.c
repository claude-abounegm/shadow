/**
 * Author: Claude Abounegm
 */
#include <Shadow.h>
#include <stdlib.h>

// PRIVATE METHOD DEFINITIONS //
SHADOW_NOMANGLE_START
shadow_ulong_t* __allocateArray(shadow_Class_t* class_, shadow_uint_t elements);
SHADOW_NOMANGLE_END
// PRIVATE METHOD DEFINITIONS //

ArrayData* shadowArray_GetData(const shadow_PrimitiveArray_t* shadowArray, ArrayData* array)
{
	if(!array) {
		array = (ArrayData*)malloc(sizeof(ArrayData));
	}
	
	array->size = shadowArray->size;
	array->data = &shadowArray->data[1];
	return array;
}

shadow_PrimitiveArray_t* shadowArray_Create(size_t num, shadow_Class_t* class_, void** data)
{
	// we first allocate memory to hold the bare bones of the array
	shadow_PrimitiveArray_t* ret = (shadow_PrimitiveArray_t*)malloc(sizeof(shadow_PrimitiveArray_t));
	
	// now we allocate the actual array
	ret->data = __allocateArray(class_, num);
	
	// set the class
	//ret->class = class;
	
	// set the size of the array
	ret->size = num;
	
	// give the user access to the first element of the array, since the first
	// item is the ulong, we jump and skip that.
	*data = &ret->data[1];
	
	return ret;
}

void shadowArray_Free(shadow_PrimitiveArray_t* array)
{
	//free(array->data);
	//free(array);
}
