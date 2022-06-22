#include <string>
#include <iostream>
#include <stdlib.h>

void error_handling(const std::string& message) {
    std::cerr << message << std::endl;
    exit(1);
}