
#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>

#include "presence_server.cpp"
#include "presence_retriever.cpp"
#include "presence_cache.cpp"

using namespace std;
using namespace grpc;

class ServiceRunner
{

public:
    ServiceRunner(string serverAddress)
    {
        server_address_ = serverAddress;
    }

    std::unique_ptr<Server> Run()
    {
        auto cache = std::make_shared<PresenceCacheImpl>();
        PresenceRecorderImpl presence_recorder(cache);
        PresenceRetrieverImpl presence_retriever(cache);

        grpc::EnableDefaultHealthCheckService(true);
        grpc::reflection::InitProtoReflectionServerBuilderPlugin();
        
        ServerBuilder builder;
        // Listen on the given address without any authentication mechanism.
        builder.AddListeningPort(server_address_, grpc::InsecureServerCredentials());
        // Register "service" as the instance through which we'll communicate with
        // clients. In this case it corresponds to an *synchronous* service.
        builder.RegisterService(&presence_recorder);
        builder.RegisterService(&presence_retriever);
        // Finally assemble the server.
        std::unique_ptr<Server> server(builder.BuildAndStart());
        std::cout << "Server listening on " << server_address_ << std::endl;

        return server;
    }

private:
    string server_address_;
};