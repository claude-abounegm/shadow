; Shared.ll
; 
; A set of functions which are of help to native C code. This facilitates
; writing C code which communicates with Shadow and LLVM.
;
; Author:
;   Claude Abounegm

;-------------
; Definitions
;-------------
; Primitives
%boolean = type i1
%byte = type i8
%ubyte = type i8
%short = type i16
%ushort = type i16
%int = type i32
%uint = type i32
%code = type i32
%long = type i64
%ulong = type i64
%float = type float
%double = type double
%void = type i8

; Class
%shadow.standard..Class = type opaque

; Pointer
%shadow.natives..Pointer = type opaque

;---------------------------
; Custom Method Definitions
;---------------------------
; Pointer.h
declare %shadow.natives..Pointer* @shadow.natives..Pointer_McreateNative_long_boolean(%shadow.natives..Pointer*, %long, %boolean)
declare %long @shadow.natives..Pointer_MgetAddressNative(%shadow.natives..Pointer*)

define %shadow.natives..Pointer* @_shadow_CreatePointer(%void*, %boolean) {
entry:
	%address = ptrtoint %void* %0 to %long
	%call = call %shadow.natives..Pointer* @shadow.natives..Pointer_McreateNative_long_boolean(%shadow.natives..Pointer* null, %long %address, %boolean %1)
	ret %shadow.natives..Pointer* %call
}

define %void* @_shadow_ExtractPointer(%shadow.natives..Pointer*) {
entry:
	%address = call %long @shadow.natives..Pointer_MgetAddressNative(%shadow.natives..Pointer* %0)
	%pointer = inttoptr %long %address to %void*
	ret %void* %pointer
}