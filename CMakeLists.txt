cmake_minimum_required(VERSION 3.2)

project(opengl-car)

find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)

file(GLOB src CONFIGURE_DEPENDS "src/*.hpp" "src/*.cpp")

set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_CXX_FLAGS_RELEASE "-std=c++17 -Wall -pipe -O2")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_RELEASE} -DDEBUG")

add_executable(opengl-car ${src})

target_link_libraries(opengl-car glfw)
target_link_libraries(opengl-car OpenGL::GL)
