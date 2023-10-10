cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

#See source files 
message( STATUS "Sources: " ${SOURCES} )

add_executable(regular_ops regular_ops.cpp ${SOURCES})
add_executable(nested_ops nested_ops.cpp ${SOURCES})

target_include_directories(regular_ops PRIVATE ${INC_DIR})
target_include_directories(nested_ops PRIVATE ${INC_DIR})

# link dependencies
target_link_libraries(regular_ops Catch2::Catch2WithMain main)

target_link_libraries(nested_ops Catch2::Catch2WithMain main)


# add tests
add_test(NAME regular_ops COMMAND regular_ops)
add_test(NAME nested_ops COMMAND nested_ops)