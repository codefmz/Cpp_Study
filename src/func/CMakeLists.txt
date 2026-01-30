file(GLOB SRC "./*.cpp")

add_library(funcT STATIC ${SRC})
target_link_libraries(funcT gtest)
target_include_directories(funcT PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})