/**
 * Author: Claude Abounegm
 */
#include <standard/Thread.h>

#include <stddef.h>
#include <stdlib.h>
#include <pthread.h>

shadow_Pointer_t* __shadowStandardThread_Spawn(shadow_Thread_t* ref, void* (*thread_start)(void*))
{
	pthread_t* ptr = malloc(sizeof(pthread_t));
	if(pthread_create(ptr, NULL, thread_start, ref) != 0) {
		free(ptr);
		ptr = NULL;
	}
	
	return shadow_CreatePointer(ptr, SHADOW_CAN_FREE);
}