cmake_minimum_required(VERSION 3.17)

project(chatserverlib)

set(CMAKE_CXX_STANDARD 17)

get_filename_component(chatting_proto "${PROTODIR}/chatting.proto" ABSOLUTE)
get_filename_component(chatting_proto_path "${chatting_proto}" PATH)

set(chatting_proto_srcs "${CMAKE_CURRENT_SOURCE_DIR}/gen/chatting.pb.cc")
set(chatting_proto_hdrs "${CMAKE_CURRENT_SOURCE_DIR}/gen/chatting.pb.h")
set(chatting_grpc_srcs "${CMAKE_CURRENT_SOURCE_DIR}/gen/chatting.grpc.pb.cc")
set(chatting_grpc_hdrs "${CMAKE_CURRENT_SOURCE_DIR}/gen/chatting.grpc.pb.h" )

add_custom_command(
        PRE_BUILD
        OUTPUT "${chatting_proto_srcs}" "${chatting_proto_hdrs}" "${chatting_grpc_srcs}" "${chatting_grpc_hdrs}"
        COMMAND ${_PROTOBUF_PROTOC}
        ARGS --grpc_out=generate_mock_code=true:"${CMAKE_CURRENT_SOURCE_DIR}/gen" #"${CMAKE_CURRENT_SOURCE_DIR}/gen"
        --cpp_out "${CMAKE_CURRENT_SOURCE_DIR}/gen"
        -I "${chatting_proto_path}"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        "${chatting_proto}"
        DEPENDS "${chatting_proto}")

include_directories("gen")

add_library(chatserverlib
        ${chatting_grpc_hdrs}
        ${chatting_proto_hdrs}
        ${chatting_proto_srcs}
        ${chatting_grpc_srcs}
        service_runner.cpp
        service_runner.h
        configuration_models.h
        chat_channel_server.cpp
        chat_channel_service.cpp
        chat_channel_service.h)

target_link_libraries(chatserverlib PRIVATE Boost::boost commonlib
        ${_REFLECTION}
        ${_GRPC_GRPCPP}
        ${_PROTOBUF_LIBPROTOBUF})

add_executable(chatserver main.cpp)

target_compile_features(chatserver PRIVATE cxx_std_17)

target_link_libraries(chatserver PRIVATE chatserverlib
        fmt::fmt commonlib
        ${_REFLECTION}
        ${_GRPC_GRPCPP}
        ${_PROTOBUF_LIBPROTOBUF})
