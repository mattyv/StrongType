# Currently only builds in DEBUG for clang19 and gcc13 (asserts do not get compiled out)

add_library(tests_interface INTERFACE)

target_include_directories(tests_interface INTERFACE
    ${CMAKE_SOURCE_DIR}/include        # main project headers
    ${CMAKE_SOURCE_DIR}/tests       # tests/ headers
)

add_subdirectory(test_strong_types)

set(TEST_TARGETS
    test_features
)

add_executable(test_all test_main.cpp)
target_link_libraries(test_all PUBLIC ${TEST_TARGETS})
