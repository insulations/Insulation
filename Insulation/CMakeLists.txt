#Insulation Engine Core CMakelists
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${PROJECT_BINARY_DIR}/bin/Debug-x64/Insulation) # Output directory for shared lib (.DLL)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${PROJECT_BINARY_DIR}/bin/Debug-x64/Insulation) # Output directory for static lib (.LIB)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_BINARY_DIR}/bin/Debug-x64/Insulation) # Output directory for executables (.EXE)

include_directories("${PROJECT_SOURCE_DIR}/Insulation/vendor/spdlog/include")
include_directories("${PROJECT_SOURCE_DIR}/Insulation/src")
include_directories("${PROJECT_SOURCE_DIR}/Insulation/vendor/glfw-3.3.6/include")
include_directories("${PROJECT_SOURCE_DIR}/Insulation/vendor/glad/include")
include_directories("${PROJECT_SOURCE_DIR}/Insulation/vendor/imgui")
#link_directories("${PROJECT_SOURCE_DIR}/Insulation/vendor/glfw-3.3.6/build/src/Debug")

add_library(Insulation
    STATIC
    ${PROJECT_SOURCE_DIR}/Insulation/src/Insulation.h
    ${PROJECT_SOURCE_DIR}/Insulation/src/Insulation/Core/Application.h
    ${PROJECT_SOURCE_DIR}/Insulation/src/Insulation/Core/Application.cpp
    ${PROJECT_SOURCE_DIR}/Insulation/src/Insulation/Core/Core.h
    ${PROJECT_SOURCE_DIR}/Insulation/src/Insulation/Core/EntryPoint.h
    ${PROJECT_SOURCE_DIR}/Insulation/src/Insulation/Core/Log.h
    ${PROJECT_SOURCE_DIR}/Insulation/src/Insulation/Core/Log.cpp
    ${PROJECT_SOURCE_DIR}/Insulation/src/Insulation/Event/Event.h
    ${PROJECT_SOURCE_DIR}/Insulation/src/Insulation/Event/ApplicationEvent.h
    ${PROJECT_SOURCE_DIR}/Insulation/src/Insulation/Event/KeyEvent.h
    ${PROJECT_SOURCE_DIR}/Insulation/src/Insulation/Event/MouseEvent.h
    ${PROJECT_SOURCE_DIR}/Insulation/src/Ins_pch.h
    ${PROJECT_SOURCE_DIR}/Insulation/src/Ins_pch.cpp
    ${PROJECT_SOURCE_DIR}/Insulation/src/Insulation/Core/Window.h
    ${PROJECT_SOURCE_DIR}/Insulation/src/Insulation/Core/Window.cpp
    ${PROJECT_SOURCE_DIR}/Insulation/src/Platform/Windows/WindowsWindow.h
    ${PROJECT_SOURCE_DIR}/Insulation/src/Platform/Windows/WindowsWindow.cpp
    ${PROJECT_SOURCE_DIR}/Insulation/src/Insulation/Core/Layer.h
    ${PROJECT_SOURCE_DIR}/Insulation/src/Insulation/Core/Layer.cpp
    ${PROJECT_SOURCE_DIR}/Insulation/src/Insulation/Core/LayerStack.h
    ${PROJECT_SOURCE_DIR}/Insulation/src/Insulation/Core/LayerStack.cpp
    ${PROJECT_SOURCE_DIR}/Insulation/src/Insulation/ImGui/ImGuiLayer.h
    ${PROJECT_SOURCE_DIR}/Insulation/src/Insulation/ImGui/ImGuiLayer.cpp
    ${PROJECT_SOURCE_DIR}/Insulation/src/Platform/OpenGL/imgui_impl_opengl3.h
    ${PROJECT_SOURCE_DIR}/Insulation/src/Platform/OpenGL/imgui_impl_opengl3.cpp
    ${PROJECT_SOURCE_DIR}/Insulation/src/Platform/OpenGL/imgui_impl_opengl3_loader.h
    )

