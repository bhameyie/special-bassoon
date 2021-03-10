
#include "utils.h"
#include <chrono>

namespace bassoon {
namespace common {

grpc::StatusCode FailureCodeToStatusCode(OperationFailureCode code) {

  if (code == OperationFailureCode::FAILED_VALIDATION) {
    return grpc::StatusCode::INVALID_ARGUMENT;
  }

  if (code == OperationFailureCode::FATAL_ERROR) {
    return grpc::StatusCode::INTERNAL;
  }

  if (code == OperationFailureCode::ITEM_NOT_FOUND) {
    return grpc::StatusCode::NOT_FOUND;
  }

  return grpc::StatusCode::OK;
}

long GetCurrentTimestamp() {
  return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

}
}
