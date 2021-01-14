#ifndef __PRESENCE_RETRIEVER_SERVICE_H__
#define __PRESENCE_RETRIEVER_SERVICE_H__

#include <memory>
#include <iostream>
#include <variant>
#include "presence_cache.h"
#include "service_models.h"
#include "presence.pb.h"
#include "presence.grpc.pb.h"

class PresenceRetrieverService {
 private:
  std::shared_ptr<PresenceCache> presence_cache_;

 public:
  explicit PresenceRetrieverService(std::shared_ptr<PresenceCache> cache);

  std::variant<presence::PresenceModel,OperationFailure> GetPresenceById(const std::string &user_id);
};

#endif // __PRESENCE_RETRIEVER_SERVICE_H__