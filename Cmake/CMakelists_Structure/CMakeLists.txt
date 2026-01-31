cmake_minimum_required(VERSION 3.31)
project(structure)

file(GLOB src ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)
include_directories(${PROJECT_SOURCE_DIR}/include)

set(EXECUTABLE_OUTPUT_PATH ../bin)
# set(LIBRARY_OUTPUT_PATH ../lib)

add_executable(main ${src})
# add_library()

