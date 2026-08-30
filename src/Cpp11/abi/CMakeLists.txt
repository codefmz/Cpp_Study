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


add_subdirectory(shared_lib_b)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE shared_lib_b)