cmake_minimum_required(VERSION 3.17)
project(presenceservice)

set(CMAKE_CXX_STANDARD 17)

add_executable(presenceservice main.cpp)

target_compile_features(presenceservice PRIVATE cxx_std_17)

target_link_libraries(presenceservice PRIVATE presenceservicelib fmt::fmt  ${_REFLECTION}
        ${_GRPC_GRPCPP}
        ${_PROTOBUF_LIBPROTOBUF})
