file(GLOB SRC "./*.cpp")
add_library(pointerT STATIC ${SRC})
target_link_libraries(pointerT gtest)
target_include_directories(pointerT PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})