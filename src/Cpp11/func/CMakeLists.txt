file(GLOB SRC "./*.cpp")
add_library(func OBJECT ${SRC})
set_property(GLOBAL APPEND PROPERTY MY_MODULE_LIST func)