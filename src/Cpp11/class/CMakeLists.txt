file(GLOB SRC "./*.cpp")

add_library(classT OBJECT ${SRC})
# target_link_libraries(classT PUBLIC gtest)
target_include_directories(classT PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})