cmake_minimum_required(VERSION 3.9)
project(moltenvkcpp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")
set(GLSL_VALIDATOR "$ENV{VULKAN_SDK}/bin/glslangValidator")

find_package(glfw3 REQUIRED)
find_package(Vulkan REQUIRED)
find_package(glm REQUIRED)

file(GLOB CXX_SOURCES "src/*.cpp")

add_executable(moltenvkcpp ${CXX_SOURCES})

# Add shaders
file(GLOB SHADER_SOURCES "shaders/*.frag" "shaders/*.vert")

foreach (GLSL ${SHADER_SOURCES})
    message("Compiling: ${GLSL}")
    get_filename_component(FILE_NAME ${GLSL} NAME)
    set(SPIRV "${PROJECT_BINARY_DIR}/shaders/${FILE_NAME}.spv")
    add_custom_command(
            OUTPUT ${SPIRV}
            COMMAND ${CMAKE_COMMAND} -E make_directory "${PROJECT_BINARY_DIR}/shaders/"
            COMMAND ${GLSL_VALIDATOR} -V ${GLSL} -o ${SPIRV}
            DEPENDS ${GLSL})
    list(APPEND SPIRV_BINARY_FILES ${SPIRV})
endforeach (GLSL)

add_custom_target(shaders DEPENDS ${SPIRV_BINARY_FILES})

add_dependencies(moltenvkcpp shaders)

add_custom_command(TARGET moltenvkcpp POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_FILE_DIR:moltenvkcpp>/shaders/"
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${PROJECT_BINARY_DIR}/shaders"
        "$<TARGET_FILE_DIR:moltenvkcpp>/shaders")

target_link_libraries(moltenvkcpp glm glfw Vulkan::Vulkan)