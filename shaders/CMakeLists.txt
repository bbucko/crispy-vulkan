project(shaders)

if (UNIX)
    set(GLSL_VALIDATOR "glslangValidator")
elseif (APPLE)
    set(GLSL_VALIDATOR "$ENV{VULKAN_SDK}/bin/glslangValidator")
endif (UNIX)

# Add shaders
file(GLOB SHADER_SOURCES "*.frag" "*.vert")

foreach (GLSL ${SHADER_SOURCES})
    get_filename_component(FILE_NAME ${GLSL} NAME)
    set(SPIRV "${PROJECT_BINARY_DIR}/${FILE_NAME}.spv")

    message("Compiling: ${GLSL} to ${SPIRV}")
    add_custom_command(
            OUTPUT ${SPIRV}
            COMMAND ${GLSL_VALIDATOR} -V ${GLSL} -o ${SPIRV}
            DEPENDS ${GLSL})
    list(APPEND SPIRV_BINARY_FILES ${SPIRV})
endforeach (GLSL)

message("SPV files: ${SPIRV_BINARY_FILES}")

add_custom_target(shaders DEPENDS ${SPIRV_BINARY_FILES})