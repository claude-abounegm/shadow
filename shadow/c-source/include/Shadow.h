#ifndef SHADOW_H
#define SHADOW_H

#ifdef __cplusplus
#define SHADOW_NOMANGLE_START extern "C" {
#define SHADOW_NOMANGLE_END }
#else
#define SHADOW_NOMANGLE_START
#define SHADOW_NOMANGLE_END
#endif

// platform specific defines
#include <_ShadowOs.h>
#include <_ShadowArch.h>

// primitives
#include <standard/Boolean.h>
#include <standard/Byte.h>
#include <standard/UByte.h>
#include <standard/Short.h>
#include <standard/UShort.h>
#include <standard/Int.h>
#include <standard/UInt.h>
#include <standard/Code.h>
#include <standard/Long.h>
#include <standard/ULong.h>
#include <standard/Float.h>
#include <standard/Double.h>

// 
#include <PrimitiveArray.h>

// standard library
#include <standard/Object.h>
#include <standard/Class.h>
#include <standard/String.h>
#include <natives/Pointer.h>

#endif