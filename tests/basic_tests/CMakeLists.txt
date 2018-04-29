include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(moltenvkcpp_tests basic_tests.cpp)

target_link_libraries(moltenvkcpp_tests gtest gtest_main)
target_link_libraries(moltenvkcpp_tests game)