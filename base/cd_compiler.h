#ifndef CD_COMPILER_H_
#define CD_COMPILER_H_

#include "cd_standard.h"

/* Compiler macros */
#if defined(__clang__)
#  define CD_COMPILER_CLANG (1)
#elif defined(__GNUC__)
#  define CD_COMPILER_GCC (1)
#elif defined(__TINYC__)
#  define CD_COMPILER_TCC (1)
#elif defined(_MSC_VER)
#  define CD_COMPILER_MSVC (1)
#endif

#if defined(CD_COMPILER_GCC) || defined(CD_COMPILER_CLANG)
#   define CD_NORETURN __attribute__((noreturn))
#   define CD_UNLIKELY(x) __builtin_expect(!!(x), 0)
#   define CD_ALLOC_ATTR2(sz, al) __attribute__((malloc, alloc_size(sz), alloc_align(al)))
#   define CD_ALLOC_ATTR(sz) __attribute__((malloc, alloc_size(sz)))
#   define CD_FORMAT_CHECK(fmt_pos, args_pos) __attribute__((format(printf, fmt_pos, args_pos)))
#   define CD_WARN_UNUSED __attribute__((warn_unused_result))
#   define CD_INLINE __attribute__((always_inline)) inline
#   define CD_NOINLINE __attribute__((noinline))
#   define CD_NAKED __attribute__((naked))
#   define CD_THREAD_LOCAL __thread
#   define CD_MEMORY_FENCE() __asm__ __volatile__("" ::: "memory")
#   if defined(CD_ARCHITECTURE_X86_64) || defined(CD_ARCHITECTURE_X86)
#       define CD_BREAKPOINT() __asm__ __volatile__("int3; nop")
#   elif defined(CD_ARCHITECTURE_ARM64)
#       define CD_BREAKPOINT() __asm__ __volatile__(".inst 0xd4200000")
#   elif defined(CD_ARCHITECTURE_ARM32)
#       define CD_BREAKPOINT() __asm__ __volatile__(".inst 0xe7f001f0")
#   elif defined(CD_ARCHITECTURE_PPC)
#       define CD_BREAKPOINT() __asm__ __volatile__("trap")
#   elif defined(CD_ARCHITECTURE_MIPS)
#       define CD_BREAKPOINT() __asm__ __volatile__("break")
#   else
#	    define CD_BREAKPOINT()  ((void)0)
#	endif

#elif defined(CD_COMPILER_MSVC)
#   define CD_NORETURN __declspec(noreturn)
#   define CD_UNLIKELY(x) x
#   define CD_ALLOC_ATTR2(sz, al)
#   define CD_ALLOC_ATTR(sz)
#   define CD_FORMAT_CHECK(fmt_pos, args_pos)
#   define CD_WARN_UNUSED _Check_return_
#   define CD_INLINE __forceinline
#   define CD_NOINLINE __declspec(noinline)
#   define CD_NAKED __declspec(naked)
#   define CD_BREAKPOINT() __debugbreak()
#   define CD_THREAD_LOCAL __declspec(thread)
#   include <intrin.h>
#   define CD_MEMORY_FENCE() _ReadWriteBarrier()
#else
/* TODO: instead of erroring out the compiler error when it gets used in the project, couldn't find a way to do it lol */
#   define CD_NORETURN
#   define CD_UNLIKELY(x) x
#   define CD_ALLOC_ATTR2(sz, al)
#   define CD_ALLOC_ATTR(sz)
#   define CD_FORMAT_CHECK(fmt_pos, args_pos)
#   define CD_WARN_UNUSED
#   define CD_INLINE static inline
#   define CD_NOINLINE
#   define CD_BREAKPOINT() ((void)0)
#   ifndef CD_MEMORY_FENCE
#       error "no memory fence known for this compiler"
#   endif
#   if CD_C_STANDARD_11  && !defined(__STDC_NO_THREADS__)
#       define CD_THREAD_LOCAL _Thread_local
#   else
#       ifndef CD_THREAD_LOCAL
#           error "no thread local storage keyword known for this compiler"
#       endif
#   endif
#endif

#ifdef NDEBUG
#   undef CD_BREAKPOINT
#   define CD_BREAKPOINT() ((void)0)
#endif

/* TODO: restrict */

/* Library import/export */
#ifdef CD_EXPORT
#    ifdef CD_COMPILER_MSVC
#        define CD_API __declspec(dllexport)
#    elif defined(CD_COMPILER_GCC) || defined(CD_COMPILER_CLANG)
#        define CD_API __attribute__((visibility("default")))
#    else
#        define CD_API
#    endif
#else
#    ifdef CD_COMPILER_MSVC
#        define CD_API __declspec(dllimport)
#    else
#        define CD_API
#    endif
#endif

#endif /* CD_COMPILER_H_ */
