#include <memory>
#include <iostream>
#include <utility>
#include "presence_cache.h"

#include "presence.pb.h"
#include "presence.grpc.pb.h"
#include "presence_retriever_service.h"

PresenceRetrieverService::PresenceRetrieverService(std::shared_ptr<PresenceCache> cache)
{
    presence_cache_ = std::move(cache);
}

PresenceRetrieverService::~PresenceRetrieverService()
= default;