
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "presence_cache.h"
#include "presence_cache_mock.h"
#include "presence_cache.cpp"
#include "presence_recorder_service.cpp"
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

/* TODO
 * test typical scenario of all is well
 * test scenario where an exception occurs
 */

struct SomeException : public exception {

};

class PresenceRecorderServiceShould : public ::testing::Test {
 protected:
  std::shared_ptr<PresenceCacheMock> cache_ = std::make_shared<PresenceCacheMock>();
};

TEST_F(PresenceRecorderServiceShould, ReturnUpdatedPresenceWhenNoErrorOccurs) {

  UpdateUserConnectionRequest req;
  req.set_device_id("dev");
  req.set_user_id("u1");
  req.set_status(ConnectionStatus::AWAY);
  req.set_last_seen_timestamp(23L);

  auto update = PresenceUpdate();
  update.status_id = 2;
  update.device_id = "dev";
  update.user_id = "u1";
  update.last_seen_timestamp = 23L;

  const auto updated = UpdatedPresence{
      "user1",
      1
  };

  EXPECT_CALL(*cache_, UpdatePresence(_))
      .WillOnce(Return(updated));

  PresenceRecorderService sut(cache_);
  auto result = sut.UpdateStatus(req);

  EXPECT_TRUE(std::holds_alternative<UpdatedPresence>(result));
  EXPECT_EQ(std::get<UpdatedPresence>(result), updated);

  EXPECT_TRUE(Mock::VerifyAndClearExpectations(cache_.get()));
}

TEST_F(PresenceRecorderServiceShould, ReturnOperationFailureWhenUserIdIsNull) {
  EXPECT_TRUE(false);
}

TEST_F(PresenceRecorderServiceShould, ReturnOperationFailureWhenDeviceIdIsNull) {

  EXPECT_TRUE(false);
}

TEST_F(PresenceRecorderServiceShould, ReturnOperationFailureWhenTimeStampIsLessThan1) {

  EXPECT_TRUE(false);
}

TEST_F(PresenceRecorderServiceShould, ReturnOperationFailureWhenAnExceptionIsThrown) {

  UpdateUserConnectionRequest req;
  req.set_device_id("dev");
  req.set_user_id("u1");
  req.set_status(ConnectionStatus::AWAY);
  req.set_last_seen_timestamp(23L);

  auto update = PresenceUpdate();
  update.status_id = 2;
  update.device_id = "dev";
  update.user_id = "u1";
  update.last_seen_timestamp = 23L;

  EXPECT_CALL(*cache_, UpdatePresence(_))
      .WillOnce(Throw(SomeException()));

  PresenceRecorderService sut(cache_);
  auto result = sut.UpdateStatus(req);

  EXPECT_TRUE(std::holds_alternative<OperationFailure>(result));

  EXPECT_TRUE(Mock::VerifyAndClearExpectations(cache_.get()));
}