add_definitions(-DINS_PLATFORM_WINDOWS)
add_definitions(-DGLFW_INCLUDE_NONE)
add_definitions(-D_CRT_SECURE_NO_WARNINGS) #Shutdown SDL

#target_link_libraries(Insulation glfw3)

source_group("src/Insulation/Core" FILES 
    ${PROJECT_SOURCE_DIR}/Insulation/src/Insulation/Core/Application.h
    ${PROJECT_SOURCE_DIR}/Insulation/src/Insulation/Core/Application.cpp
    ${PROJECT_SOURCE_DIR}/Insulation/src/Insulation/Core/Core.h
    ${PROJECT_SOURCE_DIR}/Insulation/src/Insulation/Core/EntryPoint.h
    ${PROJECT_SOURCE_DIR}/Insulation/src/Insulation/Core/Log.h
    ${PROJECT_SOURCE_DIR}/Insulation/src/Insulation/Core/Log.cpp
    ${PROJECT_SOURCE_DIR}/Insulation/src/Insulation/Core/Window.h
    ${PROJECT_SOURCE_DIR}/Insulation/src/Insulation/Core/Window.cpp
    ${PROJECT_SOURCE_DIR}/Insulation/src/Insulation/Core/Layer.h
    ${PROJECT_SOURCE_DIR}/Insulation/src/Insulation/Core/Layer.cpp
    ${PROJECT_SOURCE_DIR}/Insulation/src/Insulation/Core/LayerStack.h
    ${PROJECT_SOURCE_DIR}/Insulation/src/Insulation/Core/LayerStack.cpp
)

source_group("src/Insulation/Event" FILES 
    ${PROJECT_SOURCE_DIR}/Insulation/src/Insulation/Event/Event.h
    ${PROJECT_SOURCE_DIR}/Insulation/src/Insulation/Event/ApplicationEvent.h
    ${PROJECT_SOURCE_DIR}/Insulation/src/Insulation/Event/KeyEvent.h
    ${PROJECT_SOURCE_DIR}/Insulation/src/Insulation/Event/MouseEvent.h
)

source_group("src/Insulation/Event" FILES 
    ${PROJECT_SOURCE_DIR}/Insulation/src/Insulation/ImGui/ImGuiLayer.h
    ${PROJECT_SOURCE_DIR}/Insulation/src/Insulation/ImGui/ImGuiLayer.cpp
)

source_group("src/Platform/Windows" FILES 
    ${PROJECT_SOURCE_DIR}/Insulation/src/Platform/Windows/WindowsWindow.cpp
    ${PROJECT_SOURCE_DIR}/Insulation/src/Platform/Windows/WindowsWindow.h
)

source_group("src/Platform/OpenGL" FILES
    ${PROJECT_SOURCE_DIR}/Insulation/src/Platform/OpenGL/imgui_impl_opengl3.h
    ${PROJECT_SOURCE_DIR}/Insulation/src/Platform/OpenGL/imgui_impl_opengl3.cpp
    ${PROJECT_SOURCE_DIR}/Insulation/src/Platform/OpenGL/imgui_impl_opengl3_loader.h
)

source_group("src" FILES 
    ${PROJECT_SOURCE_DIR}/Insulation/src/Insulation.h
    ${PROJECT_SOURCE_DIR}/Insulation/src/Ins_pch.h
    ${PROJECT_SOURCE_DIR}/Insulation/src/Ins_pch.cpp
)

# 设置项目属性，使用预编译头文件。需要注意的是，PCH_HEADER_FILE （Ins_pch.h）不需要路径，只传文件名即可，而PCH_SOURCE_FILE（Ins_pch.cpp）则需要传完整路径
SET_TARGET_PROPERTIES(Insulation PROPERTIES COMPILE_FLAGS 
	"/YuIns_pch.h /FIIns_pch.h")
 
# 预编译源文件（Ins_pch.cpp）设置属性，创建预编译文件
SET_SOURCE_FILES_PROPERTIES("${PROJECT_SOURCE_DIR}/Insulation/src/Ins_pch.cpp" PROPERTIES COMPILE_FLAGS
	"/YcIns_pch.h")