cmake_minimum_required(VERSION 3.14)

project(soloud)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -msse4.1")
add_compile_definitions(WITH_MINIAUDIO)
include_directories(include)

file(GLOB_RECURSE source_files src/*.cpp)
add_library(${PROJECT_NAME} ${source_files})