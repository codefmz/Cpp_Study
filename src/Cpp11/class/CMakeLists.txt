file(GLOB SRC "./*.cpp")

add_executable(classT ${SRC})
target_link_libraries(classT PRIVATE GTest::gtest GTest::gtest_main)