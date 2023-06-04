#ifndef SGE_ENGINE_H
#define SGE_ENGINE_H

#include <stdint.h>

#include "sge_graphics.h"
#include "sge_window.h"
#include "sge_input.h"

typedef struct
{
    uint8_t VERSION_MAJOR; 
    uint8_t VERSION_MINOR; 

} sge_engine_info_t;

typedef struct
{
    sge_engine_info_t info;
    sge_graphics_core_data_t* sge_graphics_core_data;
    sge_window_core_data_t* sge_window_core_data;
    sge_input_core_data_t* sge_input_core_data;

} sge_engine_t;

sge_engine_t* sge_engine_create();

void sge_engine_destroy(sge_engine_t* engine);

#endif  // SGE_ENGINE_H
