#include "buffer.h"
#include <iostream>

int main() {
    Buffer bf("hello world");
    std::cout << bf.str() << "--->at(1): " << bf.at(1) << std::endl;
    bf.remove_prefix(6);
    std::cout << bf.str() << "--->at(1): " << bf.at(1) << std::endl;
    Buffer hello("hello");
    Buffer world("world");
    BufferList bl(hello);
    bl.append(world);

    BufferViewList blv(bl);

    std::cout << bl.concatenate() << std::endl; 
    bl.remove_prefix(7);
    std::cout << bl.concatenate() << std::endl; 

    std::cout << blv.size() << std::endl;
    blv.remove_prefix(3);
    std::cout << blv.size() << std::endl;

    const char* str_c = "hello char";
    BufferViewList bl2(str_c);
}