cmake_minimum_required(VERSION 3.10)
project(changeColor)
set(LIBS glfw GL GLEW SOIL)
set(SHADER_DIR ShaderClass)

add_executable(main main.cpp)
add_library(lib ${SHADER_DIR}/Shader.cpp ${SHADER_DIR}/Shader.h)
target_link_libraries(main lib ${LIBS})
