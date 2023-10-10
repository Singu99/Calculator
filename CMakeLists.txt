cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

# create project
project(MyProject)

# C++ 20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)

file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)
set(INC_DIR ${CMAKE_SOURCE_DIR}/inc)

# add executable
add_library(main ${SOURCES})

target_include_directories(main PUBLIC ${INC_DIR})

# add dependencies
include(cmake/CPM.cmake)

CPMAddPackage("gh:catchorg/Catch2@3.2.1")

add_subdirectory(test)

