#imgui CMakelists
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(imgui_build LANGUAGES CXX)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/bin) # Output directory for shared lib (.DLL)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/bin) # Output directory for static lib (.LIB)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/bin) # Output directory for executables (.EXE)


add_library(imgui
    STATIC
    ${PROJECT_SOURCE_DIR}/imconfig.h
    ${PROJECT_SOURCE_DIR}/imgui.h
    ${PROJECT_SOURCE_DIR}/imgui.cpp
    ${PROJECT_SOURCE_DIR}/imgui_demo.cpp
    ${PROJECT_SOURCE_DIR}/imgui_draw.cpp
    ${PROJECT_SOURCE_DIR}/imgui_internal.h
    ${PROJECT_SOURCE_DIR}/imgui_tables.cpp
    ${PROJECT_SOURCE_DIR}/imgui_widgets.cpp
    ${PROJECT_SOURCE_DIR}/imstb_rectpack.h
    ${PROJECT_SOURCE_DIR}/imstb_textedit.h
    ${PROJECT_SOURCE_DIR}/imstb_truetype.h
    )
#E:\Insulation\Insulation\vendor\cmake\bin\cmake.exe -DCMAKE_SYSTEM_VERSION=10.0.19041.0 -H. -Bbuild 
