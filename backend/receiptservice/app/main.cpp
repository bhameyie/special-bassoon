#include <iostream>
#include <receiptservice/Yello.hpp>
#include <fmt/format.h>


int main() {
    std::cout << "Hello, World!" << std::endl;
        
    fmt::print("Meh: {}\n",  meh(3));

    return 0;
}
