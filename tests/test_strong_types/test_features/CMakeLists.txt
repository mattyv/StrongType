
SET(TEST_SOURCES
    test_binary_features.cpp
)

add_library(test_features ${TEST_SOURCES})
target_link_libraries(test_features PRIVATE tests_interface)