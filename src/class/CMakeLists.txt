file(GLOB SRC "./*.cpp")

add_library(classT STATIC ${SRC})
target_link_libraries(classT gtest)
target_include_directories(classT PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})