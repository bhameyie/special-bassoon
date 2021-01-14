
#include <memory>
#include <utility>
#include <variant>
#include "presence_cache.h"
#include "service_models.h"
#include "presence.pb.h"
#include "presence_recorder_service.h"

PresenceRecorderService::PresenceRecorderService(std::shared_ptr<PresenceCache> cache) {
  presence_cache_ = std::move(cache);
}

PresenceRecorderService::~PresenceRecorderService() = default;

std::variant<UpdatedPresence,
             OperationFailure> PresenceRecorderService::UpdateStatus(
    const presence::UpdateUserConnectionRequest &request) const {
  /*TODO: Fire event and other niceties
  - validate user credentials
  - send an event in a topic of some kind for analysis of when the user typically comes on
      - should be done in a separate task/thread so to not hold anything up
  */

  if (request.last_seen_timestamp() < 1L) {
    return OperationFailure("Invalid request: 'last_seen_timestamp' is not in the proper range", OperationFailureCode::FAILED_VALIDATION);
  }

  if (request.user_id().empty()) {
    return OperationFailure("Invalid request: 'user_id' cannot be null", OperationFailureCode::FAILED_VALIDATION);
  }

  if (request.device_id().empty()) {
    return OperationFailure("Invalid request: 'device_id' cannot be null", OperationFailureCode::FAILED_VALIDATION);
  }

  const auto convertedRequest = PresenceUpdate{
      request.user_id(),
      request.device_id(),
      (unsigned int) request.status(),
      request.last_seen_timestamp()
  };

  try {
    return presence_cache_->UpdatePresence(convertedRequest);
  }
  catch (const std::exception &ex) {
    //todo: log here
    return OperationFailure("Unexpected error while updating the cache",
                            OperationFailureCode::FATAL_ERROR);
  }
}


