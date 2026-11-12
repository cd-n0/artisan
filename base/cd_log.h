#ifndef CD_LOG_H_
#define CD_LOG_H_

/* FIXME: Temporarily in log */
typedef struct cd_string_s {
    char* data;
    usize size;
} cd_string_t;

#define CD_STRING_LITERAL(cstr) ((cd_string_t){.data = cstr, .size = sizeof(cstr)})

typedef enum cd_log_level_e {
    CD_LOG_LEVEL_FATAL = 0,
    CD_LOG_LEVEL_ERROR,
    CD_LOG_LEVEL_WARNING,
    CD_LOG_LEVEL_INFO,
    CD_LOG_LEVEL_DEBUG,
    CD_LOG_LEVEL_TRACE,
    CD_LOG_LEVEL_COUNT
} cd_log_level_t;

const char* cd_log_level_colors[CD_LOG_LEVEL_COUNT] = {
    [CD_LOG_LEVEL_FATAL]    = "0;41",
    [CD_LOG_LEVEL_ERROR]    = "1:31",
    [CD_LOG_LEVEL_WARNING]  = "1;33",
    [CD_LOG_LEVEL_INFO]     = "1;32",
    [CD_LOG_LEVEL_DEBUG]    = "1;34",
    [CD_LOG_LEVEL_TRACE]    = "1:35"
};

const char* cd_log_level_prefixes[CD_LOG_LEVEL_COUNT] = {
    [CD_LOG_LEVEL_FATAL]    = "[FATAL]:  ",
    [CD_LOG_LEVEL_ERROR]    = "[ERROR]:  ",
    [CD_LOG_LEVEL_WARNING]  = "[WARNING]:",
    [CD_LOG_LEVEL_INFO]     = "[INFO]:   ",
    [CD_LOG_LEVEL_DEBUG]    = "[DEBUG]:  ",
    [CD_LOG_LEVEL_TRACE]    = "[TRACE]:  "
};

#define CD_LOGF(message) cd_logln(CD_LOG_LEVEL_FATAL, CD_STRING_LITERAL(message))
#define CD_LOGE(message) cd_logln(CD_LOG_LEVEL_ERROR, CD_STRING_LITERAL(message))
#define CD_LOGW(message) cd_logln(CD_LOG_LEVEL_WARNING, CD_STRING_LITERAL(message))
#define CD_LOGI(message) cd_logln(CD_LOG_LEVEL_INFO, CD_STRING_LITERAL(message))
#define CD_LOGD(message) cd_logln(CD_LOG_LEVEL_DEBUG, CD_STRING_LITERAL(message))
#define CD_LOGT(message) cd_logln(CD_LOG_LEVEL_TRACE, CD_STRING_LITERAL(message))

#endif /* CD_LOG_H_ */
