#ifndef CD_ASSERT_H_
#define CD_ASSERT_H_

/* Static assert (Compile time assertion) */
#if !defined(static_assert)
#   if (__STDC_VERSION__ >= 201112L) /* C11 or later */
#       define CD_STATIC_ASSERT _Static_assert
#   elif (__cplusplus >= 201103L) /* CXX11 or later */
#       define CD_STATIC_ASSERT static_assert
/* GCC 4.6 or later */
#   elif defined __GNUC__ && ( __GNUC__ > 4 || __GNUC__ == 4 && defined __GNUC_MINOR__ && __GNUC_MINOR >= 6)
#       define CD_STATIC_ASSERT _Static_assert
    /* Negative sized array hack, can do the same with a switch case
     * More info: https://en.wikichip.org/wiki/c/static_assertion */
#   else
#       define CD_STATIC_ASSERT(condition, message) extern char _static_assert_[(condition) ? 1 : -1]
#   endif
#else
#   define CD_STATIC_ASSERT static_assert
#endif

#ifndef NDEBUG
#ifndef CD_ASSERT
#include <assert.h>
/* Works as same as assert from `assert.h` */
#define CD_ASSERT(cond) assert(cond)
#endif
/* Works as same as assert from `assert.h` with a message appended at the start */
#define CD_ASSERT_MSG(msg, cond) CD_ASSERT((msg) && (cond))
/* Asssert a function return instead, keeps `function` on NDEBUG builds */
#define CD_ASSERT_FUNCTION(function) CD_ASSERT(function)
#else
#define CD_ASSERT(cond) ((void)0)
#define CD_ASSERT_FUNCTION(function) (function)
#define CD_ASSERT_MSG(msg, cond) ((void)0)
#endif

#endif /* CD_ASSERT_H_ */
