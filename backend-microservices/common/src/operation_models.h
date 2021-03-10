#ifndef __OPERATION_MODELS_H__
#define __OPERATION_MODELS_H__

#include <string>
#include <utility>

namespace bassoon {
namespace common {

enum struct OperationFailureCode : int {
  NONE = 0,
  FATAL_ERROR = 1,
  FAILED_VALIDATION = 2,
  ITEM_NOT_FOUND = 3,
};

class OperationFailure {
 private:
  std::string error_message_;
  OperationFailureCode failure_code_;
 public:
  OperationFailure(std::string error_message, OperationFailureCode failure_code) {
    error_message_ = std::move(error_message);
    failure_code_ = failure_code;
  }

  [[nodiscard]] std::string ErrorMessage() const {
    return error_message_;
  }

  [[nodiscard]] OperationFailureCode FailureCode() const {
    return failure_code_;
  }
};

}
}
#endif // __OPERATION_MODELS_H__
