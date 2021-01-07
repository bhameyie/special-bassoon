#include "service_runner.cpp"
#include "presence_recorder_service.cpp"

int main() {

  //UpdateUserConnectionRequest req;
  ServiceRunner runner("0.0.0.0:50051");

  auto server = runner.Run();

  server->Wait();

  return 0;
}
