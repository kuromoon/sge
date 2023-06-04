#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include "ascii_colors.h"

typedef enum
{
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARNING,
    LOG_LEVEL_ERROR,
    LOG_LEVEL_FATAL,
    LOG_LEVEL_ALL = LOG_LEVEL_FATAL,
    LOG_LEVEL_COUNT
} log_level_t;

typedef struct
{
    FILE* file_sink;
    char file_sink_name[128];
    log_level_t log_level;
} logger_t;


void write_log(logger_t* logger, log_level_t log_level, const char* format, ...);

void set_file_sink(logger_t* logger, const char* file_sink_name);

void set_log_level(logger_t* logger, log_level_t log_level);

#define LOG_INFO(logger, format, args...)   \
        write_log(logger, LOG_LEVEL_INFO, format, ## args);

#define LOG_WARNING(logger, format, args...)   \
        write_log(logger, LOG_LEVEL_WARNING, format, ## args);

#define LOG_ERROR(logger, format, args...)   \
        write_log(logger, LOG_LEVEL_ERROR, format, ## args);

#define LOG_FATAL(logger, format, args...)   \
        write_log(logger, LOG_LEVEL_FATAL, format, ## args);

#endif  // LOGGER_H
