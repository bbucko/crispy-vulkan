cmake_minimum_required(VERSION 3.10)
project(moltenvkcpp)

set(CMAKE_CXX_STANDARD 11)

find_package(vulkan REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)

include_directories(${OPENGL_INCLUDE_DIR})

add_executable(moltenvkcpp main.cpp)
target_link_libraries(moltenvkcpp glm glfw Vulkan::Vulkan)