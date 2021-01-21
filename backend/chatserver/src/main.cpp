#include "service_runner.h"

int main() {

  //todo: configuration should be read from a file or environment variable
  auto config = ServiceConfiguration{};

  ServiceRunner runner("0.0.0.0:50051", config);

  auto server = runner.Run();

  server->Wait();

  return 0;
}
