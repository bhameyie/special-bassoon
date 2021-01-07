#ifndef __PRESENCE_RETRIEVER_SERVICE_H__
#define __PRESENCE_RETRIEVER_SERVICE_H__

#include <memory>
#include <iostream>
#include "presence_cache.h"

#include "presence.pb.h"
#include "presence.grpc.pb.h"

class PresenceRetrieverService
{
private:
    std::shared_ptr<PresenceCache> presence_cache_;

public:
    explicit PresenceRetrieverService(std::shared_ptr<PresenceCache> cache) ;

    ~PresenceRetrieverService();
    
};

#endif // __PRESENCE_RETRIEVER_SERVICE_H__