//
// Created by Boguste Hameyie on 1/14/21.
//

#ifndef BACKEND_CHATSERVER_SRC_CONFIGURATION_MODELS_H_
#define BACKEND_CHATSERVER_SRC_CONFIGURATION_MODELS_H_

#include <string>

struct ServiceConfiguration {
  std::string connection_string;
  std::string endpoint_name;
  std::string presence_service_url;
};

#endif //BACKEND_CHATSERVER_SRC_CONFIGURATION_MODELS_H_
