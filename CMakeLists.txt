cmake_minimum_required(VERSION 3.25)
project(RpnCalculator)

set(CMAKE_CXX_STANDARD 20)

include_directories(applications/common)

add_subdirectory(applications)
add_subdirectory(tests)
