cmake_minimum_required(VERSION 3.15)
enable_testing()

set(this TESTS)
project(${this})

# finds all .cpp files under this directory (./test) and add them to executable
set(SOURCES Counting.cpp)

add_executable(${this} ${SOURCES})

include(GoogleTest)

# Link gtest libraries
target_link_libraries(${PROJECT_NAME}
        LinearHashing
        gtest
        gtest_main)



gtest_discover_tests(${this})