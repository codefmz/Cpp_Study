file(GLOB SRC "./*.cpp")

add_executable(pointer ${SRC})
target_link_libraries(pointer PRIVATE GTest::gtest GTest::gtest_main)