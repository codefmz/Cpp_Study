cmake_minimum_required(VERSION 3.25)
project(ABIDemo)

option(USE_NEW_ABI "Use C++11 ABI for static library" ON)

if(USE_NEW_ABI)
    set(STATICLIB_ABI_FLAG "-D_GLIBCXX_USE_CXX11_ABI=1")
    message(STATUS "Using C++11 ABI for static library")
else()
    set(STATICLIB_ABI_FLAG "-D_GLIBCXX_USE_CXX11_ABI=0")
    message(STATUS "Using old pre-C++11 ABI for static library")
endif()

add_library(static_lib_a STATIC a.cpp a.h)
set_target_properties(static_lib_a PROPERTIES POSITION_INDEPENDENT_CODE ON)
target_include_directories(static_lib_a PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_definitions(static_lib_a PUBLIC ${STATICLIB_ABI_FLAG})
set_target_properties(static_lib_a PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ../../lib)