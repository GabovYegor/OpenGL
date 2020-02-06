project(rectangle)
set(LIBS glfw GL GLEW)

add_executable(main main.cpp)
target_link_libraries(main ${LIBS})
