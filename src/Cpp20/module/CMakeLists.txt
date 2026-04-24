file(GLOB SRC "./*.cpp")
add_library(module OBJECT ${SRC})
set_property(GLOBAL APPEND PROPERTY MY_MODULE_LIST module)