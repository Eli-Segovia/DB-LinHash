cmake_minimum_required(VERSION 3.15)

set (This Tests)

set(Sources LinearHashTests.cpp)


add_executable(${This} ${Sources})

target_link_libraries(${This}
        LinearHashing
        gtest
        gtest_main)

include(GoogleTest)
gtest_discover_tests(${This})

add_test(
        NAME ${This}
        COMMAND ${This}
)