cmake_minimum_required(VERSION 3.28.0)
project(cppcore VERSION 1.0.0)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

message(STATUS "C++ compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "C++ compiler version: ${CMAKE_CXX_COMPILER_VERSION}")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
)

link_directories(
    ${PROJECT_SOURCE_DIR}/lib
)

set_property(GLOBAL PROPERTY MY_MODULE_LIST "")
add_subdirectory(src)

get_property(MY_MODULE_LIST GLOBAL PROPERTY MY_MODULE_LIST)
message(STATUS "Module list: ${MY_MODULE_LIST}")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
add_executable(cs main.cpp)
target_link_libraries(cs PRIVATE gtest ${MY_MODULE_LIST})