#include "a.h"

extern "C" {
    const char * get_message_from_static_lib_a() {
        static std::string message = A::get_message();
        return message.c_str();
    }
}