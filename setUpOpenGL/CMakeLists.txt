project(Try_setUP_OpenGL)
set(LIBS glfw GL GLEW)

add_executable(openGL openGL.cpp)
target_link_libraries(openGL ${LIBS})
