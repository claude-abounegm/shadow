/**
 * Author: Claude Abounegm
 */
#include <ShadowCore.h>
#include <stdlib.h>

char* shadow_UnpackStringToCStr(shadow_String_t* shadowString)
{
	ShadowStringData str;
	shadow_UnpackString(shadowString, &str);
	
	char* dest = malloc(str.size + 1);
	int i;
	for(i = 0; i < str.size; ++i) {
		dest[i] = str.chars[i];
	}
	dest[i] = '\0';
	
	return dest;
}

ShadowStringData* shadow_UnpackString(shadow_String_t* shadowString, ShadowStringData* str)
{
	shadow_UnpackArray(&shadowString->array, (VoidArray*)str);
	str->ascii = shadowString->ascii;

	return str;
}