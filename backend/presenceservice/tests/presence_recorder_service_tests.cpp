
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "presence_cache.h"
#include "presence_cache_mock.h"
#include "presence_cache.cpp"
#include "presence_recorder_service.cpp"

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
using ::testing::Return;
using ::testing::Throw;

using namespace presence;
using namespace grpc;

/* TODO
 * test typical scenario of all is well
 * test scenario where an exception occurs
 */

TEST(PresenceRecorderServiceShould, HoldNoDataInitially) {
  PresenceCacheMock cache;

  const std::shared_ptr<PresenceCache> mock = std::shared_ptr<PresenceCacheMock>(&cache);
  //google::protobuf::Arena p;
  UpdateUserConnectionRequest req;
  req.set_device_id("dev");
  req.set_status(ConnectionStatus::AWAY);
  req.set_last_seen_timestamp(23L);

  auto update = UpdatedPresence();
  update.status_id = 2;
  update.user_id = "dev";

  const auto updated = UpdatedPresence{
      "user1",
      1
  };

  EXPECT_CALL(cache, UpdatePresence(_))
      .WillOnce(Return(updated));

  auto sut = PresenceRecorderService(mock);
  auto result = sut.UpdateStatus(req);

  EXPECT_TRUE(std::holds_alternative<UpdatedPresence>(result));
}
