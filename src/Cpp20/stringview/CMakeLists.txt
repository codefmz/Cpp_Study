file(GLOB SRC "./*.cpp")
add_library(stringview OBJECT ${SRC})
set_property(GLOBAL APPEND PROPERTY MY_MODULE_LIST stringview)