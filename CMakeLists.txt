cmake_minimum_required(VERSION 3.16)

project(cpp_study VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(MSVC)
    add_compile_options(/utf-8)
endif()

include_directories(
    ${PROJECT_SOURCE_DIR}/include
)

find_package(GTest CONFIG REQUIRED)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
add_subdirectory(src)