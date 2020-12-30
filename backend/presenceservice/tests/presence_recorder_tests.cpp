
#include "gtest/gtest.h"
#include "presence_cache_mock.h"
#include "presence_cache.cpp"
#include "presence_recorder.cpp"

#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

using namespace presence;
using namespace grpc;

//todo: delete. weird error when cerating the Recorder. replace with scenario based tests
TEST(PresenceRecorderShould, HoldNoDataInitially)
{
        //auto mock = std::make_shared<PresenceCacheMock>();
        // mock.get()->gmock_UpdatePresence
        //auto sut = PresenceRecorderImpl(nullptr);
}
