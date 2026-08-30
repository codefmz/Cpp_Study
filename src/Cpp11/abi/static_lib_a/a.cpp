#include "a.h"

std::string A::get_message() {
    return "Hello from static library ABI = "
    #if _GLIBCXX_USE_CXX11_ABI
        "1";
    #else
        "0";
    #endif
}