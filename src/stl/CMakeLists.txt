file(GLOB SRC "./*.cpp")
add_library(stlT STATIC ${SRC})
target_link_libraries(stlT gtest)
target_include_directories(stlT PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})