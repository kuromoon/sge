#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "logger.h"

const char* LOG_LEVEL_STRS[LOG_LEVEL_COUNT] = 
{
    "[INFO]:",
    "[WARNING]:",
    "[ERROR]:",
    "[FATAL]:"
};

const char* LOG_LEVEL_COLORS[LOG_LEVEL_COUNT] = 
{
    GREEN,
    YELLOW,
    RED,
    RED,
};

void write_log(logger_t *logger, log_level_t log_level, const char *format, ...)
{
    if(logger->log_level >= log_level)
    {
        va_list args;
        va_start(args, format);

        char buffer[512];
        sprintf(buffer, "%s%s%s %s\n",
                LOG_LEVEL_COLORS[log_level],
                LOG_LEVEL_STRS[log_level],
                NC,
                format); 

        vprintf(buffer, args);

        if(logger->file_sink != NULL)
        {
            sprintf(buffer, "%s %s\n",
                    LOG_LEVEL_STRS[log_level],
                    format); 
            va_start(args, format);
            vfprintf(logger->file_sink, buffer, args);
        }

        va_end(args);
    }
}

void set_file_sink(logger_t* logger, const char* file_sink_name)
{
    strcpy(logger->file_sink_name, file_sink_name);
    logger->file_sink = fopen(logger->file_sink_name, "w");
}


void set_log_level(logger_t* logger, log_level_t log_level)
{
    logger->log_level = log_level;
}
