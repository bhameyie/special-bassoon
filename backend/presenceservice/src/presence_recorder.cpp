
#include <memory>
#include <variant>
#include "presence.pb.h"
#include "presence.grpc.pb.h"
#include "presence_cache.h"
#include "presence_recorder_service.h"
#include "utils.h"

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

    auto result = service_->UpdateStatus(*request);

    return std::visit([&response](std::variant<UpdatedPresence,
                                               OperationFailure> &&x) {

      if (auto updated = std::get_if<UpdatedPresence>(&x)) {

        response->set_status(static_cast<ConnectionStatus>(updated->status_id));
        return Status::OK;
      } else {

        auto failure = std::get<OperationFailure>(x);
        response->set_status(ConnectionStatus::UNDETERMINED);
        return Status(FailureCodeToStatusCode(failure.FailureCode()), failure.ErrorMessage());
      }
    }, result);

  }

 private:
  std::unique_ptr<PresenceRecorderService> service_;
};