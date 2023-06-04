#include "sge_engine.h"
#include "logger.h"

#define GFX_LOG_WARNING(logger, format, args...) \
    LOG_WARNING(logger, "{GFX} " format, ## args)

int main(int argc, char* argv[])
{
    sge_engine_t* engine = sge_engine_create();



    logger_t logger;
    logger_t* log = &logger;

    set_log_level(log, LOG_LEVEL_ALL);
    set_file_sink(log, "test.log");

    LOG_INFO(log, "Hi there number %d", 77);
    LOG_WARNING(log, "{GRAPHICS} Hi there");
    LOG_ERROR(log, "Hi there");
    LOG_FATAL(log, "Hi there");

    GFX_LOG_WARNING(log, "This is the string %s", "mystring");

    sge_engine_destroy(engine);

    return 0;
}
