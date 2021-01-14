#include <memory>
#include <utility>
#include "presence_cache.h"

#include "service_models.h"
#include "presence.pb.h"
#include "presence_retriever_service.h"

using namespace presence;

PresenceRetrieverService::PresenceRetrieverService(std::shared_ptr<PresenceCache> cache) {
  presence_cache_ = std::move(cache);
}

std::variant<presence::PresenceModel,
             OperationFailure> PresenceRetrieverService::GetPresenceById(const std::string &user_id) {
  try {
    auto found = presence_cache_->GetLatestById(user_id);

    if (found.has_value()) {
      auto model = PresenceModel{};
      model.set_user_id(found.value().user_id);
      model.set_status(static_cast<ConnectionStatus>(found.value().status_id));
      model.set_last_seen_timestamp(found.value().last_seen_timestamp);
      model.set_device_id(found.value().device_id);
      return model;
    }

    return OperationFailure("No presence status found for the requested user", OperationFailureCode::ITEM_NOT_FOUND);
  }
  catch (const std::exception &ex) {
    //todo: log it
    return OperationFailure("Unexpected error while retrieving presence from the cache",
                            OperationFailureCode::FATAL_ERROR);
  }
}