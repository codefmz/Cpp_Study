#include <iostream>

extern "C" {
    const char * get_message_from_static_lib_a();
}

int main() {
    std::cout << get_message_from_static_lib_a() << std::endl;
    return 0;
}