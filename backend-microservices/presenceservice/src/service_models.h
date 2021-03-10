//
// Created by Boguste Hameyie on 1/20/21.
//

#ifndef BACKEND_PRESENCESERVICE_SRC_SERVICE_MODELS_H_
#define BACKEND_PRESENCESERVICE_SRC_SERVICE_MODELS_H_

struct UpdatedPresence {
  std::string user_id;
  unsigned int status_id;

  bool operator==(const UpdatedPresence &lhs) const {
    return status_id == lhs.status_id
        && user_id == lhs.user_id;
  }
};

struct RecordedPresence {
  std::string user_id;
  std::string device_id;
  unsigned int status_id;
  long last_seen_timestamp;
};

struct PresenceUpdate {
  std::string user_id;
  std::string device_id;
  unsigned int status_id;
  long last_seen_timestamp;

  bool operator==(const PresenceUpdate &lhs) const {
    return status_id == lhs.status_id
        && device_id == lhs.device_id
        && last_seen_timestamp == lhs.last_seen_timestamp
        && user_id == lhs.user_id;
  }
};

#endif //BACKEND_PRESENCESERVICE_SRC_SERVICE_MODELS_H_
