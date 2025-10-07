cmake_minimum_required(VERSION 3.21)

project(strong_types)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

add_executable(strong_types main.cpp )
target_include_directories(strong_types PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features(strong_types PUBLIC cxx_std_20)

