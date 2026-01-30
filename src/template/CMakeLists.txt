file(GLOB SRC "./*.cpp")
add_library(templateT STATIC ${SRC})
target_link_libraries(templateT gtest)
target_include_directories(templateT PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})