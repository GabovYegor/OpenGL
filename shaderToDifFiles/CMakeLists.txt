cmake_minimum_required(VERSION 3.10)
project(changeColor)
set(LIBS glfw GL GLEW)
set(SHADER_DIR Shader)

include_directories(dir PRIVATE ${SHADER_DIR})
add_library(lib ${SHADER_DIR}/Shader.cpp ${SHADER_DIR}/Shader.h)

add_executable(main main.cpp)
target_link_libraries(main lib)
target_link_libraries(main ${LIBS})
