#Insulation Engine Main CMakeLists
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(InsulationEngine LANGUAGES CXX)
set(CMAKE_BUILD_TYPE Debug CACHE STRING "set build type to debug")

add_subdirectory(Insulation)
add_subdirectory(Sandbox)
