cmake_minimum_required(VERSION 3.15)
project(DB_LinHash)

set(CMAKE_CXX_STANDARD 14)

add_executable(DB_LinHash
        main.cpp
        LinearHashing.cpp LinearHashing.hpp LinearHashingStats.cpp LinearHashingStats.hpp)
