/**
 * Author: Claude Abounegm
 */
#include <Shadow.h>
#include <standard/Thread.h>
#include <stddef.h>
#include <stdlib.h>

// METHOD SIGNATURES //
SHADOW_NOMANGLE_START
shadow_Pointer_t* __ShadowThread_Spawn(shadow_Thread_t*, void* (*thread_start)(void*));
SHADOW_NOMANGLE_END
// METHOD SIGNATURES //

shadow_Pointer_t* __ShadowThread_Spawn(shadow_Thread_t* instance, void* (*thread_start)(void*))
{
	return shadowPointer_Create(malloc(1), SHADOW_CAN_FREE);
}