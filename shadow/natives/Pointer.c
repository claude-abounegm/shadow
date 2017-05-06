/**
 * Author: Claude Abounegm
 */
#include <natives/Pointer.h>
#include <stdlib.h>

// METHOD SIGNATURES //
SHADOW_NOMANGLE_START
void __ShadowPointer_Free(void* ptr);
SHADOW_NOMANGLE_END
// METHOD SIGNATURES //

void __ShadowPointer_Free(void* ptr)
{
	free(ptr);
}