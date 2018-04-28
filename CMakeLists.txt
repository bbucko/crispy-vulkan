cmake_minimum_required(VERSION 3.10)
project(moltenvkcpp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")


find_package(glfw3 REQUIRED)
find_package(Vulkan REQUIRED)
find_package(glm REQUIRED)

add_executable(moltenvkcpp main.cpp)
target_link_libraries(moltenvkcpp glm glfw Vulkan::Vulkan)