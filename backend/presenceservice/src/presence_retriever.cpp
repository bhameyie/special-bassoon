#include <variant>
#include <memory>
#include "presence.pb.h"
#include "presence.grpc.pb.h"
#include "presence_retriever_service.h"
#include "utils.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

using namespace presence;
using namespace std;

class PresenceRetrieverImpl final : public PresenceRetriever::Service {

 public:
  explicit PresenceRetrieverImpl(std::unique_ptr<PresenceRetrieverService> service) {
    service_ = std::move(service);
  }

  ::grpc::Status RetrieveUserPresenceByUserId(::grpc::ServerContext *context,
                                              const ::presence::RetrieveUserPresenceByIdRequest *request,
                                              ::presence::RetrieveUserPresenceByIdResponse *response) override {

    auto result = service_->GetPresenceById(request->user_id());

    return std::visit([&response](std::variant<PresenceModel,
                                               OperationFailure> &&x) {

      if (auto retrieved = std::get_if<PresenceModel>(&x)) {

        response->set_allocated_model(retrieved);
        return Status::OK;
      } else {
        auto failure = std::get<OperationFailure>(x);
        return Status(FailureCodeToStatusCode(failure.FailureCode()), failure.ErrorMessage());

      }

    }, result);
  }

 private:
  std::unique_ptr<PresenceRetrieverService> service_;
};