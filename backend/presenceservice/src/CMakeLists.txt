
cmake_minimum_required(VERSION 3.17)

project(presenceservice C CXX)

get_filename_component(PARENT_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
get_filename_component(PARENT_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
get_filename_component(hw_proto "../../protos/presence.proto" ABSOLUTE)
get_filename_component(hw_proto_path "${hw_proto}" PATH)

set(hw_proto_srcs "${CMAKE_CURRENT_SOURCE_DIR}/gen/presence.pb.cc")
set(hw_proto_hdrs "${CMAKE_CURRENT_SOURCE_DIR}/gen/presence.pb.h")
set(hw_grpc_srcs "${CMAKE_CURRENT_SOURCE_DIR}/gen/presence.grpc.pb.cc")
set(hw_grpc_hdrs "${CMAKE_CURRENT_SOURCE_DIR}/gen/presence.grpc.pb.h")

add_custom_command(
        PRE_BUILD
        OUTPUT "${hw_proto_srcs}" "${hw_proto_hdrs}" "${hw_grpc_srcs}" "${hw_grpc_hdrs}"
        COMMAND ${_PROTOBUF_PROTOC}
        ARGS --grpc_out=generate_mock_code=true:"${CMAKE_CURRENT_SOURCE_DIR}/gen" #"${CMAKE_CURRENT_SOURCE_DIR}/gen"
        --cpp_out "${CMAKE_CURRENT_SOURCE_DIR}/gen"
        -I "${hw_proto_path}"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        "${hw_proto}"
        DEPENDS "${hw_proto}")


include_directories("gen")

add_library(presenceservicelib
        presence_cache.cpp
        utils.cpp
        presence_retriever.cpp
        presence_recorder.cpp
        presence_retriever_service.cpp
        presence_retriever_service.h
        presence_recorder_service.cpp
        presence_recorder_service.h
        service_models.h
        presence_cache.h
        utils.h
        service_runner.cpp
        ${hw_grpc_hdrs}
        ${hw_proto_hdrs}
        ${hw_proto_srcs}
        ${hw_grpc_srcs})

set_target_properties(presenceservicelib PROPERTIES PUBLIC_HEADER
        "service_models.h;presence_cache.h;utils.h;${hw_grpc_hdrs};${hw_proto_hdrs}")

target_link_libraries(presenceservicelib PRIVATE Boost::boost
        ${_REFLECTION}
        ${_GRPC_GRPCPP}
        ${_PROTOBUF_LIBPROTOBUF})

add_executable(presenceservice main.cpp)

target_compile_features(presenceservice PRIVATE cxx_std_17)

target_link_libraries(presenceservice PRIVATE
        presenceservicelib
        fmt::fmt
        ${_REFLECTION}
        ${_GRPC_GRPCPP}
        ${_PROTOBUF_LIBPROTOBUF})
