cmake_minimum_required(VERSION 3.15)
project(UnitTest)

set(CMAKE_CXX_STANDARD 11)

include_directories(UnitTests)
include_directories(../lib)

add_executable(UnitTest UnitTests.cpp)