file(GLOB SRC "./*.cpp")

add_executable(stringview ${SRC})
target_link_libraries(stringview PRIVATE GTest::gtest GTest::gtest_main)