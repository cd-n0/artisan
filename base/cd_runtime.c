/* TODO: Check if the platform supports runtime, ifdef/error it out if it doesn't */
/* TODO: arch checks */
/* TODO: naked macro */
/* TODO: put syscall logic to an appropriate file */

/*
 * From syscall(2):
 * The first table lists the instruction used to transition to kernel mode (which might not be the
 *   fastest or best way to transition to the kernel, so you might have to refer  to  vdso(7)),  the
 *   register  used  to  indicate  the system call number, the register(s) used to return the system
 *   call result, and the register used to signal an error.
 *   Arch/ABI    Instruction           System  Ret  Ret  Error    Notes
 *                                     call #  val  val2
 *   ───────────────────────────────────────────────────────────────────
 *   x86-64      syscall               eax     rax  rdx  -        5
 *   x32         syscall               eax     rax  rdx  -        5
 *   xtensa      syscall               a2      a2   -    -
 *
 * The second table shows the registers used to pass the system call arguments.
 *   Arch/ABI      arg1  arg2  arg3  arg4  arg5  arg6  arg7  Notes
 *   ──────────────────────────────────────────────────────────────
 *   x86-64        rdi   rsi   rdx   r10   r8    r9    -
 *   x32           rdi   rsi   rdx   r10   r8    r9    -
 *   xtensa        a6    a3    a4    a5    a8    a9    -
*/
/* TODO: syscall(2) has these as long, see if they're fixed length or platform dependent */
/* TODO: I never did one but think of an inline assembler macro, idk how it would work or if it's even possible since MSVC has more of an expression based inline assembler */
long syscall1(long number, long arg1) {
    long res;
    __asm__ __volatile__(
            "syscall"
            : "=a" (res)
            : "a" (number), "D" (arg1)
            : "rcx", "r11", "memory"
    );

    return res;
}

long syscall2(long number, long arg1, long arg2) {
    long res;
    __asm__ __volatile__(
        "syscall"
        : "=a" (res)
        : "a" (number), "D" (arg1), "S" (arg2)
        : "rcx", "r11", "memory"
    );

    return res;
}


long syscall3(long number, long arg1, long arg2, long arg3) {
    long res;
    __asm__ __volatile__(
        "syscall"
        : "=a" (res)
        : "a" (number), "D" (arg1), "S" (arg2), "d" (arg3)
        : "rcx", "r11", "memory"
    );

    return res;
}

#define CD_SYS_exit 60
void exit(int code) {
    syscall1(CD_SYS_exit, code);
    /* TODO: change with unreachable macro */
    for (;;) {}
}

__attribute__((naked)) void _start(void) {
    /* TODO: compiler checks */
    /* Maybe use asm and link it with that instead of inline? */
    /* https://refspecs.linuxbase.org/elf/x86_64-abi-0.99.pdf */
    __asm__ __volatile__(
            "xor %rbp, %rbp\n"      /* Set frame pointer to 0 */
            "mov (%rsp), %rdi\n"    /* argc */
            "lea 8(%rsp), %rsi\n"   /* argv */
            "and $-16, %rsp\n"      /* 16 byte align */
            "call main\n"
            "mov %rax, %rdi\n" 
            "call exit\n"
    );
}
