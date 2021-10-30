cmake_minimum_required(VERSION 3.15)
enable_testing()

set(this TESTS)
project(${this})

# finds all .cpp files under this directory (./test) and add them to executable
set(SOURCES Counting.cpp)

add_executable(${this} ${SOURCES})

# Link gtest libraries
target_link_libraries(${this}
        LinearHashing
        gtest
        gtest_main)


include(GoogleTest)

gtest_discover_tests(${this})

add_test(
        NAME ${this}
        COMMAND ${this}
)