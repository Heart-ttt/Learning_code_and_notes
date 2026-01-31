cmake_minimum_required(VERSION 3.31)
project(create_library)

file(GLOB src ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)
include_directories(${PROJECT_SOURCE_DIR}/include)

set(LIBRARY_OUTPUT_PATH ../lib)
# set(EXECUTABLE_OUTPUT_PATH ../bin)对动态库可用

# add_executable(main ${src})
# add_library(demo2 SHARED ${src})
add_library(demo22 STATIC ${src})