cmake_minimum_required(VERSION 3.21)

project(strong_types)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
set(CMAKE_CXX_STANDARD 20)

# Global warnings
add_compile_options(-Wall -Wextra -Wpedantic -Werror)

# Debug-only sanitizers
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-O0 -g)
endif()

add_executable(strong_types main.cpp)
add_subdirectory(tests)

target_include_directories(strong_types PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
