cmake_minimum_required(VERSION 3.15)
project("OOP" LANGUAGES CXX)

# guard against in-source builds
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message(FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there. You may need to remove CMakeCache.txt. ")
endif()

SET(CMAKE_BUILD_TYPE Debug)
SET(CMAKE_CXX_FLAGS_DISTRIBUTION "-O0")
SET(CMAKE_C_FLAGS_DISTRIBUTION "-O0")

set(lib lib)

add_subdirectory(src/lib)
add_subdirectory(src/main)
