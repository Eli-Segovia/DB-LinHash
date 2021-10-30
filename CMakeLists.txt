cmake_minimum_required(VERSION 3.15)

project(LinHash C CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)
add_subdirectory(lib/LinearHashing)

file(GLOB TESTING_SOURCES
        "test/*.cpp"
        )

add_executable(${PROJECT_NAME} src/main.cpp ${TESTING_SOURCES})

target_link_libraries(${PROJECT_NAME}
        LinearHashing
        gtest_main)




