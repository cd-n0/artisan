#ifndef CD_CONTEXT_CRACKING_H_
#define CD_CONTEXT_CRACKING_H_

/* Platform Definitions */
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
#   define CD_PLATFORM_WINDOWS (1)
#endif

#if defined(__OpenBSD__)
#   define CD_PLATFORM_OPENBSD (1)
#endif

#if defined(__EMSCRIPTEN__)
#   define CD_PLATFORM_EMSCRIPTEN (1)
#endif

/* __linux__ can also be android */
#if defined(__gnu_linux__) || defined(__linux__)
#   define CD_PLATFORM_LINUX (1)
#endif

/* https://webassembly.org/docs/portability/ always little endian */
#if defined(__wasm32__)
#   define CD_PLATFORM_WASM32 (1)
#   define CD_BITS_32 (1)
#   define CD_BITS (32)
#   define CD_BYTE_ORDER ('L')
#   define CD_LITTLE_ENDIAN (1)
#elif defined(__wasm64__)
#   define CD_PLATFORM_WASM64 (1)
#   define CD_BITS_64 (1)
#   define CD_BITS (64)
#   define CD_BYTE_ORDER ('L')
#   define CD_LITTLE_ENDIAN (1)
#endif

#if defined(__ANDROID__)
#   define CD_PLATFORM_ANDROID (1)
#endif

#if defined(ESP_PLATFORM)
#   define CD_PLATFORM_ESP (1)
#endif

#if defined(__AVR__)
#   define CD_PLATFORM_AVR (1)
#endif

#if defined(__x86_64__) || defined(_M_X64) || defined(__amd64__) || defined(__amd64)
#   define CD_ARCHITECTURE_X86_64 (1)
#   define CD_ARCHITECTURE_AMD64 (1)
#   define CD_BITS_64 (1)
#   define CD_BITS (64)
#   define CD_BYTE_ORDER ('L')
#   define CD_LITTLE_ENDIAN (1)
#elif defined(__i386) || defined(_M_IX86)
#   define CD_ARCHITECTURE_X86 (1)
#   define CD_BITS_32 (1)
#   define CD_BITS (32)
#   define CD_BYTE_ORDER ('L')
#   define CD_LITTLE_ENDIAN (1)
#endif

/* Endianness */
#ifndef CD_BYTE_ORDER
#   if defined(CD_BIG_ENDIAN)
#       define CD_BYTE_ORDER ('B')
#   elif defined(CD_LITTLE_ENDIAN)
#       define CD_BYTE_ORDER ('L')
#   elif defined(__BYTE_ORDER__) && defined(__ORDER_LITTLE_ENDIAN__) && defined(__ORDER_BIG_ENDIAN__)
#       if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#           define CD_BYTE_ORDER ('L')
#       elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#           define CD_BYTE_ORDER ('B')
#       else
#           error "Unknown byte order"
#       endif
#   else
#       error "Endianness detection must be set up for your compiler/arch"
#   endif
#endif

/* Previous platform definitions, don't need all of this */
#if 0
#ifndef CD_PLATFORMDEF_H_
#define CD_PLATFORMDEF_H_

/* Platform Definitions */
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
#   define CD_PLATFORM_WINDOWS (1)
#endif

#if defined(__EMSCRIPTEN__)
#   define CD_PLATFORM_EMSCRIPTEN (1)
#endif

/* __linux__ can also be android */
#if defined(__gnu_linux__) || defined(__linux__)
#   define CD_PLATFORM_LINUX (1)
#endif

#if defined(__ANDROID__)
#   define CD_PLATFORM_ANDROID (1)
#endif

#if defined(__bsdi__)
#   define CD_PLATFORM_BSD (1)
#endif

#if defined(__FreeBSD__)
#   define CD_PLATFORM_FREEBSD (1)
#endif

#if defined(__NetBSD__)
#   define CD_PLATFORM_NETBSD (1)
#endif

#if defined(__OpenBSD__)
#   define CD_PLATFORM_OPENBSD (1)
#endif

#if defined(__DragonFly__)
#   define CD_PLATFORM_DRAGONFLY (1)
#endif


#if defined(__APPLE__)
/* Apple */
#   define CD_PLATFORM_APPLE (1)
#   include <TargetConditionals.h>
#   if TARGET_IPHONE_SIMULATOR
/* IOS Simulator */
#       define CD_PLATFORM_IOS (1)
#       define CD_PLATFORM_IOS_SIMULATOR (1)
#   elif TARGET_OS_IPHONE
#       define CD_PLATFORM_IOS (1)
/* IOS device */
#   elif TARGET_OS_MAC
#       define CD_PLATFORM_MAC (1)
#   else
#   error "Unknown Apple platform"
#   endif
#endif

