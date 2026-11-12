#!/bin/sh
set -xe
CC=${CC:-clang}
CFLAGS="-march=native -mtune=native
        -std=c99 -pedantic -Wall -Wextra
        -Wunused -Wunused-macros -Wunused-local-typedefs
        -Wconversion -Wdouble-promotion -Wsign-conversion
        -Wvla -Wmissing-field-initializers -Wuninitialized -Winit-self
        -fno-builtin -ffreestanding -nostdlib
        -fno-asynchronous-unwind-tables
        -fno-math-errno -fno-trapping-math
        -lc" # For assert
SRCS="main.c"
TEST_SRCS="tests/test_main.c"
TARGET="${1:-main}"

case "$TARGET" in
main)
    $CC $CFLAGS $SRCS -o $TARGET
    ;;
test)
    $CC $CFLAGS $TEST_SRCS -o $TARGET
    ;;
*)
    echo "Unknown target: $TARGET"
    exit 1
    ;;
esac

