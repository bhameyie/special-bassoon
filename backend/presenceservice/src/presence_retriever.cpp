
#include <iostream>
#include <memory>
#include <string>

#include "presence.pb.h"
#include "presence.grpc.pb.h"
#include "presence_cache.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

using namespace presence;
using namespace std;

class PresenceRetrieverImpl final : public PresenceRetriever::Service
{

public:
    PresenceRetrieverImpl(shared_ptr<PresenceCache> cache)
    {
        presence_cache_ = cache;
    }

    grpc::Status RetrieveUserPresenceByDevice(::grpc::ServerContext *context, const ::presence::RetrieveUserPresenceByDeviceRequest *request, ::presence::RetrieveUserPresenceByDeviceResponse *response)
    {
        return Status::OK;
    }

    grpc::Status RetrieveUserPresenceById(::grpc::ServerContext *context, const ::presence::RetrieveUserPresenceByIdRequest *request, ::presence::RetrieveUserPresenceByIdResponce *response)
    {
        return Status::OK;
    }

private:
    std::shared_ptr<PresenceCache> presence_cache_;
};