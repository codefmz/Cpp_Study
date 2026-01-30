cmake_minimum_required(VERSION 3.10.0)
project(cppcore VERSION 1.0.0)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

message(STATUS "C++ compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "C++ compiler version: ${CMAKE_CXX_COMPILER_VERSION}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

link_directories(
    ${PROJECT_SOURCE_DIR}/lib
)

enable_testing()

add_subdirectory(src)

add_executable(cs main.cpp)
target_link_libraries(cs gtest)
target_link_libraries(cs
    -Wl,--whole-archive
    classT
    funcT
    pointerT
    regexT
    templateT
    threadT
    -Wl,--no-whole-archive
)