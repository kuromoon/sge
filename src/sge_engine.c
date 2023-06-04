#include <stdlib.h>
#include "sge_engine.h"

#define SGE_VERSION_MAJOR 0
#define SGE_VERSION_MINOR 1

sge_engine_t* sge_engine_create()
{
    sge_engine_t* engine = (sge_engine_t*) malloc(sizeof(sge_engine_t));
    
    engine->info.VERSION_MAJOR = SGE_VERSION_MAJOR;
    engine->info.VERSION_MINOR = SGE_VERSION_MINOR;



    return engine;
}

void sge_engine_destroy(sge_engine_t* engine)
{
    if(engine != NULL)
    {

        free(engine);
    }
}
