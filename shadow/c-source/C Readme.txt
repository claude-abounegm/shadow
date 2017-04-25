All the stuff below are included with this include:
  #include <ShadowCore.h>

-----------------------------------------------------------------------------------
Usage:
  #ifdef SHADOW_*

=================
=   Platforms   =
=================
  SHADOW_WINDOWS
  SHADOW_MAC
  SHADOW_LINUX

=================
= Architectures =
=================
  SHADOW_ARCH32
  SHADOW_ARCH64
-----------------------------------------------------------------------------------
===================
= Primitive types =
===================
  shadow_boolean_t

  shadow_byte_t
  shadow_ubyte_t

  shadow_short_t
  shadow_ushort_t

  shadow_int_t
  shadow_uint_t
  shadow_code_t

  shadow_long_t
  shadow_ulong_t

  shadow_float_t
  shadow_double_t
-----------------------------------------------------------------------------------
====================
=  Primitive Array =
====================
  // NOTE: This is a pointer to a Shadow Primitive Array T[] and IS NOT an Array<T> object.
  type: shadow_PrimitiveArray_t
  ---

  ArrayData* shadowArray_GetData(const shadow_PrimitiveArray_t* shadowArray, ArrayData* array);

  shadow_PrimitiveArray_t* shadowArray_Create(size_t num, size_t size, void** data);
  void shadowArray_Free(shadow_PrimitiveArray_t* array);
-----------------------------------------------------------------------------------
==========
= Object =
==========
  #include <standard/Object.h> // optional
  type: shadow_Object_t*
  ---

  // Note: any reference type can be passed to this method. 
  //       for example, passing a reference of type `shadow_File_t*` will return 
  //       a Shadow String containing the path of the file. This is 
  //       equivalent to ref.toString() but in C.
  shadow_String_t* shadowObject_ToString(shadow_Object_t* ref);
-----------------------------------------------------------------------------------
==========
= String =
==========
  #include <standard/String.h> // optional
  type: shadow_String_t*
  ---
  
  typedef struct { 
    shadow_int_t size;
    shadow_byte_t* chars;
    shadow_boolean_t ascii;
  } StringData;

  StringData* shadowString_GetData(const shadow_String_t* instance, StringData* str);
  char* shadowString_GetCString(const shadow_String_t* instance);

  // Create and Free are still experimental.
  shadow_String_t* shadowString_Create(const char*);
  void shadowString_Free(shadow_String_t*);
-----------------------------------------------------------------------------------
===========
= Pointer =
===========
  #include <natives/Pointer.h> // optional
  type: shadow_Pointer_t*
  ---

  shadow_Pointer_t* shadowPointer_Create(void* ptr, free_type_t type);

  // T: Type of the extracted pointer
  T* shadowPointer_Extract(T, shadow_Pointer_t*);
-----------------------------------------------------------------------------------
===========
= Console =
===========
  #include <io/Console.h>
  type: shadow_Console_t*
  ---

  void shadowConsole_PrintLine(shadow_String_t*);
  void shadowConsole_PrintErrorLine(shadow_String_t*);
-----------------------------------------------------------------------------------
-----------------------------------------------------------------------------------
-----------------------------------------------------------------------------------



======================
= On the Shadow side =
======================

  // no name mangling
  // no "this" as first argument
  private extern _Test(int x) => (boolean);
    -- generates --
  declare %boolean @_Test(%int)


  // no name mangling
  // "this" argument is passed as any normal function
  // function body generated like any normal function
  private extern _Test(int x) => (boolean) {
	...
  }
    -- generates --
  define %boolean @_Test(%shadow.test..Test*, %int) {
    ...
  }

  // name mangling
  // acts a normal function
  // Allows only Class1 and Class2 to import the function
  private [Class1, Class2] $Test() => () {
	...
  }
  * in Class1 and Class2: *
  private extern $Test(OtherClass instance) => ();