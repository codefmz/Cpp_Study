file(GLOB SRC "./*.cpp")

add_executable(module ${SRC})
target_link_libraries(module PRIVATE GTest::gtest GTest::gtest_main)