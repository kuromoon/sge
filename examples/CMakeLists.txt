project(SGE)

add_executable(example01-barebones example01-barebones.c)

target_link_libraries(example01-barebones LINK_PUBLIC sge)