#if !defined(CD_PLATFORM) && (defined(__unix__) || defined(__unix))
#   define CD_PLATFORM_UNIX (1)
#endif

#if defined(__x86_64__) || defined(_M_X64) || defined(__amd64__) || defined(__amd64)
#   define CD_ARCHITECTURE_X86_64 (1)
#   define CD_ARCHITECTURE_AMD64 (1)
#   define CD_BYTE_ORDER ('L')
#   define CD_LITTLE_ENDIAN (1)
#   define CD_BITS_64 (1)
#   define CD_BITS (64)
#elif defined(__i386) || defined(_M_IX86)
#   define CD_ARCHITECTURE_X86 (1)
#   define CD_BYTE_ORDER ('L')
#   define CD_LITTLE_ENDIAN (1)
#   define CD_BITS_32 (1)
#   define CD_BITS (32)
#endif

#if defined(__ia64) || defined(__itanium__) || defined(_M_IA64)
#   define CD_ARCHITECTURE_ITANIUM (1)
#   define CD_BITS_64 (1)
#   define CD_BITS (64)
#endif

#if defined(__arm) || defined(__arm__) || defined(_M_ARM)
#   if defined(__aarch64__)
#       define CD_ARCHITECTURE_ARM64 (1)
#       define CD_BITS_64 (1)
#       define CD_BITS (64)
#   else
#       define CD_ARCHITECTURE_ARM32 (1)
#       define CD_BITS_32 (1)
#       define CD_BITS (32)
#   endif
#endif

#if defined(__mips__) || defined(__mips) || defined(__MIPS__)
#   define CD_ARCHITECTURE_MIPS (1)
#   if defined(__MIPSEB__)
#       define CD_BYTE_ORDER ('B')
#       define CD_BIG_ENDIAN (1)
#   elif defined(__MIPSEL__)
#       define CD_BYTE_ORDER ('L')
#       define CD_LITTLE_ENDIAN (1)
#   endif
#endif

#if defined(__powerpc__) || defined(__powerpc) || defined(__ppc__) || defined(__ppc) || defined(_M_PPC) || defined(__PPC__)
#   define CD_ARCHITECTURE_PPC (1)
#   if defined(__BIG_ENDIAN__) || defined(__PPCBIG_ENDIAN__)
#       define CD_BYTE_ORDER ('B')
#       define CD_BIG_ENDIAN (1)
#   elif defined(__LITTLE_ENDIAN__) || defined(__PPCLE__)
#       define CD_BYTE_ORDER ('L')
#       define CD_LITTLE_ENDIAN (1)
#   endif
#endif

#if defined(ESP_PLATFORM)
#   define CD_PLATFORM_ESP (1)
#endif

#if defined(__AVR__)
#   define CD_PLATFORM_AVR (1)
#endif

/* Fallbacks */

/* Idk if this is always true but seems fine */
#ifndef CD_BITS
#	if defined(__SIZEOF_POINTER__) && __SIZEOF_POINTER__ == 8
#	   ifndef CD_BITS_64
#	       define CD_BITS_64 (1)
#	       define CD_BITS (64)
#	   endif
#	elif defined(__SIZEOF_POINTER__) && __SIZEOF_POINTER__ == 4
#	   ifndef CD_BITS_32
#	       define CD_BITS_32 (1)
#	       define CD_BITS (32)
#	   endif
#	else
#	   error "Pointer size unknown"
#	endif
#endif

/* Endianness */
#ifndef CD_BYTE_ORDER
#   if defined(CD_BIG_ENDIAN)
#       define CD_BYTE_ORDER ('B')
#   elif defined(CD_LITTLE_ENDIAN)
#       define CD_BYTE_ORDER ('L')
#   elif defined(__BYTE_ORDER__) && defined(__ORDER_LITTLE_ENDIAN__) && defined(__ORDER_BIG_ENDIAN__)
#       if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#           define CD_BYTE_ORDER ('L')
#       elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#           define CD_BYTE_ORDER ('B')
#       else
#           error "Unknown byte order"
#       endif
#   else
#       error "Endianness detection must be set up for your compiler/arch"
#   endif
#endif

#endif /* CD_PLATFORMDEF_H_ */

#endif

#endif /* CD_CONTEXT_CRACKING_H_ */
