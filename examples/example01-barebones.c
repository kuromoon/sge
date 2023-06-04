#include <stdio.h>

#include "sge/sge.h"

int main(int argc, char* argv[])
{
    sge_engine_t* engine = sge_engine_create();
    printf("Created SGE!\n");
    sge_engine_destroy(engine);
    printf("Destroyed SGE!\n");

    return 0;
}
