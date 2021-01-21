//
// Created by Boguste Hameyie on 1/14/21.
//

#ifndef BACKEND_CHATSERVER_SRC_SERVICE_RUNNER_H_
#define BACKEND_CHATSERVER_SRC_SERVICE_RUNNER_H_

#include <string>
#include <memory>
#include <string>
#include <utility>

#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include "configuration_models.h"

class ServiceRunner{

 public:
  ServiceRunner(std::string serverAddress, ServiceConfiguration configuration);
  std::unique_ptr<grpc::Server> Run();

 private:
  std::string server_address_;
  ServiceConfiguration configuration_;
};

#endif //BACKEND_CHATSERVER_SRC_SERVICE_RUNNER_H_
