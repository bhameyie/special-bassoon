
#include <iostream>
#include <memory>
#include <string>
#include <utility>

#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>

#include "presence_recorder_service.h"
#include "presence_recorder.cpp"
#include "presence_retriever.cpp"
#include "presence_cache.cpp"

using namespace std;
using namespace grpc;

class ServiceRunner
{

public:
    explicit ServiceRunner(string serverAddress)
    {
        server_address_ = std::move(serverAddress);
    }

    std::unique_ptr<Server> Run()
    {
        std::shared_ptr<PresenceCache> cache = std::make_shared<PresenceCacheImpl>();

        PresenceRecorderImpl presence_recorder(std::make_unique<PresenceRecorderService>(PresenceRecorderService(cache)));
        PresenceRetrieverImpl presence_retriever(std::make_unique<PresenceRetrieverService>(PresenceRetrieverService(cache)));

        grpc::EnableDefaultHealthCheckService(true);
        grpc::reflection::InitProtoReflectionServerBuilderPlugin();

        ServerBuilder builder;
        // Listen on the given address without any authentication mechanism.
        builder.AddListeningPort(server_address_, grpc::InsecureServerCredentials());
        // Register "service" as the instance through which we'll communicate with
        // clients. In this case it corresponds to an *synchronous* service.
        //builder.RegisterService(&presence_recorder);
        builder.RegisterService(&presence_retriever);
        // Finally assemble the server.
        std::unique_ptr<Server> server(builder.BuildAndStart());
        std::cout << "Server listening on " << server_address_ << std::endl;

        return server;
    }

private:
    string server_address_;
};