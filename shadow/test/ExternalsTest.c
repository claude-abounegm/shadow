/**
 * Author: Claude Abounegm
 */
#include <Shadow.h>
#include <io/Console.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

typedef void* shadow_ExternalsTest_t;

SHADOW_NOMANGLE_START
void __shadowExternalTest_PrintfToString(shadow_ExternalsTest_t* ref);
void __shadowExternalTest_CreateString();
shadow_Pointer_t* __shadowExternalTest_InitPointer(int number);
void __shadowExternalTest_PrintPointerData(shadow_ExternalsTest_t* instance, shadow_Pointer_t* ptr);

void _shadowExternalsTest_PrintNumberWithOffset(shadow_ExternalsTest_t* instance, int number);
void __shadowExternalTest_PrintClasses(shadow_ExternalsTest_t* instance);
//void __shadowExternalTest_ThrowException(shadow_Object_t* e);
SHADOW_NOMANGLE_END

/*void __shadowExternalTest_ThrowException(shadow_Object_t* e)
{
	throw e;
}*/

void __shadowExternalTest_PrintfToString(shadow_ExternalsTest_t* ref)
{
	// equivalent to ref.toString()
	shadow_String_t* str = shadowObject_ToString(ref);
	
	// get the C string from the Shadow String object
	char* cStr = shadowString_GetCString(str);
	
	// print the C null terminated string
	printf("%s\n", cStr);
	
	// since the Shadow Console and printf do not use the 
	// same system calls for the console, we flush the output
	// for consistency.
	fflush(stdout);
	
	// the shadowString_GetCString() allocates memory,
	// so we free it.
	free(cStr);
}

void __shadowExternalTest_CreateString()
{
	// Create a Shadow string from a C string
	shadow_String_t* string = shadowString_Create("This is a string created in C and printed using Shadow's Console.printLine()");

	// this method is equivalent to Console.printLine(Object)
	shadowConsole_PrintLine(string);
	
	// free the String we created
	shadowString_Free(string);
}


typedef struct {
	int number;
} TestData;

shadow_Pointer_t* __shadowExternalTest_InitPointer(int number)
{
	TestData* data = (TestData*)malloc(sizeof(TestData));
	data->number = number;
	
	return shadowPointer_Create(data, SHADOW_CAN_FREE);
}

void __shadowExternalTest_PrintPointerData(shadow_ExternalsTest_t* instance, shadow_Pointer_t* ptr)
{
	// retrieve the original pointer we allocated earlier
	TestData* data = shadowPointer_Extract(TestData, ptr);
	
	// print the number that we set earlier
	printf("%d\n", data->number);
	fflush(stdout);
	
	// pass the number to Shadow to print it with an offset
	_shadowExternalsTest_PrintNumberWithOffset(instance, data->number);
}

void __shadowExternalTest_PrintClasses(shadow_ExternalsTest_t* instance)
{
	// object class
	shadowConsole_PrintLine(shadowObject_GetClass(instance));
	
	// primitives
	shadowConsole_PrintLine(shadowBoolean_GetClass());
	shadowConsole_PrintLine(shadowByte_GetClass());
	shadowConsole_PrintLine(shadowUByte_GetClass());
	shadowConsole_PrintLine(shadowShort_GetClass());
	shadowConsole_PrintLine(shadowUShort_GetClass());
	shadowConsole_PrintLine(shadowInt_GetClass());
	shadowConsole_PrintLine(shadowUInt_GetClass());
	shadowConsole_PrintLine(shadowCode_GetClass());
	shadowConsole_PrintLine(shadowLong_GetClass());
	shadowConsole_PrintLine(shadowULong_GetClass());
	shadowConsole_PrintLine(shadowFloat_GetClass());
	shadowConsole_PrintLine(shadowDouble_GetClass());
}