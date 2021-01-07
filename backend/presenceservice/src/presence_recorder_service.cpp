
#include <memory>
#include <iostream>
#include <utility>
#include <variant>
#include "presence_cache.h"

#include "presence.pb.h"
#include "presence.grpc.pb.h"
#include "presence_recorder_service.h"

PresenceRecorderService::PresenceRecorderService(std::shared_ptr<PresenceCache> cache) {
  presence_cache_ = std::move(cache);
}

PresenceRecorderService::~PresenceRecorderService() = default;

std::variant<UpdatedPresence,OperationFailure> PresenceRecorderService::UpdateStatus(const presence::UpdateUserConnectionRequest &request) const {
  /*TODO: Fire event and other niceties
  - send an event in a topic of somekind for analysis of when the user typically comes on
      - should be done in a separate task/thread so to not hold anything up
  */
  std::variant<UpdatedPresence,OperationFailure> toReturn;

  toReturn = OperationFailure("meh", OperationFailureCode::NONE);
  return toReturn;
}


