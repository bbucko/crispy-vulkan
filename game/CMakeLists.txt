project(game)

file(GLOB CXX_SOURCES "*.cpp" "*.h")

add_library(game SHARED "${CXX_SOURCES}")

