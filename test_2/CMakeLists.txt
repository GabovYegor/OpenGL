project(test_2)
set(OPENGL_LIBS glfw GL GLEW)

add_executable(openGL openGL.cpp)
target_link_libraries(openGL ${OPENGL_LIBS})
