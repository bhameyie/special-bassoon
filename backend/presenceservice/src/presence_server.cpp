
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

class PresenceRecorderImpl final : public PresenceRecorder::Service
{
    
public:
    PresenceRecorderImpl(shared_ptr<PresenceCache> cache)
    {
        presence_cache_ = cache;
    }

    Status UpdateStatus(::grpc::ServerContext *context,
                        const ::presence::UpdateUserConnectionRequest *request,
                        ::presence::UpdateUserConnectionReply *response)
    {
        return Status::OK;
    }

private:
    std::shared_ptr<PresenceCache> presence_cache_;
};