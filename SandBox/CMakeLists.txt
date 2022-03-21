#Sandbox CMakelists
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${PROJECT_BINARY_DIR}/bin/Debug-x64/Sandbox) # Output directory for shared lib (.DLL)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${PROJECT_BINARY_DIR}/bin/Debug-x64/Sandbox) # Output directory for static lib (.LIB)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_BINARY_DIR}/bin/Debug-x64/Sandbox) # Output directory for executables (.EXE)

include_directories("${PROJECT_SOURCE_DIR}/Insulation/src")
include_directories("${PROJECT_SOURCE_DIR}/Insulation/vendor/spdlog/include")
include_directories("${PROJECT_SOURCE_DIR}/Insulation/vendor/imgui")

link_directories("${PROJECT_BINARY_DIR}/bin/Debug-x64/Insulation")
link_directories("${PROJECT_SOURCE_DIR}/Insulation/vendor/glfw-3.3.6/build/src/Debug")
link_directories("${PROJECT_SOURCE_DIR}/Insulation/vendor/glad/bin")
link_directories("${PROJECT_SOURCE_DIR}/Insulation/vendor/imgui/bin")

add_executable(Sandbox src/SandboxApp.cpp)

target_link_libraries(Sandbox Insulation)
target_link_libraries(Sandbox glfw3)
target_link_libraries(Sandbox OpenGL32)
target_link_libraries(Sandbox glad)
target_link_libraries(Sandbox imgui)

add_definitions(-DINS_PLATFORM_WINDOWS)

source_group("src" FILES src/SandboxApp.cpp)
