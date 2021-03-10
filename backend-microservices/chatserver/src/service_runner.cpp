//
// Created by Boguste Hameyie on 1/14/21.
//

#include "service_runner.h"

#include <utility>
ServiceRunner::ServiceRunner(std::string serverAddress, ServiceConfiguration configuration)
: server_address_(std::move(serverAddress)),configuration_(std::move(configuration)){

}

std::unique_ptr<grpc::Server> ServiceRunner::Run(){

  //todo: play around with this
  // server->SetGlobalCallbacks()
  return nullptr;
}
