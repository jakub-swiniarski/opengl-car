cmake_minimum_required(VERSION 3.2)

project(shift-and-drift)

find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)

file(GLOB src CONFIGURE_DEPENDS "src/*.hpp" "src/*.cpp")
set(CMAKE_CXX_FLAGS_RELEASE "-Wall -pipe -O2")
add_executable(shift-and-drift ${src})
target_link_libraries(shift-and-drift glfw)
target_link_libraries(shift-and-drift OpenGL::GL)
