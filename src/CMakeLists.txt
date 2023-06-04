add_library(sge 
    logger.c
    sge_engine.c)

target_include_directories(sge PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
target_include_directories(sge PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../src)
