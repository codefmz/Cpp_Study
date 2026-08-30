add_library(shared_lib_b SHARED b.cpp)
target_include_directories(shared_lib_b PUBLIC ${PROJECT_SOURCE_DIR}/static_lib_a)
target_link_directories(shared_lib_b PRIVATE ${PROJECT_SOURCE_DIR}/lib)
target_link_libraries(shared_lib_b PRIVATE static_lib_a)
