cmake_minimum_required(VERSION 3.9)
project(moltenvkcpp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

find_package(glfw3 REQUIRED)
find_package(Vulkan REQUIRED)
find_package(glm REQUIRED)

add_executable(moltenvkcpp main.cpp)

include_directories(game)

add_subdirectory(game)
add_subdirectory(shaders)
add_subdirectory(tests)

enable_testing()
add_test(basic_tests tests/basic_tests/moltenvkcpp_tests)

add_dependencies(moltenvkcpp shaders)

add_custom_command(TARGET moltenvkcpp POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_FILE_DIR:moltenvkcpp>/shaders/"
        COMMAND ${CMAKE_COMMAND} -E copy_directory "$<TARGET_FILE_DIR:moltenvkcpp>/shaders" "$<TARGET_FILE_DIR:moltenvkcpp>/shaders")

target_link_libraries(moltenvkcpp game glm glfw Vulkan::Vulkan)