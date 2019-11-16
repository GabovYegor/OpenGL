project(test_1)
set(OPENGL_LIBS glfw GL GLEW)

add_executable(main main.cpp)
target_link_libraries(main ${OPENGL_LIBS})
