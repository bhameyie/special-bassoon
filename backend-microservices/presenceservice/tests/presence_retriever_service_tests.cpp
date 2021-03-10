

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "presence_cache.h"
#include "presence_cache_mock.h"
#include "presence_cache.cpp"
#include "presence_retriever_service.cpp"
#include <iostream>

#include <memory>
#include <variant>
#include "presence.pb.h"
#include "presence.grpc.pb.h"
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

using ::testing::_;
using ::testing::Ref;
using ::testing::Eq;
using ::testing::Return;
using ::testing::Throw;
using ::testing::Mock;
using namespace presence;
using namespace grpc;


struct SomeException : public exception {

};

class PresenceRetrieverServiceShould : public ::testing::Test {
 protected:
  std::shared_ptr<PresenceCacheMock> cache_ = std::make_shared<PresenceCacheMock>();
};

TEST_F(PresenceRetrieverServiceShould, ReturnAPresenceModelWhenTheItemIsFound) {

  const auto user_id = "meh";
  auto presence = RecordedPresence{};
  presence.user_id = user_id;
  presence.status_id = 1;
  presence.last_seen_timestamp = 988;
  presence.device_id = "lloo";

  EXPECT_CALL(*cache_, GetLatestById(user_id))
      .WillOnce(Return(presence));

  auto sut = PresenceRetrieverService{cache_};
  auto result = sut.GetPresenceById(user_id);

  EXPECT_TRUE(std::holds_alternative<PresenceModel>(result));

  auto model = std::get<PresenceModel>(result);

  EXPECT_EQ(model.last_seen_timestamp(), presence.last_seen_timestamp);

  EXPECT_EQ(model.last_seen_timestamp(), presence.last_seen_timestamp);
  EXPECT_EQ(model.user_id(), presence.user_id);
  EXPECT_EQ(model.device_id(), presence.device_id);
  EXPECT_EQ(model.status(), static_cast<ConnectionStatus>(presence.status_id));

}

TEST_F(PresenceRetrieverServiceShould, ReturnAnOperationFailureOnAnExceptionWhenGettingPresenceByUserId) {

  const auto user_id = "meh";

  EXPECT_CALL(*cache_, GetLatestById(user_id))
      .WillOnce(Throw(SomeException()));

  auto sut = PresenceRetrieverService{cache_};
  auto result = sut.GetPresenceById(user_id);

  EXPECT_TRUE(std::holds_alternative<OperationFailure>(result));
}

TEST_F(PresenceRetrieverServiceShould, ReturnAnOperationFailureOnItemNotFoundWhenGettingPresenceByUserId) {

  const auto user_id = "meh";

  std::optional<RecordedPresence> presence = {};
  EXPECT_CALL(*cache_, GetLatestById(user_id))
      .WillOnce(Return(presence));

  auto sut = PresenceRetrieverService{cache_};
  auto result = sut.GetPresenceById(user_id);

  EXPECT_TRUE(std::holds_alternative<OperationFailure>(result));

  auto err = std::get<OperationFailure>(result);
  EXPECT_EQ(err.FailureCode(), OperationFailureCode::ITEM_NOT_FOUND);
}
