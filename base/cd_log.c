#include "cd_log.h"

#define CD_SYS_write 1
ssize write (i32 fd, const void* buf, usize count) {
    return syscall3(CD_SYS_write, fd, (long)buf, (long)count);
}

usize cd_cstr_strlen(const char* cstr) {
    if (!cstr) return 0;

    usize len = 0;
    while (*cstr) {
        len++;
        cstr++;
    }

    return len;
}

#define stdout 1
#define stderr 2
void cd_log_print_cstr(const char* cstr) {
    write(stdout, cstr, cd_cstr_strlen(cstr));
}

void cd_log_print_str(const cd_string_t str) {
    write(stdout, str.data, str.size);
}

static void cd_log_print_ansi_escape(void) {
    cd_log_print_cstr("\033");
}

static void cd_log_print_ansi_escape_color(const char* color) {
    cd_log_print_ansi_escape();
    cd_log_print_cstr("[");
    cd_log_print_cstr(color);
    cd_log_print_cstr("m");
}

i32 cd_log(cd_log_level_t level, cd_string_t message) {
    i32 fd = (CD_LOG_LEVEL_WARNING <= level ) ? stderr : stdout;
    cd_log_print_ansi_escape_color(cd_log_level_colors[level]);
    cd_log_print_cstr(cd_log_level_prefixes[level]);
    cd_log_print_ansi_escape_color("0");
    cd_log_print_str(message);
}

i32 cd_logln(cd_log_level_t level, cd_string_t message) {
    cd_log(level, message);
    cd_log_print_str(CD_STRING_LITERAL("\n"));
}

/* Maybe use stb_sprintf for now instead of writing the formatter without planning? */
i32 cd_logf(cd_log_level_t level, const char* message_fmt, ...) {
}
