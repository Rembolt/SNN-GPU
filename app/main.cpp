#include "CLBoilerplate.h"

#include <iostream>

int main() {
    try {
        CLBoilerplate cl;
        cl.printDevice();
    } catch (const std::exception& e) {
        std::cerr << "OpenCL error: " << e.what() << '\n';
        return 1;
    }
    return 0;
}
