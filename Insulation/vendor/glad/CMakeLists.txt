#Sandbox CMakelists
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(glad)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/bin) # Output directory for shared lib (.DLL)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/bin) # Output directory for static lib (.LIB)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/bin) # Output directory for executables (.EXE)

include_directories("${PROJECT_SOURCE_DIR}/src")
include_directories("${PROJECT_SOURCE_DIR}/include")

add_library(glad
    STATIC
    ${PROJECT_SOURCE_DIR}/src/glad.c
    ${PROJECT_SOURCE_DIR}/include/glad/glad.h
    ${PROJECT_SOURCE_DIR}/include/KHR/khrplatform.h
)
#E:\Insulation\Insulation\vendor\cmake\bin\cmake.exe -H. -Bbuild
