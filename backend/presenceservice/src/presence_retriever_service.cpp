#include <memory>
#include <iostream>
#include "presence_cache.h"

#include "presence.pb.h"
#include "presence.grpc.pb.h"
#include "presence_retriever_service.h"

PresenceRetrieverService::PresenceRetrieverService(std::shared_ptr<PresenceCache> cache)
{
    presence_cache_ = cache;
}

PresenceRetrieverService::~PresenceRetrieverService()
{
}