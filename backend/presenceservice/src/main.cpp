#include <iostream>
#include <fmt/format.h>
#include "service_runner.cpp"
#include "presence_recorder_service.cpp"

int main() {
  std::cout << "Hello, World!" << std::endl;

  //UpdateUserConnectionRequest req;
  fmt::print("Meh: {}\n", meh(3));

  ServiceRunner runner("0.0.0.0:50051");

  auto server = runner.Run();

  server->Wait();

  return 0;
}
