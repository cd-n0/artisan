#ifndef CD_TYPES_H_
#define CD_TYPES_H_

#include "cd_assert.h"
#include "cd_context_cracking.h"

typedef   signed          char i8;
typedef unsigned          char u8;
typedef   signed     short int i16;
typedef unsigned     short int u16;
typedef   signed           int i32;
typedef unsigned           int u32;
typedef   signed long long int i64;
typedef unsigned long long int u64;

CD_STATIC_ASSERT(sizeof( i8) == 1, "Expected i8 to be 1 bytes");
CD_STATIC_ASSERT(sizeof( u8) == 1, "Expected u8 to be 1 bytes");
CD_STATIC_ASSERT(sizeof(i16) == 2, "Expected i16 to be 2 bytes");
CD_STATIC_ASSERT(sizeof(u16) == 2, "Expected u16 to be 2 bytes");
CD_STATIC_ASSERT(sizeof(i32) == 4, "Expected i32 to be 4 bytes");
CD_STATIC_ASSERT(sizeof(u32) == 4, "Expected u32 to be 4 bytes");
CD_STATIC_ASSERT(sizeof(i64) == 8, "Expected i64 to be 8 bytes");
CD_STATIC_ASSERT(sizeof(u64) == 8, "Expected u64 to be 8 bytes");

typedef float  f32;
typedef double f64;

CD_STATIC_ASSERT(sizeof(f32) == 4, "Expected f32 to be 4 bytes");
CD_STATIC_ASSERT(sizeof(f64) == 8, "Expected f64 to be 8 bytes");

typedef u32 b32;
typedef u8  b8;

#define CD_TRUE  (1)
#define CD_FALSE (0)

#define U64_MAX (18446744073709551615ULL)
#define U32_MAX (4294967295UL)
#define U16_MAX (65535U)
#define U8_MAX  (255U)
#define U64_MIN (0U)
#define U32_MIN (0U)
#define U16_MIN (0U)
#define U8_MIN  (0U)

#define I8_MAX  (127)
#define I16_MAX (32767)
#define I32_MAX (2147483647L)
#define I64_MAX (9223372036854775807LL)
#define I8_MIN  (-128)
#define I16_MIN (-32767 - 1)
#define I32_MIN (-2147483647 - 1)
#define I64_MIN (-9223372036854775807L - 1)

#define F32_MIN (1.17549435e-38F)
#define F64_MIN (2.2250738585072014e-308)
#define F32_MAX (3.40282347e+38F)
#define F64_MAX (1.7976931348623157e+308)

#ifdef CD_BITS_64
    typedef u64 uptr;
    typedef i64 iptr;
#   define UPTR_MAX U64_MAX
#   define UPTR_MIN U64_MIN
#   define IPTR_MAX I64_MAX
#   define IPTR_MIN I64_MIN
#elif CD_BITS_32
    typedef u32 uptr;
    typedef i32 iptr;
#   define UPTR_MAX U32_MAX
#   define UPTR_MIN U32_MIN
#   define IPTR_MAX I32_MAX
#   define IPTR_MIN I32_MIN
#else
    #error "Pointer size unknown"
#endif

/* No "At least 16 bits for size_t", never understood the reasoning behind that
 * Just assign it to a DWORD or QWORD depending on architecture */
typedef uptr usize;
typedef iptr ssize;

#endif /* CD_TYPES_H_ */
