#ifndef __SERVICE_MODELS_H__
#define __SERVICE_MODELS_H__

#include <string>
#include <utility>

enum struct OperationFailureCode : int {
  NONE = 0,
  FATAL_ERROR=1,
  FAILED_VALIDATION=2
};

class OperationFailure{
 private:
  std::string error_message_;
  OperationFailureCode failure_code_;
 public:
  OperationFailure(std::string error_message, OperationFailureCode failure_code){
    error_message_=std::move(error_message);
    failure_code_=failure_code;
  }

  [[nodiscard]] std::string ErroMessage() const{
    return error_message_;
  }

  [[nodiscard]] OperationFailureCode FailureCode() const{
    return failure_code_;
  }
};

struct UpdatedPresence
{
    std::string user_id;
    unsigned int status_id;

  bool operator==(const UpdatedPresence &lhs) const {
    return status_id == lhs.status_id
        && user_id == lhs.user_id;
  }
};

struct RecordedPresence{
    std::string user_id;
    std::string device_id;
    unsigned int status_id;
    long last_seen_timestamp;
};

struct PresenceUpdate
{
    std::string user_id;
    std::string device_id;
    unsigned int status_id;
    long last_seen_timestamp;

    bool operator==(const PresenceUpdate &lhs) const{
      return status_id == lhs.status_id
          && device_id == lhs.device_id
          && last_seen_timestamp == lhs.last_seen_timestamp
          && user_id == lhs.user_id;
    }
};

#endif // __SERVICE_MODELS_H__
