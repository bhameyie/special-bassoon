
#include <iostream>
#include <memory>
#include <string>

#include "presence.pb.h"
#include "presence.grpc.pb.h"
#include "presence_cache.h"
#include "presence_recorder_service.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

using namespace presence;
using namespace std;

class PresenceRecorderImpl final : public PresenceRecorder::Service {

 public:
  explicit PresenceRecorderImpl(std::unique_ptr<PresenceRecorderService> service) {
    service_ = std::move(service);
  }

  grpc::Status UpdateStatus(::grpc::ServerContext *context,
                            const ::presence::UpdateUserConnectionRequest *request,
                            ::presence::UpdateUserConnectionReply *response) override {

    return Status::OK;
  }

 private:
  std::unique_ptr<PresenceRecorderService> service_;
};