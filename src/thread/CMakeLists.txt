file(GLOB SRC "threadTest.cpp")
add_library(threadT STATIC ${SRC})
target_link_libraries(threadT gtest)
target_include_directories(threadT PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})