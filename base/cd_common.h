#ifndef CD_COMMON_H_
#define CD_COMMON_H_

#include "cd_context_cracking.h"

#ifndef   NULL
#define   NULL ((void *)0)
#endif

#define   CD_NULL ((void *)0)

#define CD_UNUSED(var) ((void)var)

#define CD_CONCAT(a, b) a##b
#define CD_CONCAT_MACRO(a, b) CD_CONCAT(a, b)
#define CD_SIZEOF_MEMBER(type, member) (sizeof(((type*)0)->member))

/* These 2 will not work on pointers */
#define CD_ARRAY_LENGTH(s) (sizeof((s)) / sizeof((s)[0]))
#define CD_CSTRING_LENGTH(s) ((sizeof((s)) / sizeof((s)[0])) - sizeof((s)[0]))

/* Credits to Colleague Riley:
 * https://github.com/ColleagueRiley/RGFW/blob/9de5bcbb958e6830932a3facf041482d90f1be31/examples/gl33/gl33.c#L17 */
/* NOTE: When multiline strings pound character shouldn't directly get used otherwise the preprocessor will complain
 * \x23 can be used instead of the actual char (ascii # == 0x23) */
#if (__STDC_VERSION__ >= 199901L) /* C99 Feature */
    #define CD_MULTILINE_STR(...) #__VA_ARGS__
#endif

/* Credits to TomasBorquez/base.h */
#if defined(CD_PLATFORM_WINDOWS)
/* Process functions */
#  define popen _popen
#  define pclose _pclose

/* File I/O functions */
#  define fileno _fileno
#  define fdopen _fdopen
#  define access _access
#  define unlink _unlink
#  define isatty _isatty
#  define dup _dup
#  define dup2 _dup2
#  define ftruncate _chsize
#  define fsync _commit

/* Directory functions */
#  define mkdir(path, mode) _mkdir(path)
#  define rmdir _rmdir
#  define getcwd _getcwd
#  define chdir _chdir

/* Process/Threading */
#  define getpid _getpid
#  define sleep(x) Sleep((x) * 1000)
#  define usleep(x) Sleep((x) / 1000)

/* String functions */
#  define strcasecmp _stricmp
#  define strncasecmp _strnicmp
#  define strdup _strdup

/* File modes */
#  define R_OK 4
#  define W_OK 2
#  define X_OK 0 /* Windows doesn't have explicit X_OK */
#  define F_OK 0

/* File descriptors */
#  define STDIN_FILENO 0
#  define STDOUT_FILENO 1
#  define STDERR_FILENO 2

/* Some functions need complete replacements */
#  if defined(COMPILER_MSVC)
#    define snprintf _snprintf
#    define vsnprintf _vsnprintf
#  endif
#endif

/* Swap */
#define CD_SWAP(type, a, b) \
  do {              \
    type tmp = a;   \
    a = b;          \
    b = tmp;        \
  } while (0);
#define CD_XORSWAP(a, b)    \
  do {              \
    a ^= b;         \
    b ^= a;         \
    a ^= b;         \
  } while (0);

#define CD_DEFER_LOOP(statement, defer)                                 \
    for(int CD_CONCAT_MACRO(__defer_i__, __LINE__) = ((statement), 0);  \
            !CD_CONCAT_MACRO(__defer_i__, __LINE__);                    \
            CD_CONCAT_MACRO(__defer_i__, __LINE__) += 1, (defer))
#define CD_DEFER_LOOP_CHECKED(statement, defer)                     \
    for (int CD_CONCAT_MACRO(__defer_i__, __LINE__) = (statement);  \
         CD_CONCAT_MACRO(__defer_i__, __LINE__);                    \
         CD_CONCAT_MACRO(__defer_i__, __LINE__) = 0, (defer))


/* Size macros */
#define CD_EXBIBYTES(amount) ((amount) * 1024ULL * 1024ULL * 1024ULL * 1024ULL * 1024ULL * 1024ULL)
#define CD_PEBIBYTES(amount) ((amount) * 1024ULL * 1024ULL * 1024ULL * 1024ULL * 1024ULL)
#define CD_TEBIBYTES(amount) ((amount) * 1024ULL * 1024ULL * 1024ULL * 1024ULL)
#define CD_GIBIBYTES(amount) ((amount) * 1024ULL * 1024ULL * 1024ULL)
#define CD_MEBIBYTES(amount) ((amount) * 1024ULL * 1024ULL)
#define CD_KIBIBYTES(amount) ((amount) * 1024ULL)

#define CD_EXABYTES(amount)  ((amount)  * 1000ULL * 1000ULL * 1000ULL * 1000ULL * 1000ULL * 1000ULL)
#define CD_PETABYTES(amount) ((amount) * 1000ULL * 1000ULL * 1000ULL * 1000ULL * 1000ULL)
#define CD_TERABYTES(amount) ((amount) * 1000ULL * 1000ULL * 1000ULL * 1000ULL)
#define CD_GIGABYTES(amount) ((amount) * 1000ULL * 1000ULL * 1000ULL)
#define CD_MEGABYTES(amount) ((amount) * 1000ULL * 1000ULL)
#define CD_KILOBYTES(amount) ((amount) * 1000ULL)

/* Bit operations */
#define CD_BIT_GET(value, bit)      ((value >> bit) & 1U)
#define CD_BIT_SET(value, bit)      (value |= (1U << bit))
#define CD_BIT_RESET(value, bit)    (value &= ~(1U << bit))
#define CD_BIT_TOGGLE(value, bit)   (value ^= (1U << bit))

/* Memory offset */
#define CD_OFFSET(base, offset) ((void*)((uptr)(base) + (uptr)(offset)))
/* Memory alignment, assume alignment is a power of 2 */
#define CD_ALIGN_DOWN(value, alignment) ((uptr)(value) & ~((alignment) - 1))
#define CD_ALIGN_UP(value, alignment)   CD_ALIGN_DOWN((value) + (alignment) - 1, (alignment))

#endif /* CD_COMMON_H_ */
