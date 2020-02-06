project(hello_world)
set(HELLOWORLDLIB_DIR dir)

include_directories(dir PRIVATE ${HELLOWORLDLIB_DIR})
add_library(lib ${HELLOWORLDLIB_DIR}/helloworld.cpp ${HELLOWORLDLIB_DIR}/helloworld.h)
add_executable(test test.cpp)
target_link_libraries(test lib)
