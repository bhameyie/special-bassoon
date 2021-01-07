
#include <iostream>
#include <memory>
#include <string>

#include "presence.pb.h"
#include "presence.grpc.pb.h"
#include "presence_cache.h"
#include "presence_retriever_service.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

using namespace presence;
using namespace std;

class PresenceRetrieverImpl final : public PresenceRetriever::Service
{

public:
    explicit PresenceRetrieverImpl(std::unique_ptr<PresenceRetrieverService> service)
    {
        service_ = std::move(service);
    }

    grpc::Status RetrieveUserPresenceByDevice(::grpc::ServerContext *context, const ::presence::RetrieveUserPresenceByDeviceRequest *request, ::presence::RetrieveUserPresenceByDeviceResponse *response) override
    {
        return Status::OK;
    }

    grpc::Status RetrieveUserPresenceById(::grpc::ServerContext *context, const ::presence::RetrieveUserPresenceByIdRequest *request, ::presence::RetrieveUserPresenceByIdResponce *response) override
    {
        return Status::OK;
    }

private:
    std::unique_ptr<PresenceRetrieverService> service_;
};