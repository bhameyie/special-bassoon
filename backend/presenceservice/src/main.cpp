#include <iostream>
#include "Yello.cpp"
#include <fmt/format.h>
#include "service_runner.cpp"

int main() {
    std::cout << "Hello, World!" << std::endl;
        
    fmt::print("Meh: {}\n",  meh(3));

    ServiceRunner runner("0.0.0.0:50051");

    auto server = runner.Run();

    server->Wait();

    return 0;
}