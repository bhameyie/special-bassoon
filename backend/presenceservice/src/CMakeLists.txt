
cmake_minimum_required(VERSION 3.17)

project(presenceservice C CXX)

get_filename_component(presence_proto "${PROTODIR}/presence.proto" ABSOLUTE)
get_filename_component(presence_proto_path "${presence_proto}" PATH)

set(presence_proto_srcs "${CMAKE_CURRENT_SOURCE_DIR}/gen/presence.pb.cc")
set(presence_proto_hdrs "${CMAKE_CURRENT_SOURCE_DIR}/gen/presence.pb.h")
set(presence_grpc_srcs "${CMAKE_CURRENT_SOURCE_DIR}/gen/presence.grpc.pb.cc")
set(presence_grpc_hdrs "${CMAKE_CURRENT_SOURCE_DIR}/gen/presence.grpc.pb.h")

add_custom_command(
        PRE_BUILD
        OUTPUT "${presence_proto_srcs}" "${presence_proto_hdrs}" "${presence_grpc_srcs}" "${presence_grpc_hdrs}"
        COMMAND ${_PROTOBUF_PROTOC}
        ARGS --grpc_out=generate_mock_code=true:"${CMAKE_CURRENT_SOURCE_DIR}/gen" #"${CMAKE_CURRENT_SOURCE_DIR}/gen"
        --cpp_out "${CMAKE_CURRENT_SOURCE_DIR}/gen"
        -I "${presence_proto_path}"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        "${presence_proto}"
        DEPENDS "${presence_proto}")

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
        ${presence_grpc_hdrs}
        ${presence_proto_hdrs}
        ${presence_proto_srcs}
        ${presence_grpc_srcs})

set_target_properties(presenceservicelib PROPERTIES PUBLIC_HEADER
        "service_models.h;presence_cache.h;utils.h;${presence_grpc_hdrs};${presence_proto_hdrs}")

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
