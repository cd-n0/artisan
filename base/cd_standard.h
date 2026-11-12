#ifndef CD_STANDARD_H_
#define CD_STANDARD_H_

#if defined(__cplusplus)
#    if (__cplusplus >= 202302L)
#        define CD_CXX_STANDARD_23 (1)
#    elif (__cplusplus >= 202002L)
#        define CD_CXX_STANDARD_20 (1)
#    elif (__cplusplus >= 201703L)
#        define CD_CXX_STANDARD_17 (1)
#    elif (__cplusplus >= 201402L)
#        define CD_CXX_STANDARD_14 (1)
#    elif (__cplusplus >= 201103L)
#        define CD_CXX_STANDARD_11 (1)
#    elif (__cplusplus >= 199711L)
#        define CD_CXX_STANDARD_98 (1)
#        define CD_CXX_STANDARD_03 (1) /* CXX03 doesn't have a unique number */
#    endif
#elif defined(__STDC__)
#   if defined(__STDC_VERSION__)
#       if (__STDC_VERSION__ >= 202311L)
#           define CD_C_STANDARD_23 (1)
#       elif (__STDC_VERSION__ >= 201710L)
#           define CD_C_STANDARD_17 (1)
#       elif (__STDC_VERSION__ >= 201112L)
#           define CD_C_STANDARD_11 (1)
#       elif (__STDC_VERSION__ >= 199901L)
#           define CD_C_STANDARD_99 (1)
#       elif (__STDC_VERSION__ >= 199409L)
#           define CD_C_STANDARD_94 (1)
#       endif
#   else
#       define CD_C_STANDARD_89 (1)
#       define CD_C_STANDARD_90 (1)
#   endif
#elif defined(__cplusplus_cli)
#   define CXX_CLI (1)
#else
#   error "Unknown standard"
#endif

#endif /* CD_STANDARD_H_ */
