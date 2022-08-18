add_subdirectory(glew-cmake)
target_compile_options(libglew_shared PRIVATE "-w")
target_compile_options(libglew_static PRIVATE "-w")

add_subdirectory(glfw)
target_compile_options(glfw PRIVATE "-w")

add_subdirectory(glm)
target_compile_options(glm INTERFACE "-w")

add_subdirectory(imgui)
target_compile_options(imgui INTERFACE "-w")

add_subdirectory(stb-cmake)
