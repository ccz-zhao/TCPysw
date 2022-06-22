#include "buffer.h"
#include <iostream>

int main() {
    Buffer bf("hello world");
    std::cout << bf.str() << "--->at(1): " << bf.at(1) << std::endl;
    bf.remove_prefix(6);
    std::cout << bf.str() << "--->at(1): " << bf.at(1) << std::endl;

}