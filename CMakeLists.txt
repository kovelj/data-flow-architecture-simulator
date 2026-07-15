cmake_minimum_required(VERSION 4.00)

project(data-flow-sim)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(simulationEngine)

add_subdirectory(src)